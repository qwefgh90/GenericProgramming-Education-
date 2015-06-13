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

	// T::value_type : T�� �����ϴ� Ÿ���� �����޶�..
	//					��, double

	typename T::value_type n = v.front();

	cout << n << endl;
}

int main()
{
	list<double> v(10, 3);
	
	print(v);

}

// template ��� �����̳ʴ� �ڽ��� �����ϴ� Ÿ���� �ִ�.
// �׷���, �ܺο��� �� Ÿ���� �˰� �������� �ִ�.(���� print)
// �׷��� �Ʒ� ó�� ������ �Ѵ�.
/*
template<typename T> class list
{
public:
	typedef T value_type;	//�ٽ�!!!
	//.....

};

list<int>::value_type n;	//n�� �ᱹ __ int __ Ÿ�� �Դϴ�.


*/
