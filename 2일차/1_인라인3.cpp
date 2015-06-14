//3_인라인
#include <iostream>
#include <algorithm>
using namespace std;
//라이브러리 설계자를 생각해 봅시다.
// 1. 속도가 빨라야 한다.
// 2. 유연성이 있어야 한다. - 정책 변경이 가능해야 한다. (오름차순, 내림차순 처럼)

// 변하지 않는 전체 알고리즘(공통성)에서 변하는 부분(가변성)을 찾아서 분리해야한다.
// 일반 함수에서는 변하는 부분을 함수 인자화 해야 한다.

//sort가 사용할 비교 함수
bool cmp1(int a, int b){ return a>b; }
bool cmp2(int a, int b){ return a<b; }//내림

// C 표준 qsort()가 이런 방식 입니다.
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