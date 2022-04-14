#include "Attr.h"
namespace Atom {

#pragma region 基础属性

	/// <summary>
	/// 原子属性
	/// </summary>
	/// <param name="Base">基础</param>
	/// <param name="Rate">倍率</param>
	/// <param name="Extra">额外</param>
	Attr::Attr(double Base, double Rate, double Extra) {
		changed = true;
		base = Base;
		rate = Rate;
		extra = Extra;
		changed = true;
		LastValue();
	}
	Attr::Attr(Attr* data) :Attr(data->base, data->rate, data->extra) {
	}
	Attr::Attr(Attr& data) : Attr(data.base, data.rate, data.extra) {
	}
	Attr::Attr() : Attr(DOUBLEZERO, DOUBLEZERO, DOUBLEZERO) {
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
		changed = true;
		return this;
	}
	Attr* Attr::Product(Attr* data) {

		base = LastValue() * data->LastValue();
		rate = 0;
		extra = 0;
		changed = true;
		return this;
	};

	Attr* Attr::Copy(Attr* data) {
		base = data->base;
		rate = data->rate;
		extra = data->extra;
		changed = true;
		return this;
	}
	void Attr::Clean() {
		base = DOUBLEZERO;
		rate = DOUBLEZERO;
		extra = DOUBLEZERO;
		changed = true;
	}
	double Attr::LastValue() {
		if (changed) {
			LastValueCache = base * (DOUBLEONE + rate) + extra;
			changed = false;
		}
		return LastValueCache;
	}
#pragma endregion

}