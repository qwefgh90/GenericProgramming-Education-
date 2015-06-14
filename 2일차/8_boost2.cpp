#include <iostream>
#include <string>
#include <boost\bimap.hpp>
using namespace std;
using namespace boost;

int main()
{
	typedef bimap<string, string> BIMAP;
	BIMAP bm;
	
	bm.insert(BIMAP::value_type("mon", "월요일"));
	bm.insert(BIMAP::value_type("tue", "화요일"));
	bm.insert(BIMAP::value_type("wed", "수요일"));
	
	cout << bm.left.at("mon") << endl;		//"월요일"
	cout << bm.right.at("수요일") << endl;	//"wed" 출력해보세요

	//cout << bm["mon"] << endl;
}