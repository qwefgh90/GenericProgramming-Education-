// 8_typename

// 템플릿 의존적으로 type의 이름을 꺼낼때는 꼭 typename을 적어야 한다.
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
	typename T::DWORD * p;	// 해석해 보세요.. DWORD는 뭘까요?
					// 1. DWORD 는 static 멤버 변수인데 곱하기 p하고 있다. (기본)
					// 2. DWORD는 typedef 되어 있는 type이다.
					//	포인터 변수 p를 선언하고 있다.	(C++표준에서 typename 이라고 명시적으로 써야한다. 
					//	VC에서는 컴파일러가 추측하지만 습관적으로 반드시 써라.)
	return 0;
}

int main()
{
	AAA aaa;
	foo(aaa);
}