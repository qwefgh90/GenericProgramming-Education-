// 6_�ݺ���

#include <iostream>
using namespace std;

// �̱۸���Ʈ�� ������ ���ô�.

template<typename T> struct Node
{
	T data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n)
	{}
};

//slist �ȿ� �ִ� Node�� ����Ű�� ����Ʈ������ ����� ��ü�� ������
//slist�� ��Ҹ� �����ϱ� ���� ��ü => "�ݺ���(iterator)"��� �Ѵ�.


//Iterator (Iterator ����)�� GoF's ������ ���Ͽ� �ִ� �����̴�. 
//���� ��ü(Containter)�� ���α����� ������� ������ ������� ��Ҹ� �����ϱ� ���� ��ü!!
template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p){}

	//xfind�� �����Ϸ��� ++, *, ==, != ������ �����ؾ� �մϴ�.
	inline slist_iterator& operator++()
	{
		//����
		current = current->next;
		return *this;	//	??���⼭ ���ͷ����� ��ȯ
	}
	
	inline T& operator*() { return current->data; }
	
	inline bool operator==(const slist_iterator& p){ return current == p.current ? true : false; }
	inline bool operator!=(const slist_iterator& p){ return current != p.current ? true : false; }
};

template<typename T> class slist
{
	Node<T>* head;
public:
	slist() : head(0){}
	//Node �����ڸ� �� Ȱ���ؼ� slist�� �տ� �ִ� �ڵ�
	void push_front(const T& a) { head = new Node<T>(a, head); }

	//��� �����̳� �����ڴ� �ڽ��� �ݺ��� �̸��� ��ӵ� �̸�(iterator)
	//���� �ܺο� �����ϱ�� �Ѵ�.
	typedef slist_iterator<T> iterator;
	
	//��� �����̳� �����ڴ� �ݵ�� �ڽ��� ���۰� ������ ������ ����Ű�� �ݺ��ڸ�
	//�����ϴ� �Լ��� �����ؾ� �Ѵ�. "��Ģ!!"

	iterator<T> begin() { return iterator<T>(head); }
	iterator<T> end() { return iterator<T>(0); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(0);
	s.push_front(30);	//�̶��� �޸� ����� �����غ�����.
	
	slist<int>::iterator p = s.begin();

	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
}




