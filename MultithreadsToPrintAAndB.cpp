/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>

void function1()
{
    for(int i{0}; i<200; i++)
        std::cout << "A";
}
void function2()
{
    for(int i{0}; i<200; i++)
        std::cout << "B";
}
int main() {
    std::thread t1(function1);
    std::thread t2(function2);
    
    t1.join();
    t2.join();
    
    std::cout << "\nProgram Completed\n";

    return 0;
}

// Output
/*
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABABBBBBBBBBBBBBBBBBBBBBABAAAAAAABBBBBABAAAAAAAAABABAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
Program Completed*/
[?2004h