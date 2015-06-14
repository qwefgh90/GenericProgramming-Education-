// 4_functionȰ��

#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

bool foo(int a) { return a % 3; }

int main()
{
	int x[10] = { 3, 6, 9, 5, 3, 6, 9, 3, 6, 9 };

	int * p = find(x, x + 10, 3);	//��� ã��
	
	//find�� ���� generic �ұ�?
	//�־��� �������� ó�������� 3�� ����� �ƴѰ��� ã�� �ʹ�.

	int* p2 = find_if(x, x + 10, foo);	//������ ����
	cout << *p2 << endl;

	//�ζ��� ġȯ�� �ǰ� �Ϸ��� ������ �Լ��� �Լ���ü�� �����ؾ��Ѵ�.

	modulus<int> m; //% ����
	int* p3 = find_if(x, x + 10, bind(m, _1, 3));
	cout << *p2 << endl;
}
//
//int main()
//{
//	modulus<int> m; // % ������ �����ϴ� �Լ���ü
//					// ���� �Լ� : ���ڰ� 2���� �Լ�
//	cout << m(10, 3) << endl ; // 1
//
//
////	int x[10] = { 3, 6, 9, 5, 3, 6, 9, 3, 6, 9 };
//
////	int * p = find(x, x + 10, 3);
//	
//	//find�� ���� generic �ұ�?
//}