//5_��������2
#include <iostream>
using namespace std;

//�޸� �Ҵ�/������ ������ ���� ��å Ŭ����
template<typename T> class allocator
{
public:
	T* allocate(int n) { return new T[n]; }
	void deallocate(T* p) { delete[] p; }
};
 
template<typename T, typename Alloc = allocator<T> > class vector
{
	Alloc alloc; // ��å Ŭ������ �������� ����ϴ� �ڵ�
public:
	void resize(int n)
	{
		//�޸𸮸� �Ҵ��ؾ� �մϴ�. ��� �ұ��?
		// malloc(), new, �޸�Ǯ, �������Լ�, �������Լ�?
		T* p = alloc.allocate(n);
		
		//�޸� ����
		alloc.deallocate(p);
	}
};

int main()
{
	vector<int> v(3);

	v.resize(10);

}