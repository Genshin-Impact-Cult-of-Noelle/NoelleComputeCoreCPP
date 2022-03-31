#include "Core.h"
#include <ctime>
#include <iostream>
#define LOOPCOUNT 100000000;
using namespace std;
using namespace Core;
void testAttr();
void testBaseObject();
uint64_t FBNQ(uint64_t);
void main() {
	testAttr();
	testBaseObject();
	system("pause");
}
uint64_t FBNQ(uint64_t n) {
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