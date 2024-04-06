/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> acnt;
int cnt;
void fun()
{
    for(int i =0; i<10000; i++)
    {
        ++acnt;
        ++cnt;
    }
}

int main()
{
    {
        std::vector<std::jthread> pool;
        for(int i=0; i<10; i++)
        {
            pool.emplace_back(fun);
        }
    }
    
    std::cout << "Atomic count is : " << acnt <<std::endl;
    std::cout << "Normal Count is : " << cnt << std::endl;
    
    return 0;
}
