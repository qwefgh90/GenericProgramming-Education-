//11_반복자카테고리2

#include <list>
#include <vector>
#include <algorithm>
using namespace std;

//반복자 카테고리(category)

// 1. 입력 반복자		:	변수 = *p, ++ (컨테이너에서 읽어옴)
// 2. 출력 반복자		:	*p = 값, ++ (컨테이너로 내보냄)

// 3. 전진형 반복자		:	입출력, ++		싱글리스트
// 4. 양방향 반복자		:	입출력, ++, --	더블리스트

// 5. 임의접근 반복자	:	입출력, ++, --, +, -, []	 연속된 메모리(배열)


int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p = find(x, x + 10, 5);	// 1,2인자는 반복자입니다.
									// 최소 요구 조건은 무엇인가요 ?
									// 최소 조건은 입력 반복자

	reverse(x, x + 10);		//최소 조건 => 양방향

	sort(x, x + 10);		//퀵소트 입니다. 최소조건 => 임의접근 반복자

	//slist<int> s1;
	//reverse(s1, begin(), s1.end());	// ?? // --가 없으므로 에러

	list<int> s2;//양방향 리스트
	//sort(s2, begin(), s2.end()); // error // 임의접근 필요

	s2.sort();	//멤버 함수 sort().. 퀵소트가 아닌 다른 알고리즘

	vector<int> v;

	//v.sort();	// 이 멤버 함수가 있을까요? //임의접근 반복자 이므로 굳이 멤버함수로 없음// algorithm 사용 가능
	
	//find()	//_Init 입력 반복자
	
	//reverse()	// _BidIt 양방향 반복자

	//sort(	// _RanIt 랜덤 반복자
}


/*
int main()
{
	//우리가 만든 slist를 생각해 봅시다.
	slist<int> s;
	s.push_front(10);

	slist<int>::iterator p = s.begin();
	++p;	//ok!!
	--p;		//될까요?

}
*/