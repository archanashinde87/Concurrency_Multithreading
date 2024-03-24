#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex gLock;
static int shared_value = 0;

void shared_value_increment()
{
    gLock.lock();   // locks the mutex and blocks other threads to access critical section
        shared_value = shared_value + 1;
    gLock.unlock(); // unlocks the mutex so that other waiting threads can capture mutex and access critical section
}

int main()
{
    // launch 10 jthreads
    std::vector<std::thread> threads;
    for(int i = 0; i<1000; i++)
    {
        threads.push_back(std::thread(shared_value_increment));
    }
 
    for(int i = 0; i<1000; i++)
    {
        threads[i].join();
    }
    std::cout << "Shared Value: " << shared_value << std::endl;
    
    return 0;
}

// Result 
//Before using mutex to lock critical section of code shared_value is 999/998/996/1000/....
//After using mutex to lock and unlock critical section of code shared_value 1000 on each execution

