// 3_스마트포인터
#include <iostream>
using namespace std;


class Car
{
public:
	void Go() { cout << "Car Go" << endl; }
};
// 아래 클래스가 핵심입니다.
// 개념 : 임의의 객체가 다른 타입의 포인터 처럼 사용되는것
// 구현원리 : 
//			*, -> 연산자를 재정의해서 포인터 처럼 보이게 한다.
//			1) 지역변수(객체)안에 포인터 멤버변수를 할당
//			2) -> ,* 를 연산자 오버로드하여 멤버변수를 사용한다.
// 장점 : 진짜 포인터가 아니라 객체이다.
//			생성/소멸/복사/대입의 모든 과정을 제어할 수 있다.
//			대표적 활용이 소멸자에서의 자동 delete 기능!

class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}
	~Ptr(){ if (obj != 0) delete obj; };
	Car* operator->(){ return obj; }
	Car& operator*(){ return *obj; }	//주의 참조리턴필요
};

int main()
{
	Ptr p = new Car; // ? // Ptr p(new Car) // int a = 0 과 int a(0)과 같다.
	
	p->Go();			// 잘생각해보세요
					// (p.operator->() )Go()의 모양이지만
					// (p.operator->() )->Go()으로 해석해줍니다.
	
	(*p).Go();	//진짜 포인터 처럼 보이려면 이 코드도 되어야 한다.
	


}