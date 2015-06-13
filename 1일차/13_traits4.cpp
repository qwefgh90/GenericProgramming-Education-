// 13_traits4
#include <iostream>
using namespace std;

//traits2번에서 IsPointer 2개 복사해오세요.
//traits1번에서 Max, main()을 복사해오세요.

template<typename T> struct IsPointer
{
	enum { value = false };
};

template<typename T> struct IsPointer<T*>
{
	enum { value = true };
};

template<typename T> T Max(T a, T b)
{
	if (IsPointer<T>::value)	//false 더라도 아래코드를 생섬함 
		return *a < *b ? b : //int 는 역참조가 안되므로 에러
	
	return a < b ? b : a;
}

int main()
{
	int a = 10, b = 20;
	
	Max(a, b);	
	//Max(&a, &b);
}