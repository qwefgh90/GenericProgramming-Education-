//4_�Ϲ�ȭ�˰���

#include <iostream>
using namespace std;

// 1. Cǥ���� strchr() �Լ��� ���ؼ�

char* xstrchr(char* s, char v)
{
	while (*s != 0 && *s != v)
		s++;

	return *s == 0 ? 0 : s;
}

int main()
{
	char s[] = "abcdefg";

	char* p = xstrchr(s, 'c');
	
	if (p == 0)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;
	
}