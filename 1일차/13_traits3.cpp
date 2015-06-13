//13_traits3

#include <iostream>
using namespace std;

// T가 포인터인지 조사하는 템플릿
// 1994년 iterator_traits를 만드는 기술이 등장하고
// 이 기술을 잘 발전 시켜서 2000년 전후에 type traits 라는 기술 등장
// boost에 포함되고 2008년경 부터 TR1 이라는 이름의 STL 확장에 포함
// 공식적으로는 C++11 표준!!

//만드는 법
//private template : false 리턴( value = false 라는 의미)
//부분 전문화 버전 : true 리턴(value = true)

// int a;		//a는 int
// int* p;		//p는 int*
// int x[10];	//x는 int[10]

template<typename T> struct IsArray
{
	enum {size = -1};	//배열이 아니므로
	enum { value = false };
};

template<typename T, int N> struct IsArray<T[N]>
{
	enum { size = N };	//크기도 알 수 있다. 컴파일러에 질문함으로써 크기를 얻어올 수 있다.
	enum { value = true };
};

	template<typename T> void foo(const T& a)
	{
		if (IsArray<T>::value)	//컴파일 시간에 true / false가 결정된다. 따라서 false인 부분의 코드가 사라진다.
			cout << "배열 입니다. 크기는 " << IsArray<T>::size << endl;
		else
			cout << "배열이 아닙니다." << endl;
	};

	int main()
	{
		int x[10];
		foo(x);	//IsPointer를 수정해서 IsArray만들어 보세요


		int* p;
		foo(p);

	}