#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

// STL에는 3개의 컨테이너 어댑너가 있습니다.
#include <stack>
#include <queue> // queue, priority_queue

#include <functional>

struct Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	inline bool operator<(const Point p)
		const
	{
		return y < p.y;
	}
	inline bool operator==(const Point& p)
		const
	{
		return y == p.y && x == p.x;
	}
};

using namespace std::rel_ops;

//namespace std
//{
//	namespace rel_ops
//	{
//		template<typename T> bool operator>(const T& a, const T& b)
//		{
//			return !(a == b) && !(a < b);
//		}
//		// >=, !=, <= 도 여기 있습니다.
//	}
//}

int main()
{
	Point p1(1,1);
	Point p2(1,2);
	Point p3(1,3);

	bool b = (p1 > p2);

	cout << b << endl;

	/*
	priority_queue<Point, vector<Point>, greator<Point>> qp;
	qp.push(p1);
	qp.push(p2);
	qp.push(p3);
	*/
}

/*
int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	
	pq.push(10);
	pq.push(20);
	pq.push(16);
	
	cout << pq.top() << endl; // 우선순위가 제일 높은 요소가 나온다.
	
}*/