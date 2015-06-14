#include <iostream>
#include <vector>
using namespace std;


//vector�� ���ؼ�
int main()
{
	vector<int> v(10, 3); //10���� 3���� �ʱ�ȭ

	cout << v.size() << endl;		//10
	cout << v.capacity() << endl;	//10

	v.resize(7);		// 7���� ���̱�.. �̶� �˰����� �����غ��ô�.

	cout << v.size() << endl;		//7
	cout << v.capacity() << endl;	//10

	v.push_back(1);//���� �Ѱ� �߰�

	cout << v.size() << endl;		//8
	cout << v.capacity() << endl;	//10
	
	v.shrink_to_fit(); 	//�ʿ� ���� ���� ���� �޶�

	cout << v.size() << endl;		//8
	cout << v.capacity() << endl;	//8

	v.push_back(1);//�޸� ���Ҵ�

	cout << v.size() << endl;		// 9
	cout << v.capacity() << endl;	// 12 (1.5��)
}