// 8_boost
// boost 라이브러리의 종류
// 1. 헤더 only (템플릿이 대부분이며 거의 70~80%를 차지한다.)
//		A. VC++ 에서 디렉토리 설정을 하고
//		B. 원하는 헤더 파일을 include 한 후
//		C. boost 라는 namespace 열고 사용하면 된다.
// 2. .lib가 필요할것들

#include <iostream>
#include <boost\any.hpp>
using namespace std;
using namespace boost;

int main()
{
	any a1 = 10;
	any a2 = 3.4;
	any a3 = "aaa";
	
	int n = any_cast<int>(a1);

	cout << n << endl;

	double d = any_cast<double>(a2);

	cout << d << endl;

	//cout << a1 << endl;
	//cout << a2 << endl;

}