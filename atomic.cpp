#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

static std::atomic<int> shared_value = 0;

// If one thread writes to an atomic object while another thread reads from it, 
// the behavior is well-defined, we don't need to put lock for std::atomic type.
void shared_value_increment()
{
    shared_value += 1;
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
// Shared Value: 100

