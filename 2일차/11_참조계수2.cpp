#include <vector>
#include <list>
#include <iostream>
using namespace std;


struct Dest{
	~Dest(){
		cout << "Dest" << endl;
	}
};

class Car
{
public:
	Dest d;
	int mCount;
	
	Car() : mCount(0){}

	void retain() { ++mCount; }
	void release() { if (--mCount == 0) delete this; }
};

int main()
{
	Car* p1 = new Car;
	p1->retain();	//규칙 1. 객체 생성시 참조계수 증가

	Car* p2 = p1;
	p2->retain();	//규칙 2. 객체 포인터 복사시 참조계수 증가
	
	p1->release();
	p2->release();	//규칙 3. 객체 사용 후 참조계수 감소
}