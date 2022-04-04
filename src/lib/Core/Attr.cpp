#include "Attr.h"
namespace Core {

#pragma region 基础属性

	/// <summary>
	/// 原子属性
	/// </summary>
	/// <param name="Base">基础</param>
	/// <param name="Rate">倍率</param>
	/// <param name="Extra">额外</param>
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
	Attr::Attr() {
		base = 0;
		rate = 0;
		extra = 0;
	}
	Attr::~Attr() {
		// delete this;
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