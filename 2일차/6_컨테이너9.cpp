// 6_�����̳�9
#include <iostream>
#include <map>
#include <string>
using namespace std;


// MAP : pair�� �����ϴ� set

int main()
{
	map<string, string> m;
	
	// map�� data �ֱ� 
	// 1. pair�� ����� �ֱ�
	pair<string, string> p1("mon", "������");
	m.insert(p1);
		
	//2. make_pair
	m.insert(make_pair("tue", "ȭ����"));

	//3. [] �����ڷ� �ֱ�
	m["wed"] = "������";
	
	//�ݺ��� ����ϱ�
	map<string, string>::iterator p = m.begin();
	
	cout << (*p).second << endl;

	
}


//
//template<typename T> T square(T a) { return a*a; };
//
////������ ���� ����? �Ͻ��� �߷��� ����ϱ� ���� ���δ�.
//square(3);			//1. �Ͻ��� �߷�
//square<int>(3);		//2. ����� �߷�
//
//list<> s(10,3);	//10���� 3���� �ʱ�ȭ
//				//Ŭ���� ���ø��� �Ͻ��� �߷��� ���� �����Ƿ�
//				// ����� ���δ�.



// Ŭ���� ���ø��� �Ͻ��� �߷��� �Ұ����ϱ� ������ �׻� ����� ���δ�.
// �Ͻ��� �߷��� ������ �Լ� ���ø��� �����ϸ� ��������.

//template<typename T, typename U>
//pair<T, U> make_pair(T a, T b)
//{
//	return pair<T, U>(a, b);
//}
//
//int main()
//{
//	pair<int, double> p(1, 3.4);
//	foo(p);
//
//	//�� 2�ٰ� ������ �ڵ��Դϴ�.
//	foo(make_pair(1, 3, 4));
//}