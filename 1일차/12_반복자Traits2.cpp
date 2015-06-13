// 12_�ݺ���Traits2
#include <iostream>
#include <vector>
#include <iterator>	// iterator_traits ���� ��� �ֽ��ϴ�.
using namespace std;


// first ~ last������ ���� ���϶�
/*
int sum(int * first, int* last)
{
	int s = 0;

	while (first != last)
	{
		s += *first;
		++first;
	}
	return s;
}*/

//��� ���޳ʿ��� ���� ���� �� �ְ� "�Ϲ�ȭ"
template<typename T>
typename iterator_traits<T>::value_type sum(T first, T last)
{
	// T�� �ݺ���(list_iterator��)
	// T::value_type : �ݺ��ڰ� ����Ű�� Ÿ��
	// typename T::value_type s = 0;
	
	typename iterator_traits<T>::value_type s = 0;
	
	// C++11�� ��ó�� �����ϰ� ���� �ʰ� *first�� Ÿ���� �����Ϸ�����
	// ��û�ص� �˴ϴ�. vc++2013���� �����˴ϴ�.
	// decltype(*first) s = 0;

	while (first != last)
	{
		s += *first;
		++first;
	}
	return s;
}

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	int s1 = sum(x, x + 10);
	cout << s1 << endl;

	vector<int> v(x, x + 10);
	int s2 = sum(v.begin(), v.end());

	cout << s2 << endl;
}