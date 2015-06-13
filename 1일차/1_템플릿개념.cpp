// 1_템플릿개념.cpp
//#include <iostream>
//using namespace std;


/*

//1.int형 버전
int square(int a) { return a*a; }
//2.double형 버전
double square(double a) { return a*a; }
*/

//유사한 코드가 반복되면 코드 생성기를 사용하자!!
//1. C언어 - 매크로를 사용한 코드 생성
//단점 : 매크로에 의한 코드생성은 전처리기가 한다.
//			전처리기는 타입을 알지 못한다.
//			그래서 어떤 터입이 필요한지 사용자가 선언해야한다.
//			MAKE_SQUARE(int)라고 선언해야됨
/*
#define MAKE_SQUARE(T)	T square ( T a ) { return a*a; }

MAKE_SQUARE(int)
MAKE_SQUARE(double)
*/

//2. C++ - 컴파일러에 의한 코드 생성 기술 - template!!
//장점 : 컴파일러는 타입을 알고 있다.
//			소스를 분석해서 어떤 타입이 필요한지 정확히
//			알아내서 해당 함수를 생성해 준다.!!
//			MAKE_SQUARE(int)등은 필요 없다.
//단점 : 컴파일러가 코드를 생성할때 필요한 코드 이상으로 너무 많은 타입의 
//			함수/클래스를 생성해서 코드 메모리 사용량이 증가
//			할 수 있다. - "Code Bloat" 라고 불리는 현상
//			임베디드 개발시 유의!!d

template <typename T>	T square ( T a ) { return a*a; }

// 인스턴스화(instantiation) : 템플릿의 T의 타입이 결정되어 진짜 함수를 만드는 과정
//
// 암시적 인스턴스화 : T의 타입을 컴파일러가 추론하는 것
// 명시적 인스턴스화 : T의 타입을 사용자가 결정하는 것

int main()
{
	square(3);
	square(3.3);
	
	short s = 3;
	square(s);	//1. square(short) 버전을 생성할것이다. (명시적 인스턴스화)

	//cl.exe ( 컴파일러 )
	//C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013용 개발자 명령 프롬프트
	//1) cl 1_템플릿개념 /FAs	-> 어셈생성
	//2) notepad 1_템플릿개념.asm
	//3) 
	

	//int형 버전의 함수를 사용하고 싶을때 (Code Bloat 해결 및 개발자의 의도대로 코딩하는 것)
	square<int>(s);	//2.  sqaure(int) 버전을 사용하게 해줄 것이다. (명시적 인스턴스화)
	
	

	
}