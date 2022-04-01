#pragma once
#include "Attr.h"

namespace Core {

#pragma region 实例基类
	const char BaseObjectAttrSize = 26;
	class  BaseObject {
	public:
		class Result {
		public:
			Result();
			double Atk;
			double Def;
			double Helath;

			double ElementMaster;
			double CritRate;
			double CritDamage;
			double CureRate;
			double BeCureRate;
			double ChargeRate;
			double ColdDownRate;
			double ArmorRate;

			double EWaterDef;
			double EFireDef;
			double EIceDef;
			double EElectricDef;
			double EGrassDef;
			double ELandDef;
			double EWindDef;
			double EPhysicalDef;

			double EWaterDmg;
			double EFireDmg;
			double EIceDmg;
			double EElectricDmg;
			double EGrassDmg;
			double ELandDmg;
			double EWindDmg;
			double EPhysicalDmg;
		};
		//
		BaseObject(Attr** datas);
		BaseObject(BaseObject* datas);
		BaseObject();
		//整体累加
		BaseObject* Add(BaseObject*);
		//[key]属性相加
		BaseObject* Add(uint32_t, Attr*);
		//[key]属性相加
		BaseObject* Add(uint32_t, BaseObject*);
		//设置[key]属性
		BaseObject* SetAttr(uint32_t, Attr*);
		//取出[key]属性指针
		Attr* GetAttr(uint32_t);
		//从参数拷贝一个BaseObject
		BaseObject* Copy(BaseObject*);
		//取回结果指针
		Result* LastValue();
		//清空
		void Clean();
	private:
		Attr* GetAttrCur(uint32_t);
		bool changed;
		Result* result;
		Attr* Atk;
		Attr* Def;
		Attr* Helath;

		Attr* ElementMaster;
		Attr* CritRate;
		Attr* CritDamage;
		Attr* CureRate;
		Attr* BeCureRate;
		Attr* ChargeRate;
		Attr* ColdDownRate;
		Attr* ArmorRate;

		Attr* EWaterDef;
		Attr* EFireDef;
		Attr* EIceDef;
		Attr* EElectricDef;
		Attr* EGrassDef;
		Attr* ELandDef;
		Attr* EWindDef;
		Attr* EPhysicalDef;

		Attr* EWaterDmg;
		Attr* EFireDmg;
		Attr* EIceDmg;
		Attr* EElectricDmg;
		Attr* EGrassDmg;
		Attr* ELandDmg;
		Attr* EWindDmg;
		Attr* EPhysicalDmg;
	};
#pragma endregion

}