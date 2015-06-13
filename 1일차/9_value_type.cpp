// 9_value_type
#include <iostream>
#include <list>
#include <vector>
using namespace std;
/*
void print(vector<int>& v)
{
	int n = v.front();
	cout << n << endl;
}
*/
/*
template<typename T> void print(vector<T>& v)
{
	T n = v.front();
	cout << n << endl;
}
*/

template<typename T> void print(T& v)
{
	//T n = v.front(); // ??? 

	// T::value_type : T가 보관하는 타입을 꺼내달라..
	//					즉, double

	typename T::value_type n = v.front();

	cout << n << endl;
}

int main()
{
	list<double> v(10, 3);
	
	print(v);

}

// template 기반 컨테이너는 자신이 보관하는 타입이 있다.
// 그런데, 외부에서 그 타입을 알고 싶을때가 있다.(위의 print)
// 그래서 아래 처럼 만들어야 한다.
/*
template<typename T> class list
{
public:
	typedef T value_type;	//핵심!!!
	//.....

};

list<int>::value_type n;	//n은 결국 __ int __ 타입 입니다.


*/
