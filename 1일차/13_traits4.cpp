// 13_traits4
#include <iostream>
using namespace std;

//traits2������ IsPointer 2�� �����ؿ�����.
//traits1������ Max, main()�� �����ؿ�����.

template<typename T> struct IsPointer
{
	enum { value = false };
};

template<typename T> struct IsPointer<T*>
{
	enum { value = true };
};

template<typename T> T Max(T a, T b)
{
	if (IsPointer<T>::value)	//false ���� �Ʒ��ڵ带 ������ 
		return *a < *b ? b : //int �� �������� �ȵǹǷ� ����
	
	return a < b ? b : a;
}

int main()
{
	int a = 10, b = 20;
	
	Max(a, b);	
	//Max(&a, &b);
}