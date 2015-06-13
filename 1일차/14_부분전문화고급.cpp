// 14_부분전문화고급
#include <iostream>
using namespace std;

template<typename T> void count(const T& a)
{
	cout << T::N << endl;
}

// 임의의 타입 2개를 보관하는 구조체
template<typename T, typename U> struct Duo
{
	T v1;
	U v2;

	enum { N = 2};
};


//2번째 인자가 Recursive 일때를 위한 부분 전문화
template<typename A, typename B, typename C> struct Duo <A, Duo<B,C>>
{
	A v1;
	Duo<B,C> v2;
	
	enum { N = Duo<B,C>::N + 1 };
};

	//1, 2번째 인자가 Recursive 일때를 위한 부분 전문화
	template<typename A, typename B, typename C, typename D> struct Duo <Duo<A, B>, Duo<C, D>>
	{
		Duo<A,B> v1;
		Duo<C,D> v2;

		enum { N = Duo<A, B>::N + Duo<C, D>::N };
	};

		//2번째 인자가 Recursive 일때를 위한 부분 전문화
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
	Duo<int, Duo<int, int>> d3;	//recursive Duo 객체
	Duo<int, Duo<int, Duo<int, int>>> d4;

	count(d2);
	count(d3);
	count(d4);
}
*/