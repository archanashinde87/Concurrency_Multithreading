// MultithreadingThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

// callable function pointer
void foo(int num)
{
	for (int i{ 0 }; i < num; i++)
	{
		std::cout << "Thread using function pointer as callable.\n";
	}
}

// callable object
class thread_obj
{
public:
	void operator()(int n)
	{
		for (int i{ 0 }; i < n; i++)
		{
			std::cout << "Thread using function object as callable.\n";
		}
	}
};

class Base
{
public:

	void non_static_fun()
	{
		std::cout << "Thread using non static member function as callable\n";
	}
	static void static_fun()
	{
		std::cout << "Thread using static member function as callable\n";
	}
};
int main()
{
	std::cout << "Threads 1 and 2 and 3 operating independently.\n";

	// This thread is launched by using function pointer as callable
	std::thread th1(foo, 3);
	
	// This thread is launched by using function object as callable
	std::thread th2(thread_obj(), 3);

	auto f{ [](int x)
		{
			for (int i{ 0 }; i < x; i++)
				std::cout << "Thread using lambda function as callable.\n";
		} };

	// This thread is launched by using lambda function as callable
	std::thread th3(f, 3);

	Base b;
	std::thread th4(&Base::non_static_fun, &b);
	std::thread th5(&Base::static_fun);

	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();
		
	return 0;
}

