//2_�ζ���
//1. �ζ��� ġȯ�� ������ �ð� �����̴�.
//2. �ζ��� �Լ��� �Լ����̆��� ��Ƽ� ����ϸ� �ζ��� ġȯ�� �� ����.
//    => �߿��մϴ�. !!

#include <iostream>
using namespace std;

int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);//ȣ��
	int n2 = Add2(1, 2);//���� �ڵ� ġȯ

	int(*f)(int, int) = &Add2;

	//--------------
	int n;
	cin >> n;
	if (n == 0) f = &Add1; // ?


	f(1, 2); // ??

}// cl 1_�ζ���.cpp /FAs