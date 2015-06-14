// 8_boost
// boost ���̺귯���� ����
// 1. ��� only (���ø��� ��κ��̸� ���� 70~80%�� �����Ѵ�.)
//		A. VC++ ���� ���丮 ������ �ϰ�
//		B. ���ϴ� ��� ������ include �� ��
//		C. boost ��� namespace ���� ����ϸ� �ȴ�.
// 2. .lib�� �ʿ��Ұ͵�

#include <iostream>
#include <boost\any.hpp>
using namespace std;
using namespace boost;

int main()
{
	any a1 = 10;
	any a2 = 3.4;
	any a3 = "aaa";
	
	int n = any_cast<int>(a1);

	cout << n << endl;

	double d = any_cast<double>(a2);

	cout << d << endl;

	//cout << a1 << endl;
	//cout << a2 << endl;

}