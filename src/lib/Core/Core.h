#pragma once
#include <map>
//#include <string>
#include <vector>
using namespace std;


namespace Core {
#pragma region 原子属性
	const double DOUBLEONE = 1;
	const double DOUBLEZERO = 0;

	/*基础属性*/
	class Attr {



	public:
		//struct Result {
		//	//string histroy;
		//	double value;
		//};
		Attr(double, double, double);
		Attr(Attr*);
		Attr(Attr&);
		static Attr* Zero();
		Attr* Add(Attr* data);
		Attr* Copy(Attr* data);
		void Clean();
		//Result Last();
		//string LastHistroy();
		double LastValue();
	private:

		/*
		Attr* operator+(Attr&);
		Attr* operator*(uint32_t);
		Attr* operator+=(Attr&);
		*/
		//double* value;
		double base;
		double rate;
		double extra;
	};
#pragma endregion

	class Element {
	public:
		const static uint8_t Other = 0;
		const static uint8_t Water = 1 << 0;
		const static uint8_t Fire = 1 << 1;
		const static uint8_t Ice = 1 << 2;
		const static uint8_t Electric = 1 << 3;
		const static uint8_t Grass = 1 << 4;
		const static uint8_t Land = 1 << 5;
		const static uint8_t Wind = 1 << 6;
		const static uint8_t Physical = 1 << 7;
	};
	class DamageType {
		const static uint8_t	Mix = 0;
		const static uint8_t	Other = 0;
		const static uint8_t	Normal = 1;
		const static uint8_t	Heavy = Normal << 1;
		const static uint8_t	Fall = Normal << 2;
		const static uint8_t	Skill = Normal << 3;
		const static uint8_t	Burst = Normal << 4;
	};
#pragma region 实例基类
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
		//const static uint32_t AttrsSize = 27;
		class AttrType
		{
		public:
			const static uint8_t Atk = 0;
			const static uint8_t Def = 1;
			const static uint8_t Helath = 2;
			const static uint8_t ElementMaster = 3;
			const static uint8_t CritRate = 4;
			const static uint8_t CritDamage = 5;
			const static uint8_t CureRate = 6;
			const static uint8_t BeCureRate = 7;
			const static uint8_t ChargeRate = 8;
			const static uint8_t ColdDownRate = 9;
			const static uint8_t ArmorRate = 10;
			const static uint8_t ElementDef = 11;
			const static uint8_t ElementDmg = 12;
		};
		BaseObject();

		BaseObject* Add(BaseObject*);
		BaseObject* SetAttr(uint32_t, Attr*);
		Attr* GetAttr(uint32_t);
		BaseObject* Copy(BaseObject*);
		Result* LastValue();
		void Clean();
	private:
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


