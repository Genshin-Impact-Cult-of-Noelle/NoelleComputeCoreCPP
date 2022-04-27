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
		delete result;
	}
	Damage::Damage(Damage* target) :Damage(target->from, target->to, target->DMGElementType, target->DMGType) {
		rateValue->Copy(target->rateValue);
	};

	Damage::Damage(Role* fromCur, Role* toCur) {
		otherDMG = nullptr;
		rateValue = new BaseObject();
		extraRateValue = new Attr(DOUBLEONE, DOUBLEZERO, DOUBLEZERO);
		from = fromCur;
		fromBase = new BaseObject();
		to = toCur;
		toBase = new BaseObject();
		DMGElementType = ElementType::OtherElement;
		DMGType = DamageType::OtherDamageType;
		result = nullptr;
	}
	Damage::Damage(Role* fromCur, Role* toCur, ElementType element, DamageType type) : Damage(fromCur, toCur) {
		DMGElementType = element;
		DMGType = type;
	}
	/*void Damage::Modify(void(*fun)(Damage*))
	{
		(*fun)(this);
		if (otherDMG)otherDMG->Modify(fun);
	};*/
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
	void Damage::Clone(u32 times) {
		auto cache = otherDMG;
		otherDMG = nullptr;
		while (--times)
		{
			SetOtherDMG(new Damage(this));
		}
		SetOtherDMG(cache);
	}
	Damage::DamageResult* Damage::LastReasult() {
		if (computed)return result;
		computed = true;
		fromBase->Add(from->GetLastData());
		toBase->Add(to->GetLastData());
		auto FromRoleResult = fromBase->LastValue();
		auto ToRoleResult = fromBase->LastValue();
		double avgRate, maxRate, damageExtraRate, elementDef, defRate, critRate, critDMG;
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
		critRate = FromRoleResult->CritRate;
		critDMG = FromRoleResult->CritDamage;
		double value = (fromBase->Product(rateValue)->GetSum()  /*//TODO:额外伤害*/) * damageExtraRate * defRate;
		result = new DamageResult(value, value * (DOUBLEONE + critDMG * critRate), value * (DOUBLEONE + critDMG), otherDMG ? otherDMG->LastReasult() : nullptr);
		return result;
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