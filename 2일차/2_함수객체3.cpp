//2_함수객체3

#include <iostream>
#include <algorithm>
using namespace std;

// STL에는 이미 많은 함수객체가 있습니다.
#include <functional>



inline bool foo(int a, int b) { return a > b; }


int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	
	//sort(x, x + 10); // 오름 차순 정렬
	
	//sort()는 3번째 인자료 비교정책을 보낼 수 있습니다.
	//sort(x, x + 10, foo);// 잘 실행되지만 비교함수의 inline 치환은 불가능
	greater<int> g;
	sort(x, x + 10, g);

	//절대값으로 sort하고 싶다
	// C++11의 람다(Lambda Express) 문법
	// 람다표현식은 결국 컴파일시에 익명의 함수객체("Closure")를
	// 생성해주는 문법입니다.
	sort(x, x + 10, [](int a, int b){ return abs(a) > abs(b); });	//3번째 인자는 컴파일-시간에 함수객체로 변환됨

	for (int i = 0; i < 10; i++)
		cout << x[i] << endl;
	
}