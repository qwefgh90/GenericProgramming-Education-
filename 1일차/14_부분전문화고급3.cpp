#include <iostream>
using namespace std;

// tuple�� 2008�� �濡 C++ ǥ�� STL�� �߰��Ǿ����ϴ�.
// �� ������ boost���̺귯���� �־����ϴ�.

#include <tuple>

int main()
{
	tuple<int, char, short> t3(1, 2, 3);

	//������ ���.
	int n = get<0>(t3);	//t3�� 0��°�� ���� �޶�	//����� �����ϴ�. // ��Ÿ�ӿ� ������ ��Ҹ� ������ �� ����.
	cout << n << endl;

	//vector<int> v(3);	

	// vector, �迭, list : ���� Ÿ���� ������ ����, homogeneous �����̳�
	// tuple : ���� �ٸ� Ÿ���� ������ ���� non homogeneous �����̳�


	
}