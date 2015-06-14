// 6_컨테이너

#include <iostream>
using namespace std;

// STL 컨테이너 총정리 1. 선형 컨테이너 (sequence container) - 3개
// 3개의 컨테이너는 기능은 거의 동일하지만 성능이 다르다.

#include <vector>	// 연속된 메모리
#include <list>		// 떨어진 메모리
#include <deque>	// vector와 list의 중간

int main()
{
	list<int> v;
	//넣기
	v.push_front(10);
	v.push_back(20);
	//제거
	v.pop_front();
	v.pop_back();
	int n = v.front();
}