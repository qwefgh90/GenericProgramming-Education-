//4_일반화알고리즘

#include <iostream>
using namespace std;

// 1. C표준의 strchr() 함수에 대해서

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
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;
	
}