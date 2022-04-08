#pragma once
#include "Atom.h"
namespace Atom {
	class Attr;
#pragma region 实例基类
	const char BaseObjectAttrSize = 26;
	class  BaseObject {
	public:
		class Result {
		public:
			~Result();
			Result();
			void Clean();
			Result* Merge(Result*);
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
		~BaseObject();
		BaseObject* Add(BaseObject*);
		BaseObject* Add(u32, Attr*);
		BaseObject* Add(u32, BaseObject*);
		BaseObject* SetAttr(u32, Attr*);
		Attr* GetAttr(u32);
		BaseObject* Copy(BaseObject*);
		Result* LastValue();
		void Clean();
	protected:
		//变更
		bool changed;
		//计算结果<u32,double>
		Result* result;
		//攻击力
		Attr* Atk;
		//防御力
		Attr* Def;
		//生命值
		Attr* Helath;
		//元素精通
		Attr* ElementMaster;
		//暴击率
		Attr* CritRate;
		//暴击伤害
		Attr* CritDamage;
		//治疗加成
		Attr* CureRate;
		//被治疗加成
		Attr* BeCureRate;
		//元素充能效率
		Attr* ChargeRate;
		//冷却缩减
		Attr* ColdDownRate;
		//护盾强效
		Attr* ArmorRate;

		Attr* EHydroDef;
		Attr* EPyroDef;
		Attr* ECryoDef;
		Attr* EElectroDef;
		Attr* EDendroDef;
		Attr* EGeoDef;
		Attr* EAnemoDef;
		Attr* EPhysicalDef;

		Attr* EHydroDmg;
		Attr* EPyroDmg;
		Attr* ECryoDmg;
		Attr* EElectroDmg;
		Attr* EDendroDmg;
		Attr* EGeoDmg;
		Attr* EAnemoDmg;
		Attr* EPhysicalDmg;
	};
#pragma endregion

}