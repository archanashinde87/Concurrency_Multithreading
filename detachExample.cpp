#include <chrono>
#include <iostream>
#include <thread>
 
void independentThread() 
{
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Exiting concurrent thread.\n";
}
 
void threadCaller() 
{
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Exiting thread caller.\n";
}
 
int main() 
{
    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

// Result - as independentThread detached main doesn't wait to finish it...if detached thread 
// doesn't finish till main finishes it will get suspended.
//Starting thread caller.
//Starting concurrent thread.
//Exiting thread caller.
