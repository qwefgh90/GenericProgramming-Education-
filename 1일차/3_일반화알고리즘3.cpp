//5_일반화알고리즘3

#include <iostream>
using namespace std;

//일반화 프로그래밍 개념 : 하나의 함수(클래스)를 다양한 용도로 활용할 수 있게 만들자는 것!!

// Step3. 검색 대상 타입의 일반화 - 템플릿 도입
//									함수이름 변경
template <typename T>
T* xfind(T* first, T* last, T v)
{
	while (first != last && *first != v)
		first++;

	return first == last ? 0 : first;
}

int main()
{
	double d[] = {1,2,3,4,5,6,7,8,9,10,11};
	
	double* p = xfind(d, d + 10, 11.0);

	if (p == 0)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;

}