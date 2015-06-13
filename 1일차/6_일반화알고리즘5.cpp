//6_일반화알고리즘5

#include <iostream>
using namespace std;

//일반화 프로그래밍 개념 : 하나의 함수(클래스)를 다양한 용도로 활용할 수 있게 만들자는 것!!

// Step5. 검색 실패의 경우

// xfind 함수 : 선형 컨테이너에서 선형검색을 수행하는 알고리즘

// 검색 대상 : 모든타입의 배열의 임의 구간에서 선형 검색
// 검색 구간의 표현 : 포인터 또는 스마트 포인터(++,*,!=,== 연산이 되어야 함)

// 실패의 전달 : last 리턴

// [first, last) 사이 검색

// 데이터의 크기보다 하나 큰 공간을 가지고 있다. (표준 문서에 나와 있다) 

// 스마트 포인터라고 반드시 소멸하는 것은 아니다.

template<typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 v)
{
	while (first != last && *first != v)
		first++;
	
	return first; // == last ? 0 : first;
}


int main()
{
	double d[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	double* p = xfind(d, d + 10, 10);

	if (p == d + 10)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;

}