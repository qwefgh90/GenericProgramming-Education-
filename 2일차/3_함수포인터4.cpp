#include <iostream>
using namespace std;

void foo() { cout << "foo" << endl; }
void goo(int a) { cout << "goo" << a << endl; }

class Dialog
{
public:
	void Close() { cout << "Dialog Close" << endl; }
};

// BOOST팀이 만든 범용적 함수 포인터 객체
// 2008년쯤 C++ 표준에 추가되었습니다.
#include <functional>
using namespace std::placeholders;	// _1, _2, _3 등...

void hoo(int a, int b) { cout << "hoo: " << a << "," << b << endl; }

void koo(int a, int b, int c, int d)
{
	printf("koo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	function<void(int, int)> f;
	
	f = bind(&koo, _2, 7, _1, 9);	// bind의 인자가 호출 인자의 순서
									// _2는 f()의 두번째 인자로 받음
	
	f(3, 5);	// koo : 5, 7, 3, 9가 나오게 해보세요.

}

//int main()
//{
//	function<void(int)> f;
//
//	f = bind(&hoo, 3, _1); // 될까요?	//_1은 f()의 첫번째 인자로 받겠다는 의미
//	
//	f(5);	//hoo(3,5)
//
//	return 0;
//}


//
//int main()
//{
//	function<void()> f = &foo;
//	f(); // foo 호출
//	
//	f = bind(&goo, 5);	// 인자를 5로 고정
//	f();
//
//	Dialog dlg;
//	f = bind(&Dialog::Close, &dlg);
//	f();	//Dialog Close() 호출
//}