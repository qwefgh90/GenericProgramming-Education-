// 4_function활용

#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

bool foo(int a) { return a % 3; }

int main()
{
	int x[10] = { 3, 6, 9, 5, 3, 6, 9, 3, 6, 9 };

	int * p = find(x, x + 10, 3);	//상수 찾기
	
	//find는 정말 generic 할까?
	//주어진 구간에서 처음나오는 3의 배수가 아닌것을 찾고 싶다.

	int* p2 = find_if(x, x + 10, foo);	//조건자 버전
	cout << *p2 << endl;

	//인라인 치환이 되게 하려면 조건자 함수를 함수객체로 전달해야한다.

	modulus<int> m; //% 연산
	int* p3 = find_if(x, x + 10, bind(m, _1, 3));
	cout << *p2 << endl;
}
//
//int main()
//{
//	modulus<int> m; // % 연산을 수행하는 함수객체
//					// 이항 함수 : 인자가 2개인 함수
//	cout << m(10, 3) << endl ; // 1
//
//
////	int x[10] = { 3, 6, 9, 5, 3, 6, 9, 3, 6, 9 };
//
////	int * p = find(x, x + 10, 3);
//	
//	//find는 정말 generic 할까?
//}