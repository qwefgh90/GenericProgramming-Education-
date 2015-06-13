//5_일반화알고리즘4

#include <iostream>
using namespace std;

//일반화 프로그래밍 개념 : 하나의 함수(클래스)를 다양한 용도로 활용할 수 있게 만들자는 것!!

// Step4. 

// 아래 처럼 template을 만들면 2개의 문제가 있습니다.
// 1. 구간의 타입과 찾는 요소의 타입이 연관됩니다.
//    double 배열에서 int를 찾을 수 없습니다.

// 2. T* 라고 적으면 진짜 포인터만 사용할 수 
//	  있습니다. 스마트포인터를 사용할 수 없습니다.
//template <typename T> T* xfind(T* first, T* last, T v)
template<typename T1, typename T2> 
T1 xfind(T1 first, T1 last, T2 v)
{
	while (first != last && *first != v)
		first++;

	return first == last ? 0 : first;
}

int main()
{
	double d[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	double* p = xfind(d, d + 10, 10);

	if (p == 0)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;

}