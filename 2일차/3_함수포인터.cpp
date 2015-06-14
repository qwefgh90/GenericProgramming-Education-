//3_함수포인터
// 1. 멤버함수의 호출원리 : 1번째 함수인자로 객체의 주소가 전달되는 것
// 
class Point
{
	int x, y;
public:
	void Set(int a, int b)	//void Set(Point* const this, int a, int b)
	{
		x = a;				//this->x = a;
		y = b;
	}
};

int main()
{
	Point p1, p2;
	p1.Set(10, 20);	// Set(&p1, 10, 20) 으로 컴파일 됩니다.
}