//13_traits3

#include <iostream>
using namespace std;

// T�� ���������� �����ϴ� ���ø�
// 1994�� iterator_traits�� ����� ����� �����ϰ�
// �� ����� �� ���� ���Ѽ� 2000�� ���Ŀ� type traits ��� ��� ����
// boost�� ���Եǰ� 2008��� ���� TR1 �̶�� �̸��� STL Ȯ�忡 ����
// ���������δ� C++11 ǥ��!!

//����� ��
//private template : false ����( value = false ��� �ǹ�)
//�κ� ����ȭ ���� : true ����(value = true)

// int a;		//a�� int
// int* p;		//p�� int*
// int x[10];	//x�� int[10]

template<typename T> struct IsArray
{
	enum {size = -1};	//�迭�� �ƴϹǷ�
	enum { value = false };
};

template<typename T, int N> struct IsArray<T[N]>
{
	enum { size = N };	//ũ�⵵ �� �� �ִ�. �����Ϸ��� ���������ν� ũ�⸦ ���� �� �ִ�.
	enum { value = true };
};

	template<typename T> void foo(const T& a)
	{
		if (IsArray<T>::value)	//������ �ð��� true / false�� �����ȴ�. ���� false�� �κ��� �ڵ尡 �������.
			cout << "�迭 �Դϴ�. ũ��� " << IsArray<T>::size << endl;
		else
			cout << "�迭�� �ƴմϴ�." << endl;
	};

	int main()
	{
		int x[10];
		foo(x);	//IsPointer�� �����ؼ� IsArray����� ������


		int* p;
		foo(p);

	}