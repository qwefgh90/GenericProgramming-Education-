//5_�Ϲ�ȭ�˰���3

#include <iostream>
using namespace std;

//�Ϲ�ȭ ���α׷��� ���� : �ϳ��� �Լ�(Ŭ����)�� �پ��� �뵵�� Ȱ���� �� �ְ� �����ڴ� ��!!

// Step3. �˻� ��� Ÿ���� �Ϲ�ȭ - ���ø� ����
//									�Լ��̸� ����
template <typename T>
T* xfind(T* first, T* last, T v)
{
	while (first != last && *first != v)
		first++;

	return first == last ? 0 : first;
}

int main()
{
	double d[] = {1,2,3,4,5,6,7,8,9,10,11};
	
	double* p = xfind(d, d + 10, 11.0);

	if (p == 0)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;

}