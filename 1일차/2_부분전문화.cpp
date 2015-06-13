//2_�κ�����ȭ

#include <iostream>
using namespace std;

//primary template
template<typename T> class Stack
{
public:
	void push() { cout << "T" << endl; }

};

// �κ� ����ȭ (partial specialization)
template<typename T> class Stack<T*>
{
public:
	void push() { cout << "T*" << endl; }

};

// ����ȭ (specialization)
//�Ϻ��� Ÿ���� �����Ǹ� ���� ��ȣ�� ����.
//T��� Ÿ�� ��� ������ Ÿ���� ����ϸ� �ȴ�.
//���ø� Ÿ�� �̸��� �������� ��� ����?
template<> class Stack< char* >	
{
public:
	void push() { cout << "char*" << endl; }
};
	
int main()
{
	Stack<int>	s1; s1.push();
	Stack<int*>	s2; s2.push();
	Stack<char*>	s3; s3.push();

}