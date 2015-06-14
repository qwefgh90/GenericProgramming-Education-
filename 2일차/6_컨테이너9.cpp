// 6_컨테이너9
#include <iostream>
#include <map>
#include <string>
using namespace std;


// MAP : pair을 저장하는 set

int main()
{
	map<string, string> m;
	
	// map에 data 넣기 
	// 1. pair를 만들어 넣기
	pair<string, string> p1("mon", "월요일");
	m.insert(p1);
		
	//2. make_pair
	m.insert(make_pair("tue", "화요일"));

	//3. [] 연산자로 넣기
	m["wed"] = "수요일";
	
	//반복자 사용하기
	map<string, string>::iterator p = m.begin();
	
	cout << (*p).second << endl;

	
}


//
//template<typename T> T square(T a) { return a*a; };
//
////다음중 쉬운 것은? 암시적 추론이 사용하기 쉬워 보인다.
//square(3);			//1. 암시적 추론
//square<int>(3);		//2. 명시적 추론
//
//list<> s(10,3);	//10개를 3으로 초기화
//				//클래스 템플릿은 암시적 추론이 되지 않으므로
//				// 어려워 보인다.



// 클래스 템플릿은 암시적 추론이 불가능하기 때문에 항상 어려워 보인다.
// 암시적 추론이 가능한 함수 템플릿을 제공하면 쉬워진다.

//template<typename T, typename U>
//pair<T, U> make_pair(T a, T b)
//{
//	return pair<T, U>(a, b);
//}
//
//int main()
//{
//	pair<int, double> p(1, 3.4);
//	foo(p);
//
//	//위 2줄과 동일한 코드입니다.
//	foo(make_pair(1, 3, 4));
//}