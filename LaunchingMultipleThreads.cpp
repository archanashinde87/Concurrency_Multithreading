#include <iostream>
#include <thread>
#include <vector>

// launching multiple threads program and joining them carefully

int main()
{
    auto lambda = [](int param){
        std::cout << "Hi from peer thread " << std::this_thread::get_id() << std::endl;
        std::cout << "Argument is " << param << std::endl;
    };
    
    // launch 10 threads
    std::vector<std::thread> threads;
    for(int i = 0; i<10; i++)
    {
        threads.push_back(std::thread(lambda,100));
    }
    
    // join threads carefully
    for(int i = 0; i<10; i++)
    {
        threads[i].join();
    }
    
    std::cout << "hello from my main thread\n";
    
    return 0;
}

// Result:
/*
Hi from peer thread 140346004923968
Hi from peer thread Argument is 100
Hi from peer thread 140345899738688
Argument is 100
Hi from peer thread 140345891345984
Argument is 100
140345996531264
Argument is 100
Hi from peer thread 140345988138560
Argument is 100
Hi from peer thread 140345874560576
Argument is 100
Hi from peer thread 140345908131392
Argument is 100
Hi from peer thread 140345866167872
Argument is 100
Hi from peer thread 140345857775168
Argument is 100
Hi from peer thread 140345882953280
Argument is 100
hello from my main thread
*/

