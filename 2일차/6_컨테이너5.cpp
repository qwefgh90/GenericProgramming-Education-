#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

// STL���� 3���� �����̳� ���ʰ� �ֽ��ϴ�.
#include <stack>
#include <queue> // queue, priority_queue

int main()
{
	stack<int, vector<int>> s1;
	stack<int, list<int>> s2;
	stack<int, deque<int>> s3;

	// ������ ������ ��� ������.
	queue<int, vector<int>> q1;	// error. vector�� �������� �ְų�
								/// ���� ����.!
	queue<int, list<int>> q2;
	queue<int, deque<int>> q3;

	q1.push(10); // �ڷ� �ְ� �ִ�. ���� �ƴ�..
	q1.pop();	//������ �E �� �����Ƿ� ����
}