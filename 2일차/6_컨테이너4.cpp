// 6_컨테이너4.cpp

#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

// 이미 리스트가 있다 그런데, stack이 필요하다.

// Adapter 패턴 : 기존 클래스의 인터페이스(함수이름)을 변경해서 
//					다른 클래스 처럼 보이게 하는 디자인 패턴
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
	//stack에서 메모리할당 방식을 변경하려면??
	//stack<int, list<int, MyAlloc<int>> > gg;

	stack<int, vector<int>> s;
	stack<int, list<int>> s2;
	int a = 100;
	s.push(10);
	s.push(a);
	
	cout << s.top() << endl; // 20 리턴만하고 제거되지는 않는다.
	
	a = 50;

	cout << s.top() << endl; 
}