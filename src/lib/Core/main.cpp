#include "Core.h"
#include <ctime>
#include <map>
#include <iostream>
#include "DB/Role/Land/诺艾尔.h"
#define LOOPCOUNT 100000000;
using namespace std;
using namespace Core;
//using namespace Role;
//void testAttr();
//void testBaseObject();
//double FBNQ(double);
//int LoopMapFindTest();
//Attr* LoopSwitchFindTest();
//void LoopRand();
void main() {
	Role* x = new 诺艾尔();
	cout << x;
	//testAttr();
	//testBaseObject();

	//clock_t start, end;

	//LoopMapFindTest();
	//LoopSwitchFindTest();
	//LoopRand();
	//cout << FBNQ(45);
	//testAttr();
	//testBaseObject();
	//end = clock();
	//std::cout << endl << "RUN::" << ((double)(end - start) / 1000) << "秒" << endl;
	system("pause");
}
void LoopRand() {
	clock_t start, end;
	int LoopCount;
	LoopCount = LOOPCOUNT;
	int cache;
	start = clock();
	while (LoopCount--)
	{
		cache += 1;
	}
	end = clock();
	LoopCount = LOOPCOUNT;

	cout << cache << endl;
	cout << LoopCount << "次Rand()%10::" << ((double)(end - start) / 1000) << "秒" << endl;

	return;
}
int LoopMapFindTest() {
	clock_t start, end;
	int LoopCount;
	LoopCount = LOOPCOUNT;
	int cache;
	map<int, int> data = *new map<int, int>();
	cache = 0;
	while (cache++ < 10)
	{
		data[cache] = rand();
	}
	start = clock();

	while (LoopCount--)
	{
		cache = data[rand() % 10];
	}
	end = clock();
	LoopCount = LOOPCOUNT;

	cout << cache << endl;
	cout << LoopCount << "次Map[key]+Rand()%10::" << ((double)(end - start) / 1000) << "秒" << endl;

	return cache;
}
Attr* LoopSwitchFindTest() {
	clock_t start, end;
	int LoopCount;
	LoopCount = LOOPCOUNT;

	Attr* cache = Attr::Zero();
	BaseObject data = *new BaseObject();
	start = clock();
	//map<int, int> data = *new map<int, int>();
	while (LoopCount--)
	{
		cache = data.GetAttr(rand() % 10);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << cache->LastValue() << endl;
	cout << LoopCount << "次Switch(key)+Rand()%10::" << ((double)(end - start) / 1000) << "秒" << endl;

	return cache;
}
double FBNQ(double n) {
	{

		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else {
			//uint64_t temp = FBNQ(n - 1) + FBNQ(n - 2);
			return FBNQ(n - 1) + FBNQ(n - 2);
			//return temp;
		}

	}
}
void testAttr() {
	Attr* a = new Attr(1, 1, 1);
	Attr* b = new Attr(a);
	clock_t start, end;
	int LoopCount;
	LoopCount = LOOPCOUNT;
	start = clock();
	while (LoopCount--)
	{
		a->Add(b);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << a->LastValue() << endl;
	cout << LoopCount << "次Attr相加:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->Clean();
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << a->LastValue() << endl;
	cout << LoopCount << "次Attr清空:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->Copy(b);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << a->LastValue() << endl;
	cout << LoopCount << "次Attr拷贝:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->LastValue();
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << a->LastValue() << endl;
	cout << LoopCount << "次Attr计算:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

}
void testBaseObject() {
	Attr** list = new Attr * [26];
	BaseObject* a = new BaseObject();
	BaseObject* b = new BaseObject();
	Attr* c = new Attr(1, 1, 1);

	uint32_t key = (0b100 << 8) | 11;
	clock_t start, end;
	int LoopCount;
	LoopCount = LOOPCOUNT;
	start = clock();
	while (LoopCount--)
	{
		a->Add(b);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << a->LastValue() << endl;
	cout << LoopCount << "次BaseObject相加:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->Clean();
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << a->LastValue() << endl;
	cout << LoopCount << "次BaseObject清空:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->GetAttr(key);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << a->LastValue() << endl;
	cout << LoopCount << "次BaseObject获取属性:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->SetAttr(key, c);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << a->LastValue() << endl;
	cout << LoopCount << "次BaseObject设置属性:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->Copy(b);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << a->LastValue() << endl;
	cout << LoopCount << "次BaseObject拷贝:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->LastValue();
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << a->LastValue() << endl;
	cout << LoopCount << "次BaseObject计算:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

}