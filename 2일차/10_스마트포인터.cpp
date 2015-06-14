//10_스마트포인터

#include <memory> // shared_ptr<>, week_ptr<>
					//역시 boost로 부터 온 클래스

#include <iostream>
using namespace std;

// 1. shared_ptr은 객체를 참조계수 기반으로 관리한다.
// 2. 
struct Node
{
	int data;

	//shared_ptr<Node> next; //참조계수가 증가하는 스마트 포인터
	weak_ptr<Node> next; //shared_ptr<>과 호환 되면서
						// 참조계수를 증가하지 않는 스마트 포인터
	
	~Node() { cout << "Node 파괴" << endl; }
};

int main()
{
	shared_ptr<Node> p1(new Node);
	shared_ptr<Node> p2(new Node);

	//아래 코드에 주의해야 합니다. 메모리 누수 입니다.
	p1->next = p2;
	p2->next = p1;

}