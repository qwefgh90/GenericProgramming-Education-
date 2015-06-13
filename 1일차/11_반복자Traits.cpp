// 11_반복자Traits
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


template<typename T>
inline void xadvance_imp(T& p, int n, input_iterator_tag)	//변수명을 없애면
//컴파일러는 오버로딩을 위해 사용하는 변수로 추측한다.
{
	cout << "임의 접근이 아닐때" << endl;
	while (n--) ++p;
}

template<typename T>
inline void xadvance_imp(T& p, int n, random_access_iterator_tag)
{
	//반복자의 종류에 따라 다른 함수를 사용하게 한다.
	//typename T::iterator_category a;

	cout << "임의 접근일때" << endl;
	p = p + n;
}

//반복자 정의 : 반복자 처럼 동작하는 모든 것은 반복자이다.
//				++로 이동하고 *로 값을 꺼낼 수 있는 모든 것
// 반복자의 2가지 형태
// 1. 진짜 포인터
// 2. 스마트포인터처럼 객체로 만드는 반복자

// 2가지 형태 때문에 generic 알고리즘 개발이 어렵다.
// 해결책
/*
template<typename T> struct iterator_traits
{
	typedef typename T::iterator_category iterator_category;
};

// T가 객체형 반복자가 아닌 포인터 일때
template<typename T> struct iterator_traits<T*>
{
	typedef random_access_iterator_tag iterator_category;
};
*/

template<typename T> void xadvance(T& p, int n)
{
	//xadvance_imp(p, n, typename T::iterator_category());

	xadvance_imp(p, n, typename iterator_traits<T>::iterator_category());
}

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* p2 = x;

	xadvance(p2, 4);
	
	cout << *p2 << endl;

	vector<int> v(x, x + 10);

	vector<int>::iterator p = v.begin();

	//p = p + 6;	// ?

	//advance(p, 6);	//전진형 반복자든 임의 반복자든 사용 가능
	xadvance(p, 6);		//전진형 반복자든 임의 반복자든 사용 가능
}

