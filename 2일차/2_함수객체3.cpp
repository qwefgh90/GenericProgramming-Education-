//2_�Լ���ü3

#include <iostream>
#include <algorithm>
using namespace std;

// STL���� �̹� ���� �Լ���ü�� �ֽ��ϴ�.
#include <functional>



inline bool foo(int a, int b) { return a > b; }


int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	
	//sort(x, x + 10); // ���� ���� ����
	
	//sort()�� 3��° ���ڷ� ����å�� ���� �� �ֽ��ϴ�.
	//sort(x, x + 10, foo);// �� ��������� ���Լ��� inline ġȯ�� �Ұ���
	greater<int> g;
	sort(x, x + 10, g);

	//���밪���� sort�ϰ� �ʹ�
	// C++11�� ����(Lambda Express) ����
	// ����ǥ������ �ᱹ �����Ͻÿ� �͸��� �Լ���ü("Closure")��
	// �������ִ� �����Դϴ�.
	sort(x, x + 10, [](int a, int b){ return abs(a) > abs(b); });	//3��° ���ڴ� ������-�ð��� �Լ���ü�� ��ȯ��

	for (int i = 0; i < 10; i++)
		cout << x[i] << endl;
	
}