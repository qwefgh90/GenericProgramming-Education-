
#include <iostream>
#include <string>
//#include <boost\thread.hpp>
#include <Windows.h>
#include <thread>
#include <mutex>
using namespace std;
//using namespace boost;

int x = 0;
mutex m;
void foo()
{
	m.lock();
	x = 100;
	m.unlock();
}

int main()
{
	thread t(foo);

	t.join();

}