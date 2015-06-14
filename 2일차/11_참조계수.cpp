#include <vector>
#include <list>
#include <iostream>
using namespace std;


struct Dest{
	~Dest(){
		cout << "Dest 소멸" << endl;
	}
};

class Car
{
public:
	Dest d;
	~Car(){
		cout << "Car 소멸" << endl;
	}
};
list<Car*> st;

void foo()
{
	Car* p = new Car();
	st.push_back(p);

	// p가 필요없다.
	delete p;	//이렇게 해도 될까?

}
int main()
{
	Car c;
}