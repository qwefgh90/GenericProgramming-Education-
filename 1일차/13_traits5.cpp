//13_traits5
#include <iostream>
using namespace std;


//�Ʒ� ���ø��� Generic ���α׷� ���迡�� ���� ������ ���� �Դϴ�.
template<int N> struct int2type
{
	enum { value = N };
};
/*
int main()
{
	foo(0);	
	foo(1);	//0,1�� ���� Ÿ���̴� (int)
			//foo(0), foo(1)�� ���� �Լ� ȣ��!

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1);	//t0�� t1�� �ٸ� Ÿ��
				//foo(t0), foo(t1)�� �ٸ��Լ� ȣ��
}
*/

template<typename T> struct IsPointer
{
	enum { value = false };
};

template<typename T> struct IsPointer<T*>
{
	enum { value = true };
};

//���ø� ������ ����
// �ش� Ÿ���� �Լ��� ���� �����(instantiation) ������ �Ѵ�.

//�Լ� �����ε� : ������ �ð��� � �Լ��� ȣ������ �����մϴ�.
template<typename T> T MaxImp(T a, T b, int2type<1> )
{
	cout << "�������� ���" << endl;
	return *a < *b ? b : a;
};

template<typename T> T MaxImp(T a, T b, int2type<0>)
{
	cout << "�����Ͱ� �ƴ� ��� ���" << endl;
	return a < b ? b : a;
};

	template<typename T> T Max(T a, T b)
	{
		/*if (IsPointer<T>::value)
			return *a < *b ? b : a;

		return a < b ? b : a;*/
		
		// T�� ������ ������ ���� �ٸ� �Լ� ���ø��� ����ϵ��� �Լ� �����ε�
		// ����� ����Ѵ�. - ���� �߿��� ���
		
		return MaxImp(a, b, int2type<IsPointer<T>::value>() );

	};

	int main()
	{
		int a = 10, b = 20;

		Max(a, b);
		Max(&a, &b);
	}

	//www.google.com ���� C++ Idioms ��� �˻��� ������.
	//1��° ��ũ�� ��������..