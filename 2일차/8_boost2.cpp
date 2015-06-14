#include <iostream>
#include <string>
#include <boost\bimap.hpp>
using namespace std;
using namespace boost;

int main()
{
	typedef bimap<string, string> BIMAP;
	BIMAP bm;
	
	bm.insert(BIMAP::value_type("mon", "������"));
	bm.insert(BIMAP::value_type("tue", "ȭ����"));
	bm.insert(BIMAP::value_type("wed", "������"));
	
	cout << bm.left.at("mon") << endl;		//"������"
	cout << bm.right.at("������") << endl;	//"wed" ����غ�����

	//cout << bm["mon"] << endl;
}