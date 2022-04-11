#include <ctime>
#include <iostream>
#include "../DB/DB.h"
#define LOOPCOUNT 10000000;
using namespace std;
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



	/*Attr* c = new Attr(10, 20, 30);
	Attr a = c;
	Attr* y = new Attr[5]{ c };
	cout << c->LastValue() << endl << a.LastValue() << endl << (*y).LastValue() << endl;*/
	u32* mm = new u32[1];
	*mm = 15;
	Advanced::Role* x = nullptr;
	x = Create(RoleName::诺艾尔, mm);
	x->Q(x, 0);
	cout << x->GetLastData()->LastValue()->Atk;
	//int LoopCount;
	//LoopCount = LOOPCOUNT;
	clock_t start, end;
	start = clock();
	//while (LoopCount--)
	//{
	//	
	//	//cout << x;
	//	delete x;
	//}
	//Wait
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
