// 6_�����̳�8
#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;

// ���� �����̳� : ������ ������ ����
// set : RB Ʈ�� ���
int main()
{
	//set<int, greater<int>> s; // Red Black Tree
	
	typedef set<int, greater<int>> SET;

	SET s;
	
	//�յڷ� ���� �� ����.. insert�θ� �־�� �մϴ�.
	s.insert(10);
	s.insert(20);
	s.insert(15);
	s.insert(25);
	
	// pair<> : ���� ��� Duo�� �����ϰ� ���� ����ü
	// first, second ��Ұ� �ִ�.
	pair<SET::iterator, bool> result = s.insert(25);

	//�Ʒ� �ڵ带 ���� ������ - �������� ���۰���?
	// �����ڵ� : set�� ���� �˻��� �����ѵ�, find()�� �����˻��˰����̴�.
	SET::iterator p2 = find(s.begin(), s.end(), 20); // ??

	SET::iterator p3 = s.find(20);	// ���� �˻� �Լ�!
	cout << *p3 << endl;			

	SET::iterator p = s.begin();
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
	
	if (result.second == false)
		cout << "����" << endl;
}