//13_traits

#include <iostream>
using namespace std;

// Traits(Ư��) ���ø� : T�� �پ��� Ư��(traits, �Ӽ�)�� �����ϴ� ���ø� ���

template<typename T> T Max(T a, T b)
{
	return a < b ? b : a;
}

int main()
{
	int a = 10, b = 20;

	Max(a, b);
	Max(&a, &b);
}