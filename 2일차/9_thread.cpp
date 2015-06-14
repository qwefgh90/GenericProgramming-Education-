
#include <iostream>
#include <string>
//#include <boost\thread.hpp>
#include <Windows.h>
#include <thread>
using namespace std;
//using namespace boost;

void foo(int a, int b, int c)
{
	cout << a << b << c << endl;
	Sleep(1000);
	cout << "end foo" << endl;
}

struct Test
{
public:
	void operator()() { cout << "Test" << endl; }

	void foo(int a, int b, int c)
	{
		cout << a << b << c << endl;
		Sleep(1000);
		cout << "end foo" << endl;
	}
};

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	// 스레드 함수에 인자를 보내는 방법
	/*thread t(bind(&foo, a, b, c));
	thread t2(foo, a,b,c);

	Test tst;
	thread t3(tst);
	t3.detach();*/


	Test tst2;
	thread t(bind(&Test::foo, &tst2));

	t.join();
	//t2.join();
}