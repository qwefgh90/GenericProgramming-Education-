#include <vector>
#include <list>
#include <iostream>
using namespace std;


struct Dest{
	~Dest(){
		cout << "Dest �Ҹ�" << endl;
	}
};

class Car
{
public:
	Dest d;
	~Car(){
		cout << "Car �Ҹ�" << endl;
	}
};
list<Car*> st;

void foo()
{
	Car* p = new Car();
	st.push_back(p);

	// p�� �ʿ����.
	delete p;	//�̷��� �ص� �ɱ�?

}
int main()
{
	Car c;
}