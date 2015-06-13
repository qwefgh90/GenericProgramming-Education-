// ������ Ÿ�� 2���� �����ϴ� ����ü
template<typename T, typename U> struct Duo
{
	T v1;
	U v2;

	enum { N = 2 };
};

//	Duo�� ����ȭ ��� - ������ �ڵ����� �����ϱ� ��ƽ��ϴ�.

struct Null{}; // empty Ŭ���� - �ƹ� ����� ������
				// �Լ������ε��̳� ���ø� ���ڷ� ����ϱ� ���� �����.

template<typename P1 = Null,
	typename P2 = Null,
	typename P3 = Null,
	typename P4 = Null,
	typename P5 = Null>
class xtuple : public Duo<P1, xtuple<P2, P3, P4, P5, Null>>
{

};

//xtuple�� ������ Ÿ���� 2���� �������� ���� �κ� ����ȭ

template<typename P1, typename P2>
class xtuple<P1, P2, Null, Null, Null> : public Duo<P1,P2>
{
};

int main()
{
	//			Duo<short, double>			
	//		Duo<long, xtuple<short,double,Null>>
	//   Duo<char, xtuple<long,short,double,Null>>
	// Duo<int, xtuple<char, long, short, double, Null>>	//�Ʒ��� ����.
	xtuple<int, char, long, short, double> t5;


	xtuple<int, int, int> t3;
}



