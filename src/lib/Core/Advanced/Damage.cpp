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
		otherDMG = nullptr;
		rateValue = new BaseObject();
		extraRateValue = new Attr(DOUBLEONE, DOUBLEZERO, DOUBLEZERO);
		from = fromCur;
		fromBase = new BaseObject(fromCur->GetLastData());
		to = toCur;
		toBase = new BaseObject(toCur->GetLastData());
	}
	Damage::Damage(Role* fromCur, Role* toCur, ElementType element) :Damage(fromCur, toCur) {
		DMGElementType = element;
	}
	Damage::Damage(Role* fromCur, Role* toCur, DamageType type) : Damage(fromCur, toCur) {
		DMGType = type;
	}
	Damage::Damage(Role* fromCur, Role* toCur, ElementType element, DamageType type) : Damage(fromCur, toCur) {
		DMGElementType = element;
		DMGType = type;
	}
	void Damage::Modify(void(*fun)(Damage*))
	{
		(*fun)(this);
		if (otherDMG)otherDMG->Modify(fun);
	};
	void Damage::AddBase(Attr* data, AttrType type) {
		fromBase->Add(data, type);
		delete data;
	};
	void Damage::AddBase(Attr* data, AttrType type, ElementType elemnet) {
		fromBase->Add(data, type, elemnet);
		delete data;
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
		delete data;
	};
	void Damage::AddRate(Atom::Attr* data, AttrType type, ElementType elemnet) {
		rateValue->Add(data, type, elemnet);
		delete data;
	};
	Damage::DamageResult* Damage::LastReasult() {
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
		auto x = fromBase->Product(rateValue)->GetSum();
		double value = (x  /*//TODO:额外伤害*/)*damageExtraRate * defRate;
		return new DamageResult(value, value, value, otherDMG ? otherDMG->LastReasult() : nullptr);
	}
	void Damage::AddExtraRate(Atom::Attr* data) {
		extraRateValue->Add(data);
	};
	void Damage::SetElement(Atom::Enum::ElementType element) {
		DMGElementType = element;
	};
	void Damage::SetDMGType(Atom::Enum::DamageType type) {
		DMGType = type;
	};
}