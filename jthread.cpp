#include <iostream>
#include <thread>
#include <vector>

// launching multiple jthreads program and joining them automatically while destructing - RAII principle.

int main()
{
    auto lambda = [](int param){
        std::cout << "Hi from peer thread " << std::this_thread::get_id() << std::endl;
        std::cout << "Argument is " << param << std::endl;
    };
    
    // launch 10 jthreads
    std::vector<std::jthread> jthreads;
    for(int i = 0; i<10; i++)
    {
        jthreads.push_back(std::jthread(lambda,100));
    }
    
    // We do not have to join explicitly as when jthread goes out of scope destructor of jthread will
    // call join automatically...std::jthread follows RAII principle.
    
    std::cout << "hello from my main thread\n";
    
    return 0;
}

// Result:
/*
Hi from peer thread 139654059304512
Argument is 100
Hi from peer thread 139654034126400
Argument is 100
Hi from peer thread 139653940241984
Argument is 100
Hi from peer thread 139654050911808
Argument is 100
hello from my main thread
Hi from peer thread 139654025733696
Argument is 100
Hi from peer thread Hi from peer thread 139654042519104
Argument is 100
Hi from peer thread 139653923456576
Argument is 100
139653948634688
Argument is 100
Hi from peer thread 139653915063872
Argument is 100
Hi from peer thread 139653931849280
Argument is 100
*/

