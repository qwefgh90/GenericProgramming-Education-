//3_�ζ���
#include <iostream>
#include <algorithm>
using namespace std;
//���̺귯�� �����ڸ� ������ ���ô�.
// 1. �ӵ��� ����� �Ѵ�.
// 2. �������� �־�� �Ѵ�. - ��å ������ �����ؾ� �Ѵ�. (��������, �������� ó��)

// ������ �ʴ� ��ü �˰���(���뼺)���� ���ϴ� �κ�(������)�� ã�Ƽ� �и��ؾ��Ѵ�.
// �Ϲ� �Լ������� ���ϴ� �κ��� �Լ� ����ȭ �ؾ� �Ѵ�.

//sort�� ����� �� �Լ�
bool cmp1(int a, int b){ return a>b; }
bool cmp2(int a, int b){ return a<b; }//����

// C ǥ�� qsort()�� �̷� ��� �Դϴ�.
void Sort(int* x, int n, bool(*cmp)(int,int))
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
//-------------------


int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	Sort(x, 10, cmp1);
}