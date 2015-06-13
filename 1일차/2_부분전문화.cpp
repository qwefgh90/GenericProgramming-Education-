//2_부분전문화

#include <iostream>
using namespace std;

//primary template
template<typename T> class Stack
{
public:
	void push() { cout << "T" << endl; }

};

// 부분 전문화 (partial specialization)
template<typename T> class Stack<T*>
{
public:
	void push() { cout << "T*" << endl; }

};

// 전문화 (specialization)
//완벽한 타입이 결정되면 꺽쇄 괄호를 비운다.
//T라는 타입 대신 결정된 타입을 사용하면 된다.
//템플릿 타입 이름이 여러개면 어떻게 하지?
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