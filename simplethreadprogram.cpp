/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>

void test(int param)
{
    std::cout << "Hello from thread using function pointer!" << std::endl;
    std::cout << "Argument passed in for function pointer " << param << std::endl;
}

int  main()
{
    std::thread myThread(&test, 100);

    auto lambda = [](int param){
            std::cout << "Hello from thread using lambda function" << std::endl;
            std::cout << "Argument passed in for lambda function " << param << std::endl;
        };
        
    std::thread myLambdaThread(lambda,500);
    
    myThread.join();
    myLambdaThread.join();
    
    std::cout << "Hello from my main thread!" << std::endl;
    return 0;
}