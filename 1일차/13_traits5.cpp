//13_traits5
#include <iostream>
using namespace std;


//아래 템플릿이 Generic 프로그램 세계에서 아주 유명한 도구 입니다.
template<int N> struct int2type
{
	enum { value = N };
};
/*
int main()
{
	foo(0);	
	foo(1);	//0,1은 같은 타입이다 (int)
			//foo(0), foo(1)은 같은 함수 호출!

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1);	//t0와 t1은 다른 타입
				//foo(t0), foo(t1)는 다른함수 호출
}
*/

template<typename T> struct IsPointer
{
	enum { value = false };
};

template<typename T> struct IsPointer<T*>
{
	enum { value = true };
};

//템플릿 컴파일 과정
// 해당 타입의 함수를 먼저 만들고(instantiation) 컴파일 한다.

//함수 오버로딩 : 컴파일 시간에 어떤 함수를 호출할지 결정합니다.
template<typename T> T MaxImp(T a, T b, int2type<1> )
{
	cout << "포인터인 경우" << endl;
	return *a < *b ? b : a;
};

template<typename T> T MaxImp(T a, T b, int2type<0>)
{
	cout << "포인터가 아닌 경우 경우" << endl;
	return a < b ? b : a;
};

	template<typename T> T Max(T a, T b)
	{
		/*if (IsPointer<T>::value)
			return *a < *b ? b : a;

		return a < b ? b : a;*/
		
		// T가 포인터 인지에 따라 다른 함수 템플릿을 사용하도록 함수 오버로딩
		// 기술을 사용한다. - 아주 중요한 기술
		
		return MaxImp(a, b, int2type<IsPointer<T>::value>() );

	};

	int main()
	{
		int a = 10, b = 20;

		Max(a, b);
		Max(&a, &b);
	}

	//www.google.com 에서 C++ Idioms 라고 검색해 보세요.
	//1번째 링크에 가보세요..