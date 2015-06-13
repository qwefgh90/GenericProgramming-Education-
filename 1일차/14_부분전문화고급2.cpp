// 임의의 타입 2개를 보관하는 구조체
template<typename T, typename U> struct Duo
{
	T v1;
	U v2;

	enum { N = 2 };
};

//	Duo의 선형화 기술 - 간단한 코드지만 이해하기 어렵습니다.

struct Null{}; // empty 클래스 - 아무 멤버도 없지만
				// 함수오버로딩이나 템플릿 인자로 사용하기 위해 만든다.

template<typename P1 = Null,
	typename P2 = Null,
	typename P3 = Null,
	typename P4 = Null,
	typename P5 = Null>
class xtuple : public Duo<P1, xtuple<P2, P3, P4, P5, Null>>
{

};

//xtuple이 임의의 타입을 2개만 가질때를 위한 부분 전문화

template<typename P1, typename P2>
class xtuple<P1, P2, Null, Null, Null> : public Duo<P1,P2>
{
};

int main()
{
	//			Duo<short, double>			
	//		Duo<long, xtuple<short,double,Null>>
	//   Duo<char, xtuple<long,short,double,Null>>
	// Duo<int, xtuple<char, long, short, double, Null>>	//아래와 같다.
	xtuple<int, char, long, short, double> t5;


	xtuple<int, int, int> t3;
}



