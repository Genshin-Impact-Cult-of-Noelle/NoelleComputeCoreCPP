#include "Attr.h"
namespace Atom {

#pragma region 基础属性

	/// <summary>
	/// 原子属性构造
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
	/// <summary>
	/// 原子属性构造
	/// </summary>
	/// <param name="data">拷贝构造</param>
	Attr::Attr(Attr* data) :Attr(data->base, data->rate, data->extra) {
	}
	/// <summary>
	/// 原子属性构造
	/// </summary>
	/// <param name="data">拷贝构造</param>
	Attr::Attr(Attr& data) : Attr(data.base, data.rate, data.extra) {
	}
	/// <summary>
	/// 原子属性构造(0,0,0)
	/// </summary>
	Attr::Attr() : Attr(DOUBLEZERO, DOUBLEZERO, DOUBLEZERO) {
	}
	Attr::~Attr() {
		// delete this;
	}
	/// <summary>
	/// 取回一个(0,0,0)
	/// </summary>
	/// <returns></returns>
	Attr* Attr::Zero() {
		return new Attr(DOUBLEZERO, DOUBLEZERO, DOUBLEZERO);
	}
	/// <summary>
	/// 相加 (1,2,3)+(4,5,6) = (5,7,9)
	/// </summary>
	/// <param name="data">加数</param>
	/// <returns></returns>
	Attr* Attr::Add(Attr* data) {
		base += data->base;
		rate += data->rate;
		extra += data->extra;
		changed = true;
		return this;
	}
	/// <summary>
	/// 乘法 (1,2,3) * (4,5,6) = ((1*(1+2)+3)*(4*(1+5)+6),0,0)
	/// </summary>
	/// <param name="data"></param>
	/// <returns></returns>
	Attr* Attr::Product(Attr* data) {

		base = LastValue() * data->LastValue();
		rate = 0;
		extra = 0;
		changed = true;
		return this;
	};
	/// <summary>
	/// 拷贝(值)
	/// </summary>
	/// <param name="data"></param>
	/// <returns></returns>
	Attr* Attr::Copy(Attr* data) {
		base = data->base;
		rate = data->rate;
		extra = data->extra;
		changed = true;
		return this;
	}
	/// <summary>
	/// 还原至（0,0,0）
	/// </summary>
	void Attr::Clean() {
		base = DOUBLEZERO;
		rate = DOUBLEZERO;
		extra = DOUBLEZERO;
		changed = true;
	}
	/// <summary>
	/// 原子计算(1,2,3) = (1*(1+2)+3) = 6
	/// </summary>
	/// <returns></returns>
	double Attr::LastValue() {
		if (changed) {
			LastValueCache = base * (DOUBLEONE + rate) + extra;
			changed = false;
		}
		return LastValueCache;
	}
#pragma endregion

}