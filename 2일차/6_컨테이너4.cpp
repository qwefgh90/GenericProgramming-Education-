// 6_�����̳�4.cpp

#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

// �̹� ����Ʈ�� �ִ� �׷���, stack�� �ʿ��ϴ�.

// Adapter ���� : ���� Ŭ������ �������̽�(�Լ��̸�)�� �����ؼ� 
//					�ٸ� Ŭ���� ó�� ���̰� �ϴ� ������ ����
//
//template<typename T, typename C = deque<T>> class stack
//{
//	C<T> st;
//public:
//	inline void push(const T& a)	 { st.push_back(a); }
//	inline void pop()				{ st.pop_back(); }
//	inline T& top()				{ return st.back(); }
//};

#include <stack>

int main()
{
	//stack���� �޸��Ҵ� ����� �����Ϸ���??
	//stack<int, list<int, MyAlloc<int>> > gg;

	stack<int, vector<int>> s;
	stack<int, list<int>> s2;
	int a = 100;
	s.push(10);
	s.push(a);
	
	cout << s.top() << endl; // 20 ���ϸ��ϰ� ���ŵ����� �ʴ´�.
	
	a = 50;

	cout << s.top() << endl; 
}