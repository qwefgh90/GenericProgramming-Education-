
#include <iostream>
#include <string>
//#include <boost\thread.hpp>
#include <Windows.h>
#include <thread>
using namespace std;
//using namespace boost;

void foo()
{
	cout << "foo" << endl;
	Sleep(1000);
	cout << "end foo" << endl;
}

int main()
{
	thread t(foo); // 이 순간 스레드 생성됩니다.
	t.join();	//스레드가 종료될때를 대기합니다.

}