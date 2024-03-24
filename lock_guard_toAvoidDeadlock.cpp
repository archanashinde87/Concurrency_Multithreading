#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex gLock;
static int shared_value = 0;

// To avoid deadlock situations like forgot to unlock mutex, early return after locking mutex 
// or throwing an exception after locking mutex use std::lock_guard and it follows RAII so it will release mutex
// while going out of scope means it will call unlock on mutex in any condition as it is scoped.

void shared_value_increment()
{
    std::lock_guard<std::mutex> lockGuard(gLock); // std::lock_guard<std::mutex> is wrapper on mutex 
    try
    {
        shared_value = shared_value + 1;
        throw "dangerous abort";
    }
    catch(...)
    {
        std::cout << "handle exception";
        return;
    }

}

int main()
{
    // launch 10 jthreads
    std::vector<std::thread> threads;
    for(int i = 0; i<100; i++)
    {
        threads.push_back(std::thread(shared_value_increment));
    }
 
    for(int i = 0; i<100; i++)
    {
        threads[i].join();
    }
    std::cout << "Shared Value: " << shared_value << std::endl;
    
    return 0;
}

// Result 
/*[?2004l
handle exceptionhandle exceptionhandle exceptionhandle exceptionhandle exceptionhandle exceptionhandle exceptionhandle exceptionhandle exceptionhandle exceptionShared Value: 100
[?2004h*/
