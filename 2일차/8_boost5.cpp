
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
	thread t(foo); // �� ���� ������ �����˴ϴ�.
	t.join();	//�����尡 ����ɶ��� ����մϴ�.

}