//2_인라인
//1. 인라인 치환은 컴파일 시간 문법이다.
//2. 인라인 함수라도 함수포이넡에 담아서 사용하면 인라인 치환될 수 없다.
//    => 중요합니다. !!

#include <iostream>
using namespace std;

int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);//호출
	int n2 = Add2(1, 2);//기계어 코드 치환

	int(*f)(int, int) = &Add2;

	//--------------
	int n;
	cin >> n;
	if (n == 0) f = &Add1; // ?


	f(1, 2); // ??

}// cl 1_인라인.cpp /FAs