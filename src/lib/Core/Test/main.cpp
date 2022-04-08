#include <ctime>
#include <iostream>
#include "../DB/DB.h"
#define LOOPCOUNT 10000000;
using namespace std;
using namespace Advanced;
using namespace DB::RoleConstruct;
//using namespace Role;
//void testAttr();
//void testBaseObject();
//double FBNQ(double);
//int LoopMapFindTest();
//Attr* LoopSwitchFindTest();
//void LoopRand();
void main() {
	//指针->隐->实例（可以)
	//实例->隐->指针（不可以）

	Attr* c = new Attr(10, 20, 30);
	Attr a = c;
	Attr* y = new Attr[5]{ c };
	cout << c->LastValue() << endl << a.LastValue() << endl << (*y).LastValue() << endl;
	Advanced::Role* x = nullptr;
	int LoopCount;
	LoopCount = LOOPCOUNT;
	clock_t start, end;
	start = clock();
	while (LoopCount--)
	{
		x = Create(RoleName::五郎);
		//cout << x;
		delete x;
	}
	//cout << x;
	//testAttr();
	//testBaseObject();


	//LoopMapFindTest();
	//LoopSwitchFindTest();
	//LoopRand();
	//cout << FBNQ(45);
	//testAttr();
	//testBaseObject();
	end = clock();
	cout << endl << "RUN::" << ((double)(end - start) / 1000) << "秒" << endl;
	//system("pause");
};
