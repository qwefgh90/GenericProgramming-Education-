// 4_functionȰ��2
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <vector>
using namespace std;
using namespace std::placeholders;

void foo(void*) { cout << "foo" << endl; };
void goo(void*, int a, int b) { cout << "goo" << endl; };

// DIP : Dependency Inversion Principle
//			���� ���� ������ ��Ģ
//			�����ִ� ����� callback �Լ��� ����ϴ� �������� ���ٴ� ��!

class NotificationCenter
{
	typedef function<void(void*)> HANDLER;
	map<string, vector<HANDLER>> notif_map;
public:
	void addObserver(string key, HANDLER h)
	{
		notif_map[key].push_back(h);
	}
	void postNotificationWithName(string key, void* param)
	{
		vector<HANDLER>& v = notif_map[key];
		for (int i = 0; i < v.size(); i++)
		{
			v[i](param);	// v[i]�� function<>�̹Ƿ� ()ȣ��
		}
	}

	// ���̺귯���� �Ǹ��ϰ� ����� ���ؼ� 
	// "global �뺸����" ��� ������ ����� ���ô�.
	static NotificationCenter& defaultCenter()
	{
		static NotificationCenter instance;
		return instance;
	}

};

int main()
{
	//NotificationCenter nc;
	NotificationCenter& nc = NotificationCenter::defaultCenter();;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", bind(&goo, _1, 0, 0));

	//���͸� ���°� ���ϸ�
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
	
}

