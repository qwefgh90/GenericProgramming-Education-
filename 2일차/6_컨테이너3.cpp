#include <iostream>
#include <vector>
using namespace std;

//배열만큼 빠르게, 하지만 배열보다 편리하게..!!

template<typename T, int N> struct array
{
	T buf[N];

	inline int size() { return N; }

	//반복자 관련 멤버들
	typedef T* iterator;
	
	inline iterator begin() { return buf; }
	inline iterator end() { return buf + N; }

	typedef T value_type;
};
#include <algorithm>
//#include <array>		//BOOST팀이 만들고 2008년 경에 표준 STL에 추가됨
#include <valarray>		//array 보다 훨씬 다양한 연산을 제공합니다.
						//버퍼가 힙에 있습니다. - array보다 무섭습니다.
						//1998년 STL 초창기 부터 제공
int main()
{
	array<int, 10> ar = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	reverse(ar.begin(), ar.end());
	
	cout << ar.size() << endl; /// 배열에는 멤버 함수가 없습니다.

	int x[10];			//1. 크기가 10인 배열
	vector<int> v(10);	//2. 크기가 10인 vector, 배열보다 편하다.
}