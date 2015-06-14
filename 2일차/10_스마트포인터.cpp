//10_����Ʈ������

#include <memory> // shared_ptr<>, week_ptr<>
					//���� boost�� ���� �� Ŭ����

#include <iostream>
using namespace std;

// 1. shared_ptr�� ��ü�� ������� ������� �����Ѵ�.
// 2. 
struct Node
{
	int data;

	//shared_ptr<Node> next; //��������� �����ϴ� ����Ʈ ������
	weak_ptr<Node> next; //shared_ptr<>�� ȣȯ �Ǹ鼭
						// ��������� �������� �ʴ� ����Ʈ ������
	
	~Node() { cout << "Node �ı�" << endl; }
};

int main()
{
	shared_ptr<Node> p1(new Node);
	shared_ptr<Node> p2(new Node);

	//�Ʒ� �ڵ忡 �����ؾ� �մϴ�. �޸� ���� �Դϴ�.
	p1->next = p2;
	p2->next = p1;

}