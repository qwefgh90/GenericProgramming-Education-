// 10_�ݺ���ī�װ�
#include <iostream>
#include <list>
#include <algorithm> // find()�� ���� �Ϲ�ȭ �Լ��� ������ ���

using namespace std;

int main()
{
	list<int> s;
	s.push_front(10);
	s.push_front(20);

	// s�� sort(����)�� ������.

	sort(s.begin(), s.end());
	
}
