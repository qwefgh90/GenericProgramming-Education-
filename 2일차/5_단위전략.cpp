// 5_�������� - STL �����̳ʰ� ���� ����ϴ� ������ ö��

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
// ��Ƽ �������� ��å�� ���� ��åŬ������ �����Ѵ�.
// Ŭ������ ����ϴ� �ϳ��� ����ȭ ��å���� ���� Ŭ����
// ��å Ŭ����(�������� Ŭ����)
// => �ݵ�� ���Ѿ� �ϴ� ��Ģ�� �ְ� �ȴ�. (Lock / UnLock �Լ��� �־�� �Ѵ�.)
// java style : ���Ѿ��ϴ� ��Ģ�� �������̽��� �����, ��ӹް� �Ѵ�.
//				���� : ��Ģ�� ��Ȯ�� �� �� �ִ�.
//				���� : �����Լ� ������� �ζ��� ġȯ���� �ʴ´�.
// C++ style : �������̽��� ������ ���� �Ͻ����� ����� �Ѵ�.
//				���� : ��åŬ������ ��� �Լ��� �ζ���ȭ �� �� �ִ�.
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

List<int, NoLock> st; //��������, not thread safe
List<int, MutextLock> st2; 

int main()
{
	st.push_front(10);
}