
#include <iostream>
#include <string>
#include <boost\signals2\signal.hpp>
using namespace std;
using namespace boost;
//using namespace boost::signals2;

//boost::signal : ���� ���� - ��Ƽ�����忡 �������� �ʴ�.
//boost::signals2::signal : �ֽ� ����.. ��Ƽ�����忡 �����ϴ�.

void foo() { cout << "foo" << endl; }
void goo() { cout << "goo" << endl; }
void hoo(int a) { cout << "hoo" << a << endl; }

int main()
{
	signals2::signal<void()> f;

	f.connect(&foo);
	f.connect(&goo);
	//f.connect(&hoo);	//error
	f.connect(std::bind(&hoo, 111111111111111));	// ok..
	f.connect(boost::bind(&hoo, 1111111));	// ok..
	
	f();	// foo(), goo()
}

