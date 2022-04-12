#include "Damage.h"
namespace Advanced {
	using namespace Atom;
	using namespace Atom::Enum;
	Damage::~Damage() {
		if (otherDMG)delete otherDMG;
		delete rateValue;
		delete extraRateValue;
		delete fromBase;
		delete toBase;
	}
	Damage::Damage(Role* fromCur, Role* toCur) {
		DMGElementType = ElementType::Physical;
		otherDMG = nullptr;
		from = fromCur;
		to = toCur;
		rateValue = new BaseObject();
		extraRateValue = new Attr(DOUBLEONE, DOUBLEZERO, DOUBLEZERO);
		fromBase = new BaseObject(fromCur->GetLastData());
		toBase = new BaseObject(toCur->GetLastData());
	}
	void Damage::Modify(void(*fun)(Damage*))
	{
		(*fun)(this);
		if (otherDMG)otherDMG->Modify(fun);
	};
	void Damage::AddBase(Attr* value, AttrType type) {
		fromBase->Add(value, type);
		delete value;
	};
	void Damage::AddBase(Attr* value, AttrType type, ElementType elemnet) {
		fromBase->Add(value, type, elemnet);
		delete value;
	};
	void Damage::SetOtherDMG(Damage* data) {
		if (otherDMG) {
			otherDMG->SetOtherDMG(data);
		}
		else {
			otherDMG = data;
		};
	}
	void Damage::AddRate(Atom::Attr* data, AttrType type) {
		rateValue->Add(data, type);
	};
	void Damage::AddRate(Atom::Attr* data, AttrType type, ElementType elemnet) {
		rateValue->Add(data, type, elemnet);
	};
	void Damage::LastReasult() {
		auto FromRoleResult = fromBase->LastValue();
		auto ToRoleResult = fromBase->LastValue();
		double avgRate, maxRate, damageExtraRate, elementDef, defRate;
		avgRate = FromRoleResult->CritRate * (DOUBLEONE + FromRoleResult->CritDamage) + DOUBLEONE;
		maxRate = FromRoleResult->CritDamage + DOUBLEONE;
		damageExtraRate = extraRateValue->LastValue() + FromRoleResult->GetAttr(AttrType::ElementDmg, DMGElementType);
		elementDef = ToRoleResult->GetAttr(AttrType::ElementDef, DMGElementType);
		if (elementDef < 0) {
			defRate = DOUBLEONE - elementDef / 2;
		}
		else if (elementDef < .75) {
			defRate = DOUBLEONE - elementDef;
		}
		else {
			defRate = DOUBLEONE - 1 / (1 + 4 * elementDef);
		}
		double value = (fromBase->Product(rateValue)->GetSum()  /*//TODO:额外伤害*/) * damageExtraRate * defRate;
	}
}