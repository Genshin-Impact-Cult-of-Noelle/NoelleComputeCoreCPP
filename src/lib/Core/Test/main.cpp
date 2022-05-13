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
	//Advanced::RoleGroup(1);
	u32* mm = new u32[1];
	*mm = 0;
	auto group = new  Advanced::RoleGroup(mm);
	Advanced::Role* x = nullptr;
	x = Create(RoleName::诺艾尔, mm);
	auto zl = Create(RoleName::钟离, mm);
	group->Join(x)->Join(zl);
	group->Swap(x);

	cout << x->GetLastData()->LastValue()->Atk << endl;
	/*int LoopCount;
	LoopCount = 0;*/
	clock_t start, end;
	start = clock();
	x->Q(zl, 14);
	//while ((*mm) < 3000000)
	//{
	//	//cout << *mm << endl;
	//	x->Q(zl, 14);

	//	group->Update();
	//	//cout << *mm << "||" << x->GetLastData()->LastValue()->Atk << endl;
	//}
	cout << x->GetLastData()->LastValue()->Atk << endl;
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
	cout << endl << "RUN::" << ((double)(end - start)) << "毫秒" << endl;
	//system("pause");
};
