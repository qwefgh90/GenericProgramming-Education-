// 6_�����̳�

#include <iostream>
using namespace std;

// STL �����̳� ������ 1. ���� �����̳� (sequence container) - 3��
// 3���� �����̳ʴ� ����� ���� ���������� ������ �ٸ���.

#include <vector>	// ���ӵ� �޸�
#include <list>		// ������ �޸�
#include <deque>	// vector�� list�� �߰�

int main()
{
	list<int> v;
	//�ֱ�
	v.push_front(10);
	v.push_back(20);
	//����
	v.pop_front();
	v.pop_back();
	int n = v.front();
}