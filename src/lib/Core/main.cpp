#include "Core.h"
#include <ctime>
#include <iostream>
#define LOOPCOUNT 100000000;
using namespace std;
using namespace Core;
void testAttr();
void testBaseObject();
void main() {
	//char* m = new char[1];
	//Attr* base = new Attr(1, 1, 1);
	//BaseObject* c = new BaseObject();
	//BaseObject* d = new BaseObject();

	//Attr* other = new Attr(1, 1, 1);
	////other->SetData(1);
	//clock_t start = clock();
	//uint32_t key = (2 << 8) | 11;
	////cout << 1;
	//c->SetAttr(key, base);

	//for (size_t i = 0; i < 100000000; i++)
	//{
	//	//d->Add(c);
	//	d->Clean();

	//}
	////cout << 2;
	//double result = d->GetAttr(key)->LastValue();
	//clock_t end = clock();
	//cout << "1亿次3属性累加结果:" << result << "C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
	//
	testAttr();
	testBaseObject();
	system("pause");
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

	cout << LoopCount <<"次Attr相加:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
	start = clock();
	while (LoopCount--)
	{
		a->Clean();
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << LoopCount << "次Attr清空:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->Copy(b);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << LoopCount << "次Attr拷贝:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->LastValue();
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << LoopCount << "次Attr计算:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

}
void testBaseObject() {
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

	cout << LoopCount << "次BaseObject相加:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
	start = clock();
	while (LoopCount--)
	{
		a->Clean();
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << LoopCount << "次BaseObject清空:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->GetAttr(key);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << LoopCount << "次BaseObject获取属性:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

	start = clock();
	while (LoopCount--)
	{
		a->SetAttr(key, c);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << LoopCount << "次BaseObject设置属性:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
	
	start = clock();
	while (LoopCount--)
	{
		a->Copy(b);
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << LoopCount << "次BaseObject拷贝:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;
	
	start = clock();
	while (LoopCount--)
	{
		a->LastValue();
	}
	end = clock();
	LoopCount = LOOPCOUNT;
	cout << LoopCount << "次BaseObject计算:C++用时:" << ((double)(end - start) / 1000) << "秒" << endl;

}