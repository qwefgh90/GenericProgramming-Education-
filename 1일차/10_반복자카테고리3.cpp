// 10_�ݺ���ī�װ�3
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
// STL�� �ݺ����� 5���� ī�װ��� Ÿ��ȭ �մϴ�. (�̹� STL�� ���ǵǾ� ����)
struct input_iterator_tag {};	//empty class(struct)
								//�ƹ� ����� ������ Ÿ���� Ÿ���̴�.
								//�Լ� �����ε��̳�, ���ø����ڷ� Ȱ��ȴ�.

struct output_iterator_tag {};	
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};
*/

//�׸��� �ݺ��ڸ� ���鶧 �ڽ��� ������ �ܺο� �˷��ֱ�� �߽��ϴ�.
template<typename T> class list_iterator
{
public:
	typedef bidirectional_iterator_tag iterator_category;

};

template<typename T> class vector_iterator
{
public:
	typedef random_access_iterator_tag iterator_category;

};

// �Լ� �����ε��� ����ؼ� ���� ���� �϶��� �ƴҶ��� �����մϴ�.
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

// STL�� �ִ� advance() �˰����� ����� ���ô�.
template<typename T> void xadvance(T p, int n)
{
	xadvance_imp(p, n, typename T::iterator_category());	//T::iterator_category() �ӽ� ��ü, �����ε��� ����

	//��� �ݺ��ڴ� ++�� �����ϴ�.
	
}

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	
	vector<int> v(x, x + 10);

	vector<int>::iterator p = v.begin();
	
	//p = p + 6;	// ?
	
	//advance(p, 6);	//������ �ݺ��ڵ� ���ǹݺ��ڵ� ��� ����
	xadvance(p, 6);
	
	
}