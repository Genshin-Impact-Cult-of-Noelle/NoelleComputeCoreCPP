
#include <ctime>
#include <iostream>
#include "../DB/Role/Land/诺艾尔.h"
#define LOOPCOUNT 1000;
using namespace std;
using namespace Advanced;
//using namespace Role;
//void testAttr();
//void testBaseObject();
//double FBNQ(double);
//int LoopMapFindTest();
//Attr* LoopSwitchFindTest();
//void LoopRand();
void main() {
	Role* x = nullptr;
	int LoopCount;
	LoopCount = LOOPCOUNT;
	clock_t start, end;
	start = clock();
	while (LoopCount--)
	{
		x = new 诺艾尔();
		//cout << LoopCount << endl;

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
	std::cout << endl << "RUN::" << ((double)(end - start) / 1000) << "秒" << endl;
	//system("pause");
};
//void LoopRand() {
//	clock_t start, end;
//	int LoopCount;
//	LoopCount = LOOPCOUNT;
//	int cache;
//	start = clock();
//	while (LoopCount--)
//	{
//		cache += 1;
//	}
//	end = clock();
//	LoopCount = LOOPCOUNT;
//
//	cout << cache << endl;
//	cout << LoopCount << "次Rand()%10::" << ((double)(end - start) / 1000) << "秒" << endl;
//
//	return;
//}
//int LoopMapFindTest() {
//	clock_t start, end;
//	int LoopCount;
//	LoopCount = LOOPCOUNT;
//	int cache;
//	map<int, int> data = *new map<int, int>();
//	cache = 0;
//	while (cache++ < 10)
//	{
//		data[cache] = rand();
//	}
//	start = clock();
//
//	while (LoopCount--)
//	{
//		cache = data[rand() % 10];
//	}
//	end = clock();
//	LoopCount = LOOPCOUNT;
//
//	cout << cache << endl;
//	cout << LoopCount << "次Map[key]+Rand()%10::" << ((double)(end - start) / 1000) << "秒" << endl;
//
//	return cache;
//}
//Attr* LoopSwitchFindTest() {
//	clock_t start, end;
//	int LoopCount;
//	LoopCount = LOOPCOUNT;
//
//	Attr* cache = Attr::Zero();
//	BaseObject data = *new BaseObject();
//	start = clock();
//	//map<int, int> data = *new map<int, int>();
//	while (LoopCount--)
//	{
//		cache = data.GetAttr(rand() % 10);
//	}
//	end = clock();
//	LoopCount = LOOPCOUNT;
//	cout << cache->LastValue() << endl;
//	cout << LoopCount << "次Switch(key)+Rand()%10::" << ((double)(end - start) / 1000) << "秒" << endl;
//
//	return cache;
//}
//double FBNQ(double n) {
//	{
//
//		if (n == 0)
//			return 0;
//		else if (n == 1)
//			return 1;
//		else {
//			//uint64_t temp = FBNQ(n - 1) + FBNQ(n - 2);
//			return FBNQ(n - 1) + FBNQ(n - 2);
//			//return temp;
//		}
//
//	}
//}
//
//void testBaseObject() {
//	Attr** list = new Attr * [26];
//	BaseObject* a = new BaseObject();
//	BaseObject* b = new BaseObject();
//	Attr* c = new Attr(1, 1, 1);
//
//	u32 key = (0b100 << 8) | 11;
//	clock_t start, end;
//	int LoopCount;
//	LoopCount = LOOPCOUNT;
//	start = clock();
//	while (LoopCount--)
//	{
//		a->Add(b);
//	}
//	end = clock();
//	LoopCount = LOOPCOUNT;
//	cout << a->LastValue() << endl;
//	cout << LoopCount << "次BaseObject相加:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
//
//	start = clock();
//	while (LoopCount--)
//	{
//		a->Clean();
//	}
//	end = clock();
//	LoopCount = LOOPCOUNT;
//	cout << a->LastValue() << endl;
//	cout << LoopCount << "次BaseObject清空:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
//
//	start = clock();
//	while (LoopCount--)
//	{
//		a->GetAttr(key);
//	}
//	end = clock();
//	LoopCount = LOOPCOUNT;
//	cout << a->LastValue() << endl;
//	cout << LoopCount << "次BaseObject获取属性:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
//
//	start = clock();
//	while (LoopCount--)
//	{
//		a->SetAttr(key, c);
//	}
//	end = clock();
//	LoopCount = LOOPCOUNT;
//	cout << a->LastValue() << endl;
//	cout << LoopCount << "次BaseObject设置属性:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
//
//	start = clock();
//	while (LoopCount--)
//	{
//		a->Copy(b);
//	}
//	end = clock();
//	LoopCount = LOOPCOUNT;
//	cout << a->LastValue() << endl;
//	cout << LoopCount << "次BaseObject拷贝:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
//
//	start = clock();
//	while (LoopCount--)
//	{
//		a->LastValue();
//	}
//	end = clock();
//	LoopCount = LOOPCOUNT;
//	cout << a->LastValue() << endl;
//	cout << LoopCount << "次BaseObject计算:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
//
//}