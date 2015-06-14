// 2_함수객체
#include <iostream>
using namespace std;

//1. 함수 객체 : 함수 처럼 사용할 수 있는 객체
struct Plus
{
	int operator()(int a, int b) { return a + b; }
};

int main()
{
	Plus p;
	int n = p(1, 2); // p.operator()(1,2)
	cout << n << endl;
	
	//a+b; // a.operator+(b)
	//a-b; // a.operator-(b)
	//a(); // a.operator()()
	//a(1,2); // a.operator()(1,2)
}