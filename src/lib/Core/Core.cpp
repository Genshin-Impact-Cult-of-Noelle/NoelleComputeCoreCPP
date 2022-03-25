#include "Core.h"
#include <iostream>
namespace Core {
#pragma region 基础属性
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

		/*Attrs = new Attr * [AttrsSize];
		for (uint8_t i = 0; i < AttrsSize; i++)
		{
			Attrs[i] = Attr::Zero();
		}*/
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
		//cout << 1;
		//for (uint8_t type = 1; type < (uint8_t)AttrType::ElementDef; type++)
		//{
		//	Attrs.insert(pair<uint32_t, Attr*>(type, Attr::Zero()));
		//}
		////cout << 2;
		//for (uint16_t element = 1; element < (uint16_t)Element::End; element <<= 1) {
		//	element <<= 8;
		//	Attrs.insert(pair<uint32_t, Attr*>(element | (uint16_t)AttrType::ElementDef, Attr::Zero()));
		//	Attrs.insert(pair<uint32_t, Attr*>(element | (uint16_t)AttrType::ElementDmg, Attr::Zero()));
		//	element >>= 8;
		//	//cout << element<<endl;
		//}


	}
	BaseObject* BaseObject::Add(BaseObject* data) {
		changed = true;
		/*Attr** other = data->Attrs;
		for (uint8_t i = 0; i < AttrsSize; i++)
		{
			Attrs[i]->Add(other[i]);
		}*/
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



		//map<uint32_t, Attr*>::iterator cur, end;
		//cur = Attrs.begin();
		//end = Attrs.end();
		////int x = 0;
		//while (cur != end)
		//{
		//	//cout << x++;
		//	cur->second->Add(data->Attrs[cur->first]);
		//	cur++;
		//}
		return this;

	}
	BaseObject* BaseObject::SetAttr(uint32_t key, Attr* data) {
		changed = true;

		uint8_t typeKey = key & 0xFF;
		/*
		if (typeKey >= 0 && typeKey < 11) {
			delete Attrs[typeKey];
			Attrs[typeKey] = data;
		}
		else if(typeKey<13) {

		}*/

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
		uint8_t element = (key & 0xFF00) >> 8;
		switch (element)
		{

		case Element::Water:
			isDef ? (EWaterDef->Copy(data)) : (EWaterDmg->Copy(data));
			return this;

		case Element::Fire:
			isDef ? (EFireDef->Copy(data)) : (EFireDmg->Copy(data));
			return this;

		case Element::Ice:
			isDef ? (EIceDef->Copy(data)) : (EIceDmg->Copy(data));
			return this;

		case Element::Electric:
			isDef ? (EElectricDef->Copy(data)) : (EElectricDmg->Copy(data));
			return this;

		case Element::Grass:
			isDef ? (EGrassDef->Copy(data)) : (EGrassDmg->Copy(data));
			return this;

		case Element::Land:
			isDef ? (ELandDef->Copy(data)) : (ELandDmg->Copy(data));
			return this;

		case Element::Wind:
			isDef ? (EWindDef->Copy(data)) : (EWindDmg->Copy(data));
			return this;

		case Element::Physical:
			isDef ? (EPhysicalDef->Copy(data)) : (EPhysicalDmg->Copy(data));
			return this;


		}
		changed = false;

		return this;
	}
	Attr* BaseObject::GetAttr(uint32_t key) {
		uint8_t typeKey = key & 0xFF;
		/*
		if (typeKey >= 0 && typeKey < 11) {
			delete Attrs[typeKey];
			Attrs[typeKey] = data;
		}
		else if(typeKey<13) {

		}*/

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
		uint8_t element = (key & 0xFF00) >> 8;
		switch (element)
		{

		case Element::Water:
			return isDef ? EWaterDef : EWaterDmg;

		case Element::Fire:
			return isDef ? EFireDef : EFireDmg;

		case Element::Ice:
			return isDef ? EIceDef : EIceDmg;

		case Element::Electric:
			return isDef ? EElectricDef : EElectricDmg;

		case Element::Grass:
			return isDef ? EGrassDef : EGrassDmg;

		case Element::Land:
			return isDef ? ELandDef : ELandDmg;

		case Element::Wind:
			return isDef ? EWindDef : EWindDmg;

		case Element::Physical:
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
