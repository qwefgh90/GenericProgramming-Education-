// 7_반복자의 종류
// STL 뿐만 아니라 대부분의 언어(Java, C#, Objective-C등)에 반복자가 있다.

//				STL			다른 언어(Java, C#, C++ 타이젠)
//	find 함수	find(T p)	find(인터페이스 p)
//	이동함수	++p;		p.next(), p.MoveNext()
//	값 꺼내기	*p;			p.		p.GetObject()

//	일반 배열 사용가능..		사용불가(C++ 타이젠.)
//								C#등은 배열도 객체이므로 사용가능
//	Generic 다형성(다른 함수의 ++을 부른다)	 객체 지향의 다형성(가상함수 기반)


#include <iostream>
using namespace std;

// 싱글리스트를 생각해 봅시다.

template<typename T> struct Node
{
	T data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n)
	{}
};

//slist 안에 있는 Node를 가르키는 스마트포인터 비슷한 객체를 만들자
//slist의 요소를 열거하기 위한 객체 => "반복자(iterator)"라고 한다.


//Iterator (Iterator 패턴)란 GoF's 디자인 패턴에 있는 패턴이다. 
//복합 격체(Containter)의 내부구조에 상관없이 동일한 방법으로 요소를 열거하기 위한 객체!!
template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p){}

	//xfind에 전달하려면 ++, *, ==, != 연산이 가능해야 합니다.
	inline slist_iterator& operator++()
	{
		//구현
		current = current->next;
		return *this;	//	??여기서 이터레이터 반환
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
	//Node 생성자를 잘 활용해서 slist의 앞에 넣는 코드
	void push_front(const T& a) { head = new Node<T>(a, head); }

	//모든 컨테이너 설계자는 자신의 반복자 이름을 약속된 이름(iterator)
	//으로 외부에 노출하기로 한다.
	typedef slist_iterator<T> iterator;

	//모든 컨테이너 설계자는 반드시 자신의 시작과 마지막 다음을 가르키는 반복자를
	//리턴하는 함수를 제공해야 한다. "규칙!!"

	iterator<T> begin() { return iterator<T>(head); }
	iterator<T> end() { return iterator<T>(0); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(0);
	s.push_front(30);	//이때의 메모리 모양을 생각해보세요.

	slist<int>::iterator p = s.begin();

	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
}




