//4_�Ϲ�ȭ�˰���2

#include <iostream>
using namespace std;

//�Ϲ�ȭ ���α׷��� ���� : �ϳ��� �Լ�(Ŭ����)�� �پ��� �뵵�� Ȱ���� �� �ְ� �����ڴ� ��!!

// Step2. �˻� ������ �Ϲ�ȭ : �κ� ���ڿ� �˻��� �����ϰ� ����

// 1. Cǥ���� strchr() �Լ��� ���ؼ�

// Ư¡ : last�� �˻���� ���Ե��� �ʴ´�.(past the end)
//	1������ �������̴�.
char* xstrchr(char* first, char* last, char v)
{
	while (first != last && *first != v)
		first++;

	return first == last ? 0 : first;
}

int main()
{
	char s[] = "abcdefg";

	char* p = xstrchr(s, s+4, 'c');

	if (p == 0)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;

}