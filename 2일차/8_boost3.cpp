// 8_boost3

#include <iostream>
#include <string>
#include <boost\foreach.hpp>
using namespace std;
using namespace boost;

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	/*BOOST_FOREACH(int n, x)		//���� C++ ������ ����ؼ�
	{								//��ũ�� ����� �����
		cout << n << endl;
	}*/


	//C++11�� ���������� foreach ������ ����ȭ �߽��ϴ�.
	//ranged for ��� �մϴ�.
	for (int n : x)
	{
		cout << n << endl;
	}
}