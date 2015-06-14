#include <iostream>
#include <vector>
using namespace std;

//�迭��ŭ ������, ������ �迭���� ���ϰ�..!!

template<typename T, int N> struct array
{
	T buf[N];

	inline int size() { return N; }

	//�ݺ��� ���� �����
	typedef T* iterator;
	
	inline iterator begin() { return buf; }
	inline iterator end() { return buf + N; }

	typedef T value_type;
};
#include <algorithm>
//#include <array>		//BOOST���� ����� 2008�� �濡 ǥ�� STL�� �߰���
#include <valarray>		//array ���� �ξ� �پ��� ������ �����մϴ�.
						//���۰� ���� �ֽ��ϴ�. - array���� �������ϴ�.
						//1998�� STL ��â�� ���� ����
int main()
{
	array<int, 10> ar = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	reverse(ar.begin(), ar.end());
	
	cout << ar.size() << endl; /// �迭���� ��� �Լ��� �����ϴ�.

	int x[10];			//1. ũ�Ⱑ 10�� �迭
	vector<int> v(10);	//2. ũ�Ⱑ 10�� vector, �迭���� ���ϴ�.
}