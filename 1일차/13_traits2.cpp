//13_traits2

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


template<typename T> struct IsPointer
{
	enum { value = false };
};

template<typename T> struct IsPointer<T*>
{
	enum { value = true };
};
template<typename T> void foo(const T& a)
{
	if (IsPointer<T>::value)	//������ �ð��� true / false�� �����ȴ�. ���� false�� �κ��� �ڵ尡 �������.
		cout << "������ �Դϴ�." << endl;
	else 
		cout << "�����Ͱ� �ƴմϴ�." << endl;
}

int main()
{
	int x = 0;
	foo(&x);

}