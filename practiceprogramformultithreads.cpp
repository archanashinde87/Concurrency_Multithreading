/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>
#include <chrono>

using ull  = unsigned long long;

ull oddSum{0};
ull evenSum{0};

int calcOddSum(ull start, ull end)
{
    for(ull i{start}; i<=end; i++)
    {
        if(i%2!=0)
            oddSum+=i;
    }
    return oddSum;
}

int calcEvenSum(ull start, ull end)
{
    for(ull i{start}; i<=end; i++)
    {
        if(i%2==0)
            evenSum+=i;
    }
    return evenSum;
}


int  main()
{
  
  ull start = 0;
  ull end = 1900000000;
  
  std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
  
  /*calcOddSum(start,end);
  calcEvenSum(start,end);*/
  
  std::thread th1(calcOddSum, start, end);
  std::thread th2(calcEvenSum, start, end);
  th1.join();
  th2.join();
  
  std::chrono::high_resolution_clock::time_point stopTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime-startTime);
  std::cout << "Time taken in Sec before using threads: " << duration.count() << std::endl;
  
  std::cout << "Odd Sum: " << oddSum << std::endl;
  std::cout << "Even Sum: " << evenSum << std::endl;

  
  return 0;
  
}

// Results:
// Time taken in Sec before using threads: 8
// Time taken in Sec after using threads: 5