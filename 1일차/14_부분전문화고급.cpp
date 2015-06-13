// 14_�κ�����ȭ���
#include <iostream>
using namespace std;

template<typename T> void count(const T& a)
{
	cout << T::N << endl;
}

// ������ Ÿ�� 2���� �����ϴ� ����ü
template<typename T, typename U> struct Duo
{
	T v1;
	U v2;

	enum { N = 2};
};


//2��° ���ڰ� Recursive �϶��� ���� �κ� ����ȭ
template<typename A, typename B, typename C> struct Duo <A, Duo<B,C>>
{
	A v1;
	Duo<B,C> v2;
	
	enum { N = Duo<B,C>::N + 1 };
};

	//1, 2��° ���ڰ� Recursive �϶��� ���� �κ� ����ȭ
	template<typename A, typename B, typename C, typename D> struct Duo <Duo<A, B>, Duo<C, D>>
	{
		Duo<A,B> v1;
		Duo<C,D> v2;

		enum { N = Duo<A, B>::N + Duo<C, D>::N };
	};

		//2��° ���ڰ� Recursive �϶��� ���� �κ� ����ȭ
		template<typename A, typename B, typename C> struct Duo <Duo<A, B>, C>
		{
			Duo<A, B> v1;
			C v2;

			enum { N = Duo<A, B>::N + 1 };
		};


		int main()
		{
			Duo<Duo<int, int>, Duo<int, int>> d4;

			count(d4);
		}

		/*
	int main()
	{
		Duo<Duo<int, int>, int> d3;
		Duo<Duo<int, Duo<int, int>>, int> d4;

		count(d3);
		count(d4);

	}
	*/
/*
int main()
{
	Duo<int, int> d2;
	Duo<int, Duo<int, int>> d3;	//recursive Duo ��ü
	Duo<int, Duo<int, Duo<int, int>>> d4;

	count(d2);
	count(d3);
	count(d4);
}
*/