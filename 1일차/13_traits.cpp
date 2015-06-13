//13_traits

#include <iostream>
using namespace std;

// Traits(특질) 템플릿 : T의 다양한 특질(traits, 속성)을 조사하는 템플릿 기술

template<typename T> T Max(T a, T b)
{
	return a < b ? b : a;
}

int main()
{
	int a = 10, b = 20;

	Max(a, b);
	Max(&a, &b);
}