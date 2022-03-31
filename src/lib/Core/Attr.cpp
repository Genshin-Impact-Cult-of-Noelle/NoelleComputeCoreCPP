#include "Attr.h"
namespace Core {

#pragma region 基础属性
	//白字，额外倍率，额外值
	Attr::Attr(double Base, double Rate, double Extra) {
		base = Base;
		rate = Rate;
		extra = Extra;
	}
	Attr::Attr(Attr* data) {
		base = data->base;
		rate = data->rate;
		extra = data->extra;
	}
	Attr::Attr(Attr& data) {
		base = data.base;
		rate = data.rate;
		extra = data.extra;
	}
	Attr* Attr::Zero() {
		return new Attr(DOUBLEZERO, DOUBLEZERO, DOUBLEZERO);
	}
	Attr* Attr::Add(Attr* data) {
		base += data->base;
		rate += data->rate;
		extra += data->extra;
		return this;
	}
	Attr* Attr::Copy(Attr* data) {
		base = data->base;
		rate = data->rate;
		extra = data->extra;
		return this;
	}
	void Attr::Clean() {
		base = DOUBLEZERO;
		rate = DOUBLEZERO;
		extra = DOUBLEZERO;
	}
	double Attr::LastValue() {
		return base * (DOUBLEONE + rate) + extra;
	}
#pragma endregion

}