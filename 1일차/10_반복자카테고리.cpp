// 10_반복자카테고리
#include <iostream>
#include <list>
#include <algorithm> // find()와 같은 일반화 함수를 선언한 헤더

using namespace std;

int main()
{
	list<int> s;
	s.push_front(10);
	s.push_front(20);

	// s를 sort(정렬)해 보세요.

	sort(s.begin(), s.end());
	
}
