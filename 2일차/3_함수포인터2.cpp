//3_함수포인터2
#include <iostream>

class Dialog
{
public:
	void Close(){}
};

void foo() {}

int main()
{
	void(*f1)() = &foo; // ok!!
	//void(*f2)() = &Dialog::Close; // error, 멤버 함수는 this가 추가된다.

	void(Dialog::*f2)() = &Dialog::Close;

	//f2(); // 객체(this)가 없다. error

	Dialog dlg;
	//dlg.f2();	//함수포인터를 호출하기 위해 *을 넣는다.
	//dlg.*f2();	//연산자 우선순위를 위해 괄호를 넣는다.
	(dlg.*f2)(); // 결국 dlg.Close();

}