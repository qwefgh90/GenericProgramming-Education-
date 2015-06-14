
#include <iostream>
#include <string>
#include <boost\signals2\signal.hpp>
using namespace std;
using namespace boost;
//using namespace boost::signals2;

//boost::signal : 예전 버전 - 멀티스레드에 안전하지 않다.
//boost::signals2::signal : 최신 버전.. 멀티스레드에 안전하다.

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

