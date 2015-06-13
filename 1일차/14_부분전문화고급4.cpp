#include <iostream>
using namespace std;

/*
template<typename T>
T Mul(T a, T b)
{
	return a*b;
}
*/

// 컴파일 타입 조건문
template<bool, typename T, typename  U> struct IfThenElse
{
	typedef T ResultType;
};


//1번째 인자가 false일때를 위한 부분 전문화
template<typename T, typename  U> struct IfThenElse <false, T, U>
{
	typedef U ResultType;
};

//---------------------------------------
template<typename T, typename U>
typename IfThenElse< (sizeof(T) > sizeof(U)), T, U>::ResultType 
Mul(T a, U b)
{
	return a*b;
}

int main()
{
	cout << Mul(3, 4.2) << endl;
}




