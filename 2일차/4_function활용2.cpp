// 4_function활용2
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
//			의존 관계 역전의 법칙
//			관심있는 모듈이 callback 함수를 등록하는 디자인이 좋다는 것!

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
			v[i](param);	// v[i]는 function<>이므로 ()호출
		}
	}

	// 라이브러리를 훌륭하게 만들기 위해서 
	// "global 통보센터" 라는 개념을 만들어 봅시다.
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

	//배터리 상태가 변하면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
	
}

