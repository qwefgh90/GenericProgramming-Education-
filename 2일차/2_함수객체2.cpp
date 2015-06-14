//2_�Լ���ü2
#include <iostream>
#include <algorithm>
using namespace std;
//1. �Ϲ� �Լ��� �ڽŸ��� Ÿ���� ����.
//	 signature�� ������ ��� �Լ��� ���� Ÿ���̴�.!

//2. �Լ���ü�� �ڽŸ��� Ÿ���� �ִ�. 
//	 signature�� �����ص� ��� �Լ��� �ٸ� Ÿ���̴�.

struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};

struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

//��å ������ �����ϸ鼭�� �������ϰ� ���� sort()�����.!!
// template�� �Լ���ü�� ����ϴ� ��� - C++ ������ ������ ������
//										STL�� ����ö��
// ���� : ��å�� ������ Ƚ�� ��ŭ sort()���� �ڵ尡 �����ȴ�.
//		�ڵ� �޸� ��뷮�� �����Ѵ�.
template<typename T> void Sort(int* x, int n, T cmp)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}
//Less f1; Sort(x, 10, f1);
//Greater f2; Sort(x, 10, f2);