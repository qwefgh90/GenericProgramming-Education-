#include <iostream>
using namespace std;

// tuple은 2008년 경에 C++ 표준 STL에 추가되었습니다.
// 그 전에는 boost라이브러리에 있었습니다.

#include <tuple>

int main()
{
	tuple<int, char, short> t3(1, 2, 3);

	//꺼내는 방법.
	int n = get<0>(t3);	//t3의 0번째를 꺼내 달라	//상수만 가능하다. // 런타임에 임의의 요소를 가져올 수 없다.
	cout << n << endl;

	//vector<int> v(3);	

	// vector, 배열, list : 동일 타입을 여러개 보관, homogeneous 컨테이너
	// tuple : 서로 다른 타입을 여러개 보관 non homogeneous 컨테이너


	
}