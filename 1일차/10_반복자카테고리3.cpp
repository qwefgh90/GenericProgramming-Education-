// 10_반복자카테고리3
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
// STL은 반복자의 5가지 카테고리를 타입화 합니다. (이미 STL에 정의되어 있음)
struct input_iterator_tag {};	//empty class(struct)
								//아무 멤버도 없지만 타입은 타입이다.
								//함수 오버로딩이나, 템플릿인자로 활용된다.

struct output_iterator_tag {};	
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};
*/

//그리고 반복자를 만들때 자신의 종류를 외부에 알려주기로 했습니다.
template<typename T> class list_iterator
{
public:
	typedef bidirectional_iterator_tag iterator_category;

};

template<typename T> class vector_iterator
{
public:
	typedef random_access_iterator_tag iterator_category;

};

// 함수 오버로딩을 사용해서 임의 접근 일때와 아닐때로 구별합니다.
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

// STL에 있는 advance() 알고리즘을 만들어 봅시다.
template<typename T> void xadvance(T p, int n)
{
	xadvance_imp(p, n, typename T::iterator_category());	//T::iterator_category() 임시 객체, 오버로딩만 결정

	//모든 반복자는 ++은 가능하다.
	
}

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	
	vector<int> v(x, x + 10);

	vector<int>::iterator p = v.begin();
	
	//p = p + 6;	// ?
	
	//advance(p, 6);	//전진형 반복자든 임의반복자든 사용 가능
	xadvance(p, 6);
	
	
}