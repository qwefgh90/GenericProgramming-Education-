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
	p1->retain();	//��Ģ 1. ��ü ������ ������� ����

	Car* p2 = p1;
	p2->retain();	//��Ģ 2. ��ü ������ ����� ������� ����
	
	p1->release();
	p2->release();	//��Ģ 3. ��ü ��� �� ������� ����
}