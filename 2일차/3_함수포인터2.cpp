//3_�Լ�������2
#include <iostream>

class Dialog
{
public:
	void Close(){}
};

void foo() {}

int main()
{
	void(*f1)() = &foo; // ok!!
	//void(*f2)() = &Dialog::Close; // error, ��� �Լ��� this�� �߰��ȴ�.

	void(Dialog::*f2)() = &Dialog::Close;

	//f2(); // ��ü(this)�� ����. error

	Dialog dlg;
	//dlg.f2();	//�Լ������͸� ȣ���ϱ� ���� *�� �ִ´�.
	//dlg.*f2();	//������ �켱������ ���� ��ȣ�� �ִ´�.
	(dlg.*f2)(); // �ᱹ dlg.Close();

}