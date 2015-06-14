// 5_단위전략 - STL 컨테이너가 많이 사용하는 디자인 철학

#include <iostream>
using namespace std;

template<typename T, typename ThreadModel> 
class List : public ThreadModel
{
public :
	void push_front(const T& a)
	{
		Lock();
		//...
		UnLock();
	}
};
//--------------------
// 멀티 스레드의 정책을 담은 정책클래스를 제공한다.
// 클래스가 사용하는 하나의 동기화 정책만을 가진 클래스
// 정책 클래스(단위전략 클래스)
// => 반드시 지켜야 하는 규칙이 있게 된다. (Lock / UnLock 함수가 있어야 한다.)
// java style : 지켜야하는 규칙을 인터페이스로 만들고, 상속받게 한다.
//				장점 : 규칙을 명확히 알 수 있다.
//				단점 : 가상함수 기반으로 인라인 치환되지 않는다.
// C++ style : 인터페이스로 만들지 말고 암시적인 약속을 한다.
//				장점 : 정책클래스의 모든 함수를 인라인화 할 수 있다.
class NoLock
{
public:
	inline void Lock(){}
	inline void UnLock(){}
};

class MutextLock
{
public:
	inline void Lock(){ cout << "Mutex Lock" << endl; }
	inline void UnLock(){ cout << "Mutext UnLock" << endl; }
};

List<int, NoLock> st; //전역변수, not thread safe
List<int, MutextLock> st2; 

int main()
{
	st.push_front(10);
}