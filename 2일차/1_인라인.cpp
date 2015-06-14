//1_인라인
//1. 장점 : 기계어 코드 치환, 속도가 빠르다.
//2. 단점 : 여러번 치환되면 목적코드의 크기가 커질 수 있다.
//			1~2줄 짜리 간단한 함수는 오히려 목적코드의 크기가 줄어듭니다.
	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);//호출
	int n2 = Add2(1, 2);//기계어 코드 치환
	
//	int(*f)(int, int) = &Add2;

//	f(1, 2); // ??

}// cl 1_인라인.cpp /FAs