#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

// STL에는 3개의 컨테이너 어댑너가 있습니다.
#include <stack>
#include <queue> // queue, priority_queue

int main()
{
	stack<int, vector<int>> s1;
	stack<int, list<int>> s2;
	stack<int, deque<int>> s3;

	// 다음중 에러를 모두 고르세요.
	queue<int, vector<int>> q1;	// error. vector는 앞쪽으로 넣거나
								/// 뺄수 없다.!
	queue<int, list<int>> q2;
	queue<int, deque<int>> q3;

	q1.push(10); // 뒤로 넣고 있다. 에러 아님..
	q1.pop();	//앞으로 뺼 수 없으므로 에러
}