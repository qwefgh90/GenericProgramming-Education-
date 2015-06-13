//4_일반화알고리즘2

#include <iostream>
using namespace std;

//일반화 프로그래밍 개념 : 하나의 함수(클래스)를 다양한 용도로 활용할 수 있게 만들자는 것!!

// Step2. 검색 구간의 일반화 : 부분 문자열 검색이 가능하게 하자

// 1. C표준의 strchr() 함수에 대해서

// 특징 : last는 검색대상에 포함되지 않는다.(past the end)
//	1번보다 범용적이다.
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
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;

}