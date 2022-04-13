#include "BaseObject.h"
namespace Atom {
	using namespace Enum;
#pragma region 实例基类
	u32 BaseObject::CreatKey(AttrType type) {
		return (u32)type;
	}
	u32 BaseObject::CreatKey(AttrType type, ElementType element) {
		return ((u32)element << 8) | ((u32)type);
	}
	BaseObject::Result::~Result() {
	}
	BaseObject::Result::Result() {
		changed = true;
		Sum = DOUBLEZERO;
		Atk = DOUBLEZERO;
		Def = DOUBLEZERO;
		Helath = DOUBLEZERO;

		ElementMaster = DOUBLEZERO;
		CritRate = DOUBLEZERO;
		CritDamage = DOUBLEZERO;
		CureRate = DOUBLEZERO;
		BeCureRate = DOUBLEZERO;
		ChargeRate = DOUBLEZERO;
		ColdDownRate = DOUBLEZERO;
		ArmorRate = DOUBLEZERO;

		EHydroDef = DOUBLEZERO;
		EPyroDef = DOUBLEZERO;
		ECryoDef = DOUBLEZERO;
		EElectroDef = DOUBLEZERO;
		EDendroDef = DOUBLEZERO;
		EGeoDef = DOUBLEZERO;
		EAnemoDef = DOUBLEZERO;
		EPhysicalDef = DOUBLEZERO;

		EHydroDmg = DOUBLEZERO;
		EPyroDmg = DOUBLEZERO;
		ECryoDmg = DOUBLEZERO;
		EElectroDmg = DOUBLEZERO;
		EDendroDmg = DOUBLEZERO;
		EGeoDmg = DOUBLEZERO;
		EAnemoDmg = DOUBLEZERO;
		EPhysicalDmg = DOUBLEZERO;
	}
	void BaseObject::Result::Clean() {
		Atk = DOUBLEZERO;
		Def = DOUBLEZERO;
		Helath = DOUBLEZERO;

		ElementMaster = DOUBLEZERO;
		CritRate = DOUBLEZERO;
		CritDamage = DOUBLEZERO;
		CureRate = DOUBLEZERO;
		BeCureRate = DOUBLEZERO;
		ChargeRate = DOUBLEZERO;
		ColdDownRate = DOUBLEZERO;
		ArmorRate = DOUBLEZERO;

		EHydroDef = DOUBLEZERO;
		EPyroDef = DOUBLEZERO;
		ECryoDef = DOUBLEZERO;
		EElectroDef = DOUBLEZERO;
		EDendroDef = DOUBLEZERO;
		EGeoDef = DOUBLEZERO;
		EAnemoDef = DOUBLEZERO;
		EPhysicalDef = DOUBLEZERO;

		EHydroDmg = DOUBLEZERO;
		EPyroDmg = DOUBLEZERO;
		ECryoDmg = DOUBLEZERO;
		EElectroDmg = DOUBLEZERO;
		EDendroDmg = DOUBLEZERO;
		EGeoDmg = DOUBLEZERO;
		EAnemoDmg = DOUBLEZERO;
		EPhysicalDmg = DOUBLEZERO;
	}
	/*BaseObject::Result* BaseObject::Result::Merge(BaseObject::Result* data) {
		changed = true;
		Sum += data->Sum;
		Atk += data->Atk;
		Def += data->Def;
		Helath += data->Helath;
		ElementMaster += data->ElementMaster;
		CritRate += data->CritRate;
		CritDamage += data->CritDamage;
		CureRate += data->CureRate;
		BeCureRate += data->BeCureRate;
		ChargeRate += data->ChargeRate;
		ColdDownRate += data->ColdDownRate;
		ArmorRate += data->ArmorRate;

		EWaterDmg += data->EWaterDmg;
		EFireDmg += data->EFireDmg;
		EIceDmg += data->EIceDmg;
		EElectricDmg += data->EElectricDmg;
		EGrassDmg += data->EGrassDmg;
		ELandDmg += data->ELandDmg;
		EWindDmg += data->EWindDmg;
		EPhysicalDmg += data->EPhysicalDmg;

		EWaterDef += data->EWaterDef;
		EFireDef += data->EFireDef;
		EIceDef += data->EIceDef;
		EElectricDef += data->EElectricDef;
		EGrassDef += data->EGrassDef;
		ELandDef += data->ELandDef;
		EWindDef += data->EWindDef;
		EPhysicalDef += data->EPhysicalDef;

		return this;
	}*/
	BaseObject::BaseObject() {
		NowAtkType = ElementType::Physical;
		Atk = Attr::Zero();
		Def = Attr::Zero();
		Helath = Attr::Zero();

		ElementMaster = Attr::Zero();
		CritRate = Attr::Zero();
		CritDamage = Attr::Zero();
		CureRate = Attr::Zero();
		BeCureRate = Attr::Zero();
		ChargeRate = Attr::Zero();
		ColdDownRate = Attr::Zero();
		ArmorRate = Attr::Zero();

		EHydroDef = Attr::Zero();
		EPyroDef = Attr::Zero();
		ECryoDef = Attr::Zero();
		EElectroDef = Attr::Zero();
		EDendroDef = Attr::Zero();
		EGeoDef = Attr::Zero();
		EAnemoDef = Attr::Zero();
		EPhysicalDef = Attr::Zero();

		EHydroDmg = Attr::Zero();
		EPyroDmg = Attr::Zero();
		ECryoDmg = Attr::Zero();
		EElectroDmg = Attr::Zero();
		EDendroDmg = Attr::Zero();
		EGeoDmg = Attr::Zero();
		EAnemoDmg = Attr::Zero();
		EPhysicalDmg = Attr::Zero();

		result = new Result();
		changed = false;

	}
	BaseObject::~BaseObject() {
		delete Atk;
		delete Def;
		delete Helath;
		delete ElementMaster;
		delete CritRate;
		delete CritDamage;
		delete CureRate;
		delete BeCureRate;
		delete ChargeRate;
		delete ColdDownRate;
		delete ArmorRate;
		delete EHydroDef;
		delete EPyroDef;
		delete ECryoDef;
		delete EElectroDef;
		delete EDendroDef;
		delete EGeoDef;
		delete EAnemoDef;
		delete EPhysicalDef;
		delete EHydroDmg;
		delete EPyroDmg;
		delete ECryoDmg;
		delete EElectroDmg;
		delete EDendroDmg;
		delete EGeoDmg;
		delete EAnemoDmg;
		delete EPhysicalDmg;
		delete result;
	}
	BaseObject::BaseObject(Attr** datas) {
		NowAtkType = ElementType::Physical;
		Atk = datas[0];
		Def = datas[1];
		Helath = datas[2];
		ElementMaster = datas[3];
		CritRate = datas[4];
		CritDamage = datas[5];
		CureRate = datas[6];
		BeCureRate = datas[7];
		ChargeRate = datas[8];
		ColdDownRate = datas[9];
		ArmorRate = datas[10];
		EHydroDef = datas[11];
		EPyroDef = datas[12];
		ECryoDef = datas[13];
		EElectroDef = datas[14];
		EDendroDef = datas[15];
		EGeoDef = datas[16];
		EAnemoDef = datas[17];
		EPhysicalDef = datas[18];
		EHydroDmg = datas[19];
		EPyroDmg = datas[20];
		ECryoDmg = datas[21];
		EElectroDmg = datas[22];
		EDendroDmg = datas[23];
		EGeoDmg = datas[24];
		EAnemoDmg = datas[25];
		EPhysicalDmg = datas[26];
		result = new Result();
		changed = false;
	}
	BaseObject::BaseObject(BaseObject* datas) :BaseObject() {
		Copy(datas);
	}
	BaseObject* BaseObject::Product(BaseObject* data) {
		changed = true;
		Atk->Product(data->Atk);
		Def->Product(data->Def);
		Helath->Product(data->Helath);

		ElementMaster->Product(data->ElementMaster);
		CritRate->Product(data->CritRate);
		CritDamage->Product(data->CritDamage);
		CureRate->Product(data->CureRate);
		BeCureRate->Product(data->BeCureRate);
		ChargeRate->Product(data->ChargeRate);
		ColdDownRate->Product(data->ColdDownRate);
		ArmorRate->Product(data->ArmorRate);

		EHydroDef->Product(data->EHydroDef);
		EPyroDef->Product(data->EPyroDef);
		ECryoDef->Product(data->ECryoDef);
		EElectroDef->Product(data->EElectroDef);
		EDendroDef->Product(data->EDendroDef);
		EGeoDef->Product(data->EGeoDef);
		EAnemoDef->Product(data->EAnemoDef);
		EPhysicalDef->Product(data->EPhysicalDef);

		EHydroDmg->Product(data->EHydroDmg);
		EPyroDmg->Product(data->EPyroDmg);
		ECryoDmg->Product(data->ECryoDmg);
		EElectroDmg->Product(data->EElectroDmg);
		EDendroDmg->Product(data->EDendroDmg);
		EGeoDmg->Product(data->EGeoDmg);
		EAnemoDmg->Product(data->EAnemoDmg);
		EPhysicalDmg->Product(data->EPhysicalDmg);
		return this;
	};
	BaseObject* BaseObject::Add(BaseObject* data) {
		if (!data)return this;
		changed = true;
		if (data->MustElement) {
			NowAtkType = data->NowAtkType;
		}
		else if (data->NowAtkType != NowAtkType) {
			NowAtkType = data->NowAtkType < NowAtkType ? data->NowAtkType : NowAtkType;
			//火，冰，水 相互增幅

			//雷 向上剧变

			//风岩 （向上结晶扩散，相互不反应）
		}
		Atk->Add(data->Atk);
		Def->Add(data->Def);
		Helath->Add(data->Helath);

		ElementMaster->Add(data->ElementMaster);
		CritRate->Add(data->CritRate);
		CritDamage->Add(data->CritDamage);
		CureRate->Add(data->CureRate);
		BeCureRate->Add(data->BeCureRate);
		ChargeRate->Add(data->ChargeRate);
		ColdDownRate->Add(data->ColdDownRate);
		ArmorRate->Add(data->ArmorRate);

		EHydroDef->Add(data->EHydroDef);
		EPyroDef->Add(data->EPyroDef);
		ECryoDef->Add(data->ECryoDef);
		EElectroDef->Add(data->EElectroDef);
		EDendroDef->Add(data->EDendroDef);
		EGeoDef->Add(data->EGeoDef);
		EAnemoDef->Add(data->EAnemoDef);
		EPhysicalDef->Add(data->EPhysicalDef);

		EHydroDmg->Add(data->EHydroDmg);
		EPyroDmg->Add(data->EPyroDmg);
		ECryoDmg->Add(data->ECryoDmg);
		EElectroDmg->Add(data->EElectroDmg);
		EDendroDmg->Add(data->EDendroDmg);
		EGeoDmg->Add(data->EGeoDmg);
		EAnemoDmg->Add(data->EAnemoDmg);
		EPhysicalDmg->Add(data->EPhysicalDmg);
		return this;

	}
	BaseObject* BaseObject::Add(Attr* value, AttrType type) {
		changed = true;
		u32 key = CreatKey(type);
		GetAttr(key)->Add(value);
		return this;
	}
	BaseObject* BaseObject::Add(Attr* value, AttrType type, ElementType elemnet) {
		changed = true;
		u32 key = CreatKey(type, elemnet);
		GetAttr(key)->Add(value);
		return this;
	}

	BaseObject* BaseObject::Add(BaseObject* data, AttrType type) {
		changed = true;
		u32 key = CreatKey(type);
		GetAttr(key)->Add(data->GetAttr(key));
		return this;
	}
	BaseObject* BaseObject::Add(BaseObject* data, AttrType type, ElementType elemnet) {
		changed = true;
		u32 key = CreatKey(type, elemnet);
		GetAttr(key)->Add(data->GetAttr(key));
		return this;
	}

	BaseObject* BaseObject::SetAttr(Attr* value, AttrType type) {
		changed = true;
		u32 key = CreatKey(type);
		GetAttr(key)->Copy(value);
		return this;
	}
	Attr* BaseObject::GetAttr(u32 key) {
		AttrType  typeKey = AttrType(key & 0xFF);
		switch (typeKey)
		{
		case AttrType::Atk:
			return  Atk;
		case AttrType::Def:
			return  Def;
		case AttrType::Helath:
			return  Helath;
		case AttrType::ElementMaster:
			return  ElementMaster;
		case AttrType::CritRate:
			return  CritRate;
		case AttrType::CritDamage:
			return  CritDamage;
		case AttrType::CureRate:
			return  CureRate;
		case AttrType::BeCureRate:
			return  BeCureRate;
		case AttrType::ChargeRate:
			return  ChargeRate;
		case AttrType::ColdDownRate:
			return  ColdDownRate;
		case AttrType::ArmorRate:
			return  ArmorRate;
		}
		bool isDef = typeKey == AttrType::ElementDef;

		ElementType element = ElementType((key & 0xFF00) >> 8);


		switch (element)
		{
		case ElementType::Hydro:
			return isDef ? EHydroDef : EHydroDmg;
		case ElementType::Pyro:
			return isDef ? EPyroDef : EPyroDmg;
		case ElementType::Cryo:
			return isDef ? ECryoDef : ECryoDmg;
		case ElementType::Electro:
			return isDef ? EElectroDef : EElectroDmg;
		case ElementType::Dendro:
			return isDef ? EDendroDef : EDendroDmg;
		case ElementType::Geo:
			return isDef ? EGeoDef : EGeoDmg;
		case ElementType::Anemo:
			return isDef ? EAnemoDef : EAnemoDmg;
		case ElementType::Physical:
			return isDef ? EPhysicalDef : EPhysicalDmg;
		}
		throw;
	}
	void BaseObject::Clean() {
		changed = true;
		Atk->Clean();
		Def->Clean();
		Helath->Clean();
		ElementMaster->Clean();
		CritRate->Clean();
		CritDamage->Clean();
		CureRate->Clean();
		BeCureRate->Clean();
		ChargeRate->Clean();
		ColdDownRate->Clean();
		ArmorRate->Clean();
		EHydroDef->Clean();
		EHydroDmg->Clean();
		EPyroDef->Clean();
		EPyroDmg->Clean();
		ECryoDef->Clean();
		ECryoDmg->Clean();
		EElectroDef->Clean();
		EElectroDmg->Clean();
		EDendroDef->Clean();
		EDendroDmg->Clean();
		EGeoDef->Clean();
		EGeoDmg->Clean();
		EAnemoDef->Clean();
		EAnemoDmg->Clean();
		EPhysicalDef->Clean();
		EPhysicalDmg->Clean();
	}
	BaseObject* BaseObject::Copy(BaseObject* other) {
		changed = true;
		NowAtkType = other->NowAtkType;
		Atk->Copy(other->Atk);
		Def->Copy(other->Def);
		Helath->Copy(other->Helath);
		ElementMaster->Copy(other->ElementMaster);
		CritRate->Copy(other->CritRate);
		CritDamage->Copy(other->CritDamage);
		CureRate->Copy(other->CureRate);
		BeCureRate->Copy(other->BeCureRate);
		ChargeRate->Copy(other->ChargeRate);
		ColdDownRate->Copy(other->ColdDownRate);
		ArmorRate->Copy(other->ArmorRate);
		EHydroDef->Copy(other->EHydroDef);
		EHydroDmg->Copy(other->EHydroDmg);
		EPyroDef->Copy(other->EPyroDef);
		EPyroDmg->Copy(other->EPyroDmg);
		ECryoDef->Copy(other->ECryoDef);
		ECryoDmg->Copy(other->ECryoDmg);
		EElectroDef->Copy(other->EElectroDef);
		EElectroDmg->Copy(other->EElectroDmg);
		EDendroDef->Copy(other->EDendroDef);
		EDendroDmg->Copy(other->EDendroDmg);
		EGeoDef->Copy(other->EGeoDef);
		EGeoDmg->Copy(other->EGeoDmg);
		EAnemoDef->Copy(other->EAnemoDef);
		EAnemoDmg->Copy(other->EAnemoDmg);
		EPhysicalDef->Copy(other->EPhysicalDef);
		EPhysicalDmg->Copy(other->EPhysicalDmg);
		return this;
	}
	double BaseObject::Result::GetAttr(AttrType type) {
		return GetAttr(CreatKey(type));
	}
	double BaseObject::Result::GetAttr(AttrType type, ElementType element) {
		return GetAttr(CreatKey(type, element));
	}
	double BaseObject::Result::GetAttr(u32 key) {
		AttrType  typeKey = AttrType(key & 0xFF);
		switch (typeKey)
		{
		case AttrType::Atk:
			return  Atk;
		case AttrType::Def:
			return  Def;
		case AttrType::Helath:
			return  Helath;
		case AttrType::ElementMaster:
			return  ElementMaster;
		case AttrType::CritRate:
			return  CritRate;
		case AttrType::CritDamage:
			return  CritDamage;
		case AttrType::CureRate:
			return  CureRate;
		case AttrType::BeCureRate:
			return  BeCureRate;
		case AttrType::ChargeRate:
			return  ChargeRate;
		case AttrType::ColdDownRate:
			return  ColdDownRate;
		case AttrType::ArmorRate:
			return  ArmorRate;
		}
		bool isDef = typeKey == AttrType::ElementDef;

		ElementType element = ElementType((key & 0xFF00) >> 8);


		switch (element)
		{
		case ElementType::Hydro:
			return isDef ? EHydroDef : EHydroDmg;
		case ElementType::Pyro:
			return isDef ? EPyroDef : EPyroDmg;
		case ElementType::Cryo:
			return isDef ? ECryoDef : ECryoDmg;
		case ElementType::Electro:
			return isDef ? EElectroDef : EElectroDmg;
		case ElementType::Dendro:
			return isDef ? EDendroDef : EDendroDmg;
		case ElementType::Geo:
			return isDef ? EGeoDef : EGeoDmg;
		case ElementType::Anemo:
			return isDef ? EAnemoDef : EAnemoDmg;
		case ElementType::Physical:
			return isDef ? EPhysicalDef : EPhysicalDmg;
		}
		throw;

	};

	double BaseObject::Result::GetSum() {
		if (!changed)return Sum;
		Sum = 0.;
		Sum += Atk;
		Sum += Def;
		Sum += Helath;
		Sum += ElementMaster;
		Sum += CritRate;
		Sum += CritDamage;
		Sum += CureRate;
		Sum += BeCureRate;
		Sum += ChargeRate;
		Sum += ColdDownRate;
		Sum += ArmorRate;
		Sum += EHydroDef;
		Sum += EHydroDmg;
		Sum += EPyroDef;
		Sum += EPyroDmg;
		Sum += ECryoDef;
		Sum += ECryoDmg;
		Sum += EElectroDef;
		Sum += EElectroDmg;
		Sum += EDendroDef;
		Sum += EDendroDmg;
		Sum += EGeoDef;
		Sum += EGeoDmg;
		Sum += EAnemoDef;
		Sum += EAnemoDmg;
		Sum += EPhysicalDef;
		Sum += EPhysicalDmg;
		changed = false;
		return Sum;
	}
	BaseObject::Result* BaseObject::LastValue() {
		if (!changed) {
			return result;
		}
		result->changed = true;
		result->Atk = Atk->LastValue();
		result->Def = Def->LastValue();
		result->Helath = Helath->LastValue();
		result->ElementMaster = ElementMaster->LastValue();
		result->CritRate = CritRate->LastValue();
		result->CritDamage = CritDamage->LastValue();
		result->CureRate = CureRate->LastValue();
		result->BeCureRate = BeCureRate->LastValue();
		result->ChargeRate = ChargeRate->LastValue();
		result->ColdDownRate = ColdDownRate->LastValue();
		result->ArmorRate = ArmorRate->LastValue();
		result->EHydroDef = EHydroDef->LastValue();
		result->EHydroDmg = EHydroDmg->LastValue();
		result->EPyroDef = EPyroDef->LastValue();
		result->EPyroDmg = EPyroDmg->LastValue();
		result->ECryoDef = ECryoDef->LastValue();
		result->ECryoDmg = ECryoDmg->LastValue();
		result->EElectroDef = EElectroDef->LastValue();
		result->EElectroDmg = EElectroDmg->LastValue();
		result->EDendroDef = EDendroDef->LastValue();
		result->EDendroDmg = EDendroDmg->LastValue();
		result->EGeoDef = EGeoDef->LastValue();
		result->EGeoDmg = EGeoDmg->LastValue();
		result->EAnemoDef = EAnemoDef->LastValue();
		result->EAnemoDmg = EAnemoDmg->LastValue();
		result->EPhysicalDef = EPhysicalDef->LastValue();
		result->EPhysicalDmg = EPhysicalDmg->LastValue();
		changed = false;
		return result;
	}
	double BaseObject::GetSum() {
		return LastValue()->GetSum();
	};
#pragma endregion

}