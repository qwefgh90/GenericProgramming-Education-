// 1_���ø�����.cpp
//#include <iostream>
//using namespace std;


/*

//1.int�� ����
int square(int a) { return a*a; }
//2.double�� ����
double square(double a) { return a*a; }
*/

//������ �ڵ尡 �ݺ��Ǹ� �ڵ� �����⸦ �������!!
//1. C��� - ��ũ�θ� ����� �ڵ� ����
//���� : ��ũ�ο� ���� �ڵ������ ��ó���Ⱑ �Ѵ�.
//			��ó����� Ÿ���� ���� ���Ѵ�.
//			�׷��� � ������ �ʿ����� ����ڰ� �����ؾ��Ѵ�.
//			MAKE_SQUARE(int)��� �����ؾߵ�
/*
#define MAKE_SQUARE(T)	T square ( T a ) { return a*a; }

MAKE_SQUARE(int)
MAKE_SQUARE(double)
*/

//2. C++ - �����Ϸ��� ���� �ڵ� ���� ��� - template!!
//���� : �����Ϸ��� Ÿ���� �˰� �ִ�.
//			�ҽ��� �м��ؼ� � Ÿ���� �ʿ����� ��Ȯ��
//			�˾Ƴ��� �ش� �Լ��� ������ �ش�.!!
//			MAKE_SQUARE(int)���� �ʿ� ����.
//���� : �����Ϸ��� �ڵ带 �����Ҷ� �ʿ��� �ڵ� �̻����� �ʹ� ���� Ÿ���� 
//			�Լ�/Ŭ������ �����ؼ� �ڵ� �޸� ��뷮�� ����
//			�� �� �ִ�. - "Code Bloat" ��� �Ҹ��� ����
//			�Ӻ���� ���߽� ����!!d

template <typename T>	T square ( T a ) { return a*a; }

// �ν��Ͻ�ȭ(instantiation) : ���ø��� T�� Ÿ���� �����Ǿ� ��¥ �Լ��� ����� ����
//
// �Ͻ��� �ν��Ͻ�ȭ : T�� Ÿ���� �����Ϸ��� �߷��ϴ� ��
// ����� �ν��Ͻ�ȭ : T�� Ÿ���� ����ڰ� �����ϴ� ��

int main()
{
	square(3);
	square(3.3);
	
	short s = 3;
	square(s);	//1. square(short) ������ �����Ұ��̴�. (����� �ν��Ͻ�ȭ)

	//cl.exe ( �����Ϸ� )
	//C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013�� ������ ��� ������Ʈ
	//1) cl 1_���ø����� /FAs	-> �������
	//2) notepad 1_���ø�����.asm
	//3) 
	

	//int�� ������ �Լ��� ����ϰ� ������ (Code Bloat �ذ� �� �������� �ǵ���� �ڵ��ϴ� ��)
	square<int>(s);	//2.  sqaure(int) ������ ����ϰ� ���� ���̴�. (����� �ν��Ͻ�ȭ)
	
	

	
}