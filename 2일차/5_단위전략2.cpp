//5_단위전략2
#include <iostream>
using namespace std;

//메모리 할당/해제의 전략을 담은 정책 클래스
template<typename T> class allocator
{
public:
	T* allocate(int n) { return new T[n]; }
	void deallocate(T* p) { delete[] p; }
};
 
template<typename T, typename Alloc = allocator<T> > class vector
{
	Alloc alloc; // 정책 클래스를 포함으로 사용하는 코드
public:
	void resize(int n)
	{
		//메모리를 할당해야 합니다. 어떻게 할까요?
		// malloc(), new, 메모리풀, 윈도우함수, 리눅스함수?
		T* p = alloc.allocate(n);
		
		//메모리 해제
		alloc.deallocate(p);
	}
};

int main()
{
	vector<int> v(3);

	v.resize(10);

}