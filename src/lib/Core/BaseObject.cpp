#include "BaseObject.h"
using namespace Core::Enum;
namespace Core {

#pragma region 实例基类
	BaseObject::Result::Result() {
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

		EWaterDef = DOUBLEZERO;
		EFireDef = DOUBLEZERO;
		EIceDef = DOUBLEZERO;
		EElectricDef = DOUBLEZERO;
		EGrassDef = DOUBLEZERO;
		ELandDef = DOUBLEZERO;
		EWindDef = DOUBLEZERO;
		EPhysicalDef = DOUBLEZERO;

		EWaterDmg = DOUBLEZERO;
		EFireDmg = DOUBLEZERO;
		EIceDmg = DOUBLEZERO;
		EElectricDmg = DOUBLEZERO;
		EGrassDmg = DOUBLEZERO;
		ELandDmg = DOUBLEZERO;
		EWindDmg = DOUBLEZERO;
		EPhysicalDmg = DOUBLEZERO;
	}
	BaseObject::BaseObject() {
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

		EWaterDef = Attr::Zero();
		EFireDef = Attr::Zero();
		EIceDef = Attr::Zero();
		EElectricDef = Attr::Zero();
		EGrassDef = Attr::Zero();
		ELandDef = Attr::Zero();
		EWindDef = Attr::Zero();
		EPhysicalDef = Attr::Zero();

		EWaterDmg = Attr::Zero();
		EFireDmg = Attr::Zero();
		EIceDmg = Attr::Zero();
		EElectricDmg = Attr::Zero();
		EGrassDmg = Attr::Zero();
		ELandDmg = Attr::Zero();
		EWindDmg = Attr::Zero();
		EPhysicalDmg = Attr::Zero();

		result = new Result();
		changed = false;

	}
	BaseObject::BaseObject(Attr** datas) {
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
		EWaterDef = datas[11];
		EFireDef = datas[12];
		EIceDef = datas[13];
		EElectricDef = datas[14];
		EGrassDef = datas[15];
		ELandDef = datas[16];
		EWindDef = datas[17];
		EPhysicalDef = datas[18];
		EWaterDmg = datas[19];
		EFireDmg = datas[20];
		EIceDmg = datas[21];
		EElectricDmg = datas[22];
		EGrassDmg = datas[23];
		ELandDmg = datas[24];
		EWindDmg = datas[25];
		EPhysicalDmg = datas[26];
		result = new Result();
		changed = false;
	}

	BaseObject* BaseObject::Add(BaseObject* data) {
		changed = true;
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

		EWaterDef->Add(data->EWaterDef);
		EFireDef->Add(data->EFireDef);
		EIceDef->Add(data->EIceDef);
		EElectricDef->Add(data->EElectricDef);
		EGrassDef->Add(data->EGrassDef);
		ELandDef->Add(data->ELandDef);
		EWindDef->Add(data->EWindDef);
		EPhysicalDef->Add(data->EPhysicalDef);

		EWaterDmg->Add(data->EWaterDmg);
		EFireDmg->Add(data->EFireDmg);
		EIceDmg->Add(data->EIceDmg);
		EElectricDmg->Add(data->EElectricDmg);
		EGrassDmg->Add(data->EGrassDmg);
		ELandDmg->Add(data->ELandDmg);
		EWindDmg->Add(data->EWindDmg);
		EPhysicalDmg->Add(data->EPhysicalDmg);
		return this;

	}

	BaseObject* BaseObject::Add(uint32_t key, Attr* data) {
		SetAttr(key, data);
		return this;
	}

	BaseObject* BaseObject::Add(uint32_t key, BaseObject* data) {
		SetAttr(key, data->GetAttr(key));
		return this;
	}
	BaseObject* BaseObject::SetAttr(uint32_t key, Attr* data) {
		changed = true;

		AttrType  typeKey = AttrType(key & 0xFF);

		switch (typeKey)
		{
		case AttrType::Atk:
			Atk->Copy(data);
			return this;
		case AttrType::Def:
			Def->Copy(data);
			return this;
		case AttrType::Helath:
			Helath->Copy(data);
			return this;
		case AttrType::ElementMaster:
			ElementMaster->Copy(data);
			return this;
		case AttrType::CritRate:
			CritRate->Copy(data);
			return this;
		case AttrType::CritDamage:
			CritDamage->Copy(data);
			return this;
		case AttrType::CureRate:
			CureRate->Copy(data);
			return this;
		case AttrType::BeCureRate:
			BeCureRate->Copy(data);
			return this;
		case AttrType::ChargeRate:
			ChargeRate->Copy(data);
			return this;
		case AttrType::ColdDownRate:
			ColdDownRate->Copy(data);
			return this;
		case AttrType::ArmorRate:
			ArmorRate->Copy(data);
			return this;
		}
		bool isDef = typeKey == AttrType::ElementDef;
		ElementType element = ElementType((key & 0xFF00) >> 8);
		switch (element)
		{
		case ElementType::Water:
			isDef ? (EWaterDef->Copy(data)) : (EWaterDmg->Copy(data));
			return this;
		case ElementType::Fire:
			isDef ? (EFireDef->Copy(data)) : (EFireDmg->Copy(data));
			return this;
		case ElementType::Ice:
			isDef ? (EIceDef->Copy(data)) : (EIceDmg->Copy(data));
			return this;
		case ElementType::Electric:
			isDef ? (EElectricDef->Copy(data)) : (EElectricDmg->Copy(data));
			return this;
		case ElementType::Grass:
			isDef ? (EGrassDef->Copy(data)) : (EGrassDmg->Copy(data));
			return this;
		case ElementType::Land:
			isDef ? (ELandDef->Copy(data)) : (ELandDmg->Copy(data));
			return this;
		case ElementType::Wind:
			isDef ? (EWindDef->Copy(data)) : (EWindDmg->Copy(data));
			return this;
		case ElementType::Physical:
			isDef ? (EPhysicalDef->Copy(data)) : (EPhysicalDmg->Copy(data));
			return this;
		}
		changed = false;

		return this;
	}
	Attr* BaseObject::GetAttr(uint32_t key) {
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
		case ElementType::Water:
			return isDef ? EWaterDef : EWaterDmg;
		case ElementType::Fire:
			return isDef ? EFireDef : EFireDmg;
		case ElementType::Ice:
			return isDef ? EIceDef : EIceDmg;
		case ElementType::Electric:
			return isDef ? EElectricDef : EElectricDmg;
		case ElementType::Grass:
			return isDef ? EGrassDef : EGrassDmg;
		case ElementType::Land:
			return isDef ? ELandDef : ELandDmg;
		case ElementType::Wind:
			return isDef ? EWindDef : EWindDmg;
		case ElementType::Physical:
			return isDef ? EPhysicalDef : EPhysicalDmg;
		}
		throw new exception("没有这个Key");
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
		EWaterDef->Clean();
		EWaterDmg->Clean();
		EFireDef->Clean();
		EFireDmg->Clean();
		EIceDef->Clean();
		EIceDmg->Clean();
		EElectricDef->Clean();
		EElectricDmg->Clean();
		EGrassDef->Clean();
		EGrassDmg->Clean();
		ELandDef->Clean();
		ELandDmg->Clean();
		EWindDef->Clean();
		EWindDmg->Clean();
		EPhysicalDef->Clean();
		EPhysicalDmg->Clean();
	}
	BaseObject* BaseObject::Copy(BaseObject* other) {
		changed = true;
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
		EWaterDef->Copy(other->EWaterDef);
		EWaterDmg->Copy(other->EWaterDmg);
		EFireDef->Copy(other->EFireDef);
		EFireDmg->Copy(other->EFireDmg);
		EIceDef->Copy(other->EIceDef);
		EIceDmg->Copy(other->EIceDmg);
		EElectricDef->Copy(other->EElectricDef);
		EElectricDmg->Copy(other->EElectricDmg);
		EGrassDef->Copy(other->EGrassDef);
		EGrassDmg->Copy(other->EGrassDmg);
		ELandDef->Copy(other->ELandDef);
		ELandDmg->Copy(other->ELandDmg);
		EWindDef->Copy(other->EWindDef);
		EWindDmg->Copy(other->EWindDmg);
		EPhysicalDef->Copy(other->EPhysicalDef);
		EPhysicalDmg->Copy(other->EPhysicalDmg);
		return this;
	}
	BaseObject::Result* BaseObject::LastValue() {
		if (!changed) {
			return result;
		}
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
		result->EWaterDef = EWaterDef->LastValue();
		result->EWaterDmg = EWaterDmg->LastValue();
		result->EFireDef = EFireDef->LastValue();
		result->EFireDmg = EFireDmg->LastValue();
		result->EIceDef = EIceDef->LastValue();
		result->EIceDmg = EIceDmg->LastValue();
		result->EElectricDef = EElectricDef->LastValue();
		result->EElectricDmg = EElectricDmg->LastValue();
		result->EGrassDef = EGrassDef->LastValue();
		result->EGrassDmg = EGrassDmg->LastValue();
		result->ELandDef = ELandDef->LastValue();
		result->ELandDmg = ELandDmg->LastValue();
		result->EWindDef = EWindDef->LastValue();
		result->EWindDmg = EWindDmg->LastValue();
		result->EPhysicalDef = EPhysicalDef->LastValue();
		result->EPhysicalDmg = EPhysicalDmg->LastValue();
		changed = false;
		return result;
	}
#pragma endregion

}