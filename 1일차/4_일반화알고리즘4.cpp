//5_�Ϲ�ȭ�˰���4

#include <iostream>
using namespace std;

//�Ϲ�ȭ ���α׷��� ���� : �ϳ��� �Լ�(Ŭ����)�� �پ��� �뵵�� Ȱ���� �� �ְ� �����ڴ� ��!!

// Step4. 

// �Ʒ� ó�� template�� ����� 2���� ������ �ֽ��ϴ�.
// 1. ������ Ÿ�԰� ã�� ����� Ÿ���� �����˴ϴ�.
//    double �迭���� int�� ã�� �� �����ϴ�.

// 2. T* ��� ������ ��¥ �����͸� ����� �� 
//	  �ֽ��ϴ�. ����Ʈ�����͸� ����� �� �����ϴ�.
//template <typename T> T* xfind(T* first, T* last, T v)
template<typename T1, typename T2> 
T1 xfind(T1 first, T1 last, T2 v)
{
	while (first != last && *first != v)
		first++;

	return first == last ? 0 : first;
}

int main()
{
	double d[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	double* p = xfind(d, d + 10, 10);

	if (p == 0)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;

}