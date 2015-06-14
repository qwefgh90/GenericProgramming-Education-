#include <vector>
#include <list>
#include <iostream>
using namespace std;


struct Dest{
	~Dest(){
		cout << "Dest" << endl;
	}
};

class RefBase
{
public:
	Dest d;
	int mCount;

	virtual ~RefBase() {}
	
	RefBase() : mCount(0){}

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

class Truck : public RefBase // 아이폰 NSObject
{
public:
	~Truck() { cout << "Truck 파괴" << endl; }
};

int main()
{
	sp<Truck> p = new Truck; // 될까요?
}