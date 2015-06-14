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

template<typename T> class sp
{
	T* obj;
public:
	sp(T* p = 0) : obj(p) { obj->retain(); }
	sp(const sp& p) : obj(p.obj) { obj->retain(); }
	~sp()						{ obj->release(); }
};

int main()
{
	//안드로이드 프레임워크 소스의 원리
	sp<Car> p1 = new Car();
	sp<Car> p2 = p1;
}