#include <iostream>
#include <vector>
using namespace std;


//vector에 대해서
int main()
{
	vector<int> v(10, 3); //10개를 3으로 초기화

	cout << v.size() << endl;		//10
	cout << v.capacity() << endl;	//10

	v.resize(7);		// 7개로 줄이기.. 이때 알고리즘을 생각해봅시다.

	cout << v.size() << endl;		//7
	cout << v.capacity() << endl;	//10

	v.push_back(1);//끝에 한개 추가

	cout << v.size() << endl;		//8
	cout << v.capacity() << endl;	//10
	
	v.shrink_to_fit(); 	//필요 없는 공간 지워 달라

	cout << v.size() << endl;		//8
	cout << v.capacity() << endl;	//8

	v.push_back(1);//메모리 재할당

	cout << v.size() << endl;		// 9
	cout << v.capacity() << endl;	// 12 (1.5배)
}