// 6_컨테이너8
#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;

// 연관 컨테이너 : 순서를 가지고 저장
// set : RB 트리 기반
int main()
{
	//set<int, greater<int>> s; // Red Black Tree
	
	typedef set<int, greater<int>> SET;

	SET s;
	
	//앞뒤로 넣을 수 없고.. insert로만 넣어야 합니다.
	s.insert(10);
	s.insert(20);
	s.insert(15);
	s.insert(25);
	
	// pair<> : 어제 배운 Duo와 동일하게 생긴 구조체
	// first, second 요소가 있다.
	pair<SET::iterator, bool> result = s.insert(25);

	//아래 코드를 평가해 보세요 - 좋은가요 나쁜가요?
	// 나쁜코드 : set은 이진 검색이 가능한데, find()는 선형검색알고리즘이다.
	SET::iterator p2 = find(s.begin(), s.end(), 20); // ??

	SET::iterator p3 = s.find(20);	// 이진 검색 함수!
	cout << *p3 << endl;			

	SET::iterator p = s.begin();
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
	
	if (result.second == false)
		cout << "실패" << endl;
}