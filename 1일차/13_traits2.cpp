//13_traits2

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


template<typename T> struct IsPointer
{
	enum { value = false };
};

template<typename T> struct IsPointer<T*>
{
	enum { value = true };
};
template<typename T> void foo(const T& a)
{
	if (IsPointer<T>::value)	//컴파일 시간에 true / false가 결정된다. 따라서 false인 부분의 코드가 사라진다.
		cout << "포인터 입니다." << endl;
	else 
		cout << "포인터가 아닙니다." << endl;
}

int main()
{
	int x = 0;
	foo(&x);

}