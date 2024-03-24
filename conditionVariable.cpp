#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex gLock;
std::condition_variable gConditionVariable;

int main()
{
    int result{0};
    bool notified{false};
    
    // reporter thread
    std::thread reporter([&]{
        std::unique_lock<std::mutex> lock(gLock);
        if(!notified)
        {
            gConditionVariable.wait(lock);
        }
        
        std::cout << "Reporter result is: " << result << std::endl;
    });

    // worker thread
    std::thread worker([&]{
        std::unique_lock<std::mutex> lock(gLock);
        result = 42 + 1+ 7;
        notified = true;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Worker's work is complete" << std::endl;
        gConditionVariable.notify_one();
    });
    
    worker.join();
    reporter.join();
    
    std::cout << "Program is complete\n";
    
    return 0;
    
}
