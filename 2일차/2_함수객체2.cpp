//2_함수객체2
#include <iostream>
#include <algorithm>
using namespace std;
//1. 일반 함수는 자신만의 타입이 없다.
//	 signature가 동일한 모든 함수는 같은 타입이다.!

//2. 함수객체는 자신만의 타입이 있다. 
//	 signature가 동일해도 모든 함수는 다른 타입이다.

struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};

struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

//정책 변경이 가능하면서도 성능저하가 없는 sort()만들기.!!
// template과 함수객체를 사용하는 기술 - C++ 진영의 고유한 설계기술
//										STL의 설계철학
// 단점 : 정책을 변경한 횟수 만큼 sort()기계어 코드가 생성된다.
//		코드 메모리 사용량이 증가한다.
template<typename T> void Sort(int* x, int n, T cmp)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}
//Less f1; Sort(x, 10, f1);
//Greater f2; Sort(x, 10, f2);