#pragma once
#include "Enum.h"
using namespace std;
using namespace Core::Enum;
namespace Core {


#pragma region 枚举

#pragma endregion

#pragma region 原子属性
	const double DOUBLEONE = 1;
	const double DOUBLEZERO = 0;

	/*基础属性*/
	class Attr {



	public:
		Attr(double, double, double);
		Attr(Attr*);
		Attr(Attr&);
		static Attr* Zero();
		Attr* Add(Attr* data);
		Attr* Copy(Attr* data);
		void Clean();
		double LastValue();
	private:
		double base;
		double rate;
		double extra;
	};
#pragma endregion

}
