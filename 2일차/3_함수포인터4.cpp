#include <iostream>
using namespace std;

void foo() { cout << "foo" << endl; }
void goo(int a) { cout << "goo" << a << endl; }

class Dialog
{
public:
	void Close() { cout << "Dialog Close" << endl; }
};

// BOOST���� ���� ������ �Լ� ������ ��ü
// 2008���� C++ ǥ�ؿ� �߰��Ǿ����ϴ�.
#include <functional>
using namespace std::placeholders;	// _1, _2, _3 ��...

void hoo(int a, int b) { cout << "hoo: " << a << "," << b << endl; }

void koo(int a, int b, int c, int d)
{
	printf("koo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	function<void(int, int)> f;
	
	f = bind(&koo, _2, 7, _1, 9);	// bind�� ���ڰ� ȣ�� ������ ����
									// _2�� f()�� �ι�° ���ڷ� ����
	
	f(3, 5);	// koo : 5, 7, 3, 9�� ������ �غ�����.

}

//int main()
//{
//	function<void(int)> f;
//
//	f = bind(&hoo, 3, _1); // �ɱ��?	//_1�� f()�� ù��° ���ڷ� �ްڴٴ� �ǹ�
//	
//	f(5);	//hoo(3,5)
//
//	return 0;
//}


//
//int main()
//{
//	function<void()> f = &foo;
//	f(); // foo ȣ��
//	
//	f = bind(&goo, 5);	// ���ڸ� 5�� ����
//	f();
//
//	Dialog dlg;
//	f = bind(&Dialog::Close, &dlg);
//	f();	//Dialog Close() ȣ��
//}