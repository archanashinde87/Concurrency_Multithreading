#include <iostream>
#include <thread>
#include <mutex>

static int s_amount{0}; // as s_amount is static var and there are more than 1 thread this is race condition for multiple threads
std::mutex m_mutex; // mutual exclusion(lock) on threads so that only one thread can access and modify critical condition.

void addMoney()
{
    m_mutex.lock();
    ++s_amount;      // critical section
    m_mutex.unlock();
}
int main() 
{
  std::thread t1(addMoney);
  std::thread t2(addMoney);

  t1.join();
  t2.join();

  std::cout << s_amount << std::endl;
  
  return 0;
}

// Result - as independentThread detached main doesn't wait to finish it...if detached thread 
// doesn't finish till main finishes it will get suspended.
//Starting thread caller.
//Starting concurrent thread.
//Exiting thread caller.
