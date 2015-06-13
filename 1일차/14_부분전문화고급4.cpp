#include <iostream>
using namespace std;

/*
template<typename T>
T Mul(T a, T b)
{
	return a*b;
}
*/

// ������ Ÿ�� ���ǹ�
template<bool, typename T, typename  U> struct IfThenElse
{
	typedef T ResultType;
};


//1��° ���ڰ� false�϶��� ���� �κ� ����ȭ
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




