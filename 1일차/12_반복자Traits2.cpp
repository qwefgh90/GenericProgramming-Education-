// 12_반복자Traits2
#include <iostream>
#include <vector>
#include <iterator>	// iterator_traits 등이 들어 있습니다.
using namespace std;


// first ~ last까지의 합을 구하라
/*
int sum(int * first, int* last)
{
	int s = 0;

	while (first != last)
	{
		s += *first;
		++first;
	}
	return s;
}*/

//모든 컨텡너에서 합을 구할 수 있게 "일반화"
template<typename T>
typename iterator_traits<T>::value_type sum(T first, T last)
{
	// T는 반복자(list_iterator등)
	// T::value_type : 반복자가 가르키는 타입
	// typename T::value_type s = 0;
	
	typename iterator_traits<T>::value_type s = 0;
	
	// C++11은 위처럼 복잡하게 하지 않고 *first의 타입을 컴파일러에게
	// 요청해도 됩니다. vc++2013부터 지원됩니다.
	// decltype(*first) s = 0;

	while (first != last)
	{
		s += *first;
		++first;
	}
	return s;
}

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	int s1 = sum(x, x + 10);
	cout << s1 << endl;

	vector<int> v(x, x + 10);
	int s2 = sum(v.begin(), v.end());

	cout << s2 << endl;
}