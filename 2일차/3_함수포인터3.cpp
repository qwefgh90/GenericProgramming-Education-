//3_�Լ�������3
#include <iostream>
using namespace std;

//��ü �̺�Ʈ ó�����
class Button
{
	void(*handler)();
	
	//void(Dialog::*handler)();	//�׼�
	//Dialog* object;	//Ÿ��

public:
	void setHandler(void(*f)()) { handler = f; }
	void Click()
	{
		//�̺�Ʈ �߻��� ����� �ܺο� �˷��� �Ѵ�.
		//java, �ȵ���̵� ��, C++ Ÿ���� : �������̽� ��� ������
		//C++ MFC, QT, ������ : �Լ� ������ ��� callback ����..
		handler();

		//(object->*handler)();
	}
};
void foo() { cout << "foo" << endl; }
void goo() { cout << "goo" << endl; }
int main()
{
	Button b1, b2;
	b1.setHandler(foo);
	b2.setHandler(goo);//�Լ����
	b1.Click();
	
	////���� : java style
	//Window w = new Widnow();
	//b1.addListener(&w);	//��ü ���
	//b2.addListener(&w);	//��ü ���
	//b1.Click();
}