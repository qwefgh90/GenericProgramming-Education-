//3_함수포인터3
#include <iostream>
using namespace std;

//객체 이벤트 처리기술
class Button
{
	void(*handler)();
	
	//void(Dialog::*handler)();	//액션
	//Dialog* object;	//타겟

public:
	void setHandler(void(*f)()) { handler = f; }
	void Click()
	{
		//이벤트 발생한 사실을 외부에 알려야 한다.
		//java, 안드로이드 앱, C++ 타이젠 : 인터페이스 기반 리스너
		//C++ MFC, QT, 아이폰 : 함수 포인터 기반 callback 개념..
		handler();

		//(object->*handler)();
	}
};
void foo() { cout << "foo" << endl; }
void goo() { cout << "goo" << endl; }
int main()
{
	Button b1, b2;
	b1.setHandler(foo);
	b2.setHandler(goo);//함수등록
	b1.Click();
	
	////참고 : java style
	//Window w = new Widnow();
	//b1.addListener(&w);	//객체 등록
	//b2.addListener(&w);	//객체 등록
	//b1.Click();
}