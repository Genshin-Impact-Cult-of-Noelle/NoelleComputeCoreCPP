#pragma once
#include "Atom.h"
namespace Atom {


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
		Attr();
		~Attr();
		static Attr* Zero();
		Attr* Add(Attr*);
		Attr* Product(Attr*);
		Attr* Copy(Attr*);
		void Clean();
		double LastValue();

	private:

		bool changed;
		double LastValueCache;
		double base;
		double rate;
		double extra;
	};
#pragma endregion

}
