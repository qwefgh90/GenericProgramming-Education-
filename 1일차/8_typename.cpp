// 8_typename

// ���ø� ���������� type�� �̸��� �������� �� typename�� ����� �Ѵ�.
// typename T::DWORD p;

class AAA
{
	//...
public:
	//static int DWORD
	typedef int DWORD;

};

int p = 0;

template<typename T> typename T::DWORD foo(T a)
{
	typename T::DWORD * p;	// �ؼ��� ������.. DWORD�� �����?
					// 1. DWORD �� static ��� �����ε� ���ϱ� p�ϰ� �ִ�. (�⺻)
					// 2. DWORD�� typedef �Ǿ� �ִ� type�̴�.
					//	������ ���� p�� �����ϰ� �ִ�.	(C++ǥ�ؿ��� typename �̶�� ��������� ����Ѵ�. 
					//	VC������ �����Ϸ��� ���������� ���������� �ݵ�� ���.)
	return 0;
}

int main()
{
	AAA aaa;
	foo(aaa);
}