// 8_boost3

#include <iostream>
#include <string>
#include <boost\foreach.hpp>
using namespace std;
using namespace boost;

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	/*BOOST_FOREACH(int n, x)		//예전 C++ 문법을 사용해서
	{								//매크로 기술로 만든것
		cout << n << endl;
	}*/


	//C++11은 공식적으로 foreach 개념을 문법화 했습니다.
	//ranged for 라고 합니다.
	for (int n : x)
	{
		cout << n << endl;
	}
}