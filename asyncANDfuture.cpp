#include <iostream>
#include <future>

int square(int x)
{
    return x*x;
}

int main()
{
    std::future<int> asynFunction = std::async(&square, 12);
    for(int i = 0; i<10; i++)
    {
        std::cout << square(i) << std::endl;
    }
    
    int result = asynFunction.get();
    std::cout << "Async result is : " << result << std::endl;
    
    return 0;
    
}
