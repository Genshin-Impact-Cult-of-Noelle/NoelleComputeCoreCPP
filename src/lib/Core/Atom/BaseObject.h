#pragma once
#include "Atom.h"
namespace Atom {
	namespace Enum {
		enum class ElementType;
		enum class AttrType;
	};
	class Attr;
#pragma region 实例基类
	//const char BaseObjectAttrSize = 26;
	class  BaseObject {
	public:
		Enum::ElementType NowAtkType;
		bool MustElement = false;
		static u32 CreatKey(Enum::AttrType);
		static u32 CreatKey(Enum::AttrType, Enum::ElementType);
		class Result {
		public:
			~Result();
			Result();
			void Clean();
			double GetSum();
			double GetAttr(u32);
			double GetAttr(Enum::AttrType);
			double GetAttr(Enum::AttrType, Enum::ElementType);
			//Result* Merge(Result*);
			bool changed;
			double Sum;
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

			double EHydroDef;
			double EPyroDef;
			double ECryoDef;
			double EElectroDef;
			double EDendroDef;
			double EGeoDef;
			double EAnemoDef;
			double EPhysicalDef;

			double EHydroDmg;
			double EPyroDmg;
			double ECryoDmg;
			double EElectroDmg;
			double EDendroDmg;
			double EGeoDmg;
			double EAnemoDmg;
			double EPhysicalDmg;

		};
		BaseObject(Attr** datas);
		BaseObject(BaseObject* datas);
		BaseObject();
		~BaseObject();
		BaseObject* Product(BaseObject*);
		BaseObject* Add(BaseObject*);
		BaseObject* Add(Attr*, Enum::AttrType);
		BaseObject* Add(Attr*, Enum::AttrType, Enum::ElementType);
		BaseObject* Add(BaseObject*, Enum::AttrType);
		BaseObject* Add(BaseObject*, Enum::AttrType, Enum::ElementType);
		BaseObject* SetAttr(Attr*, Enum::AttrType);
		double GetSum();

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