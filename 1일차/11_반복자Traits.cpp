// 11_�ݺ���Traits
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


template<typename T>
inline void xadvance_imp(T& p, int n, input_iterator_tag)	//�������� ���ָ�
//�����Ϸ��� �����ε��� ���� ����ϴ� ������ �����Ѵ�.
{
	cout << "���� ������ �ƴҶ�" << endl;
	while (n--) ++p;
}

template<typename T>
inline void xadvance_imp(T& p, int n, random_access_iterator_tag)
{
	//�ݺ����� ������ ���� �ٸ� �Լ��� ����ϰ� �Ѵ�.
	//typename T::iterator_category a;

	cout << "���� �����϶�" << endl;
	p = p + n;
}

//�ݺ��� ���� : �ݺ��� ó�� �����ϴ� ��� ���� �ݺ����̴�.
//				++�� �̵��ϰ� *�� ���� ���� �� �ִ� ��� ��
// �ݺ����� 2���� ����
// 1. ��¥ ������
// 2. ����Ʈ������ó�� ��ü�� ����� �ݺ���

// 2���� ���� ������ generic �˰��� ������ ��ƴ�.
// �ذ�å
/*
template<typename T> struct iterator_traits
{
	typedef typename T::iterator_category iterator_category;
};

// T�� ��ü�� �ݺ��ڰ� �ƴ� ������ �϶�
template<typename T> struct iterator_traits<T*>
{
	typedef random_access_iterator_tag iterator_category;
};
*/

template<typename T> void xadvance(T& p, int n)
{
	//xadvance_imp(p, n, typename T::iterator_category());

	xadvance_imp(p, n, typename iterator_traits<T>::iterator_category());
}

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* p2 = x;

	xadvance(p2, 4);
	
	cout << *p2 << endl;

	vector<int> v(x, x + 10);

	vector<int>::iterator p = v.begin();

	//p = p + 6;	// ?

	//advance(p, 6);	//������ �ݺ��ڵ� ���� �ݺ��ڵ� ��� ����
	xadvance(p, 6);		//������ �ݺ��ڵ� ���� �ݺ��ڵ� ��� ����
}

