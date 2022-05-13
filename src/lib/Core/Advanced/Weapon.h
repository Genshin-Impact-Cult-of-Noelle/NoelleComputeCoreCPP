#pragma once
#include "Advanced.h"
namespace Advanced {
	class Role;
	class Buff;
	class BuffPool;
#pragma region 武器类
	/// <summary>
	/// 武器类
	/// </summary>
	class Weapon :public Atom::BaseObject {
	public:
		~Weapon();
		Weapon(u8);
		void SetRole(Role*);
		BaseObject* Compute();
		bool Update(u32);
		virtual void Init(Role*) = 0;
		void ModifyDamage(Damage* dmg);
		//void (*skill)(Character*, Character*, u32);

	protected:
		u8 extraLevel;
		Role* user;
		virtual void MainModifyDamage(Damage* dmg) = 0;
		virtual void MainUpdate(u32&) = 0;

		void AddBuff(Buff*);
	private:
		BuffPool* buffPool;
		BaseObject* baseResult;

	};
	namespace Default {
		class Weapon :public Advanced::Weapon {
		public:
			Weapon() :Advanced::Weapon(0) {
			}
			void Init(Role*) {};
			void MainModifyDamage(Damage*) {};
			void MainUpdate(u32&) {};
		};
	}
	//class  螭骨剑 :public Advanced::Weapon
	//{

	//public:
	//	螭骨剑() {
	//		static Atom::Attr* MainAttrValue = new Atom::Attr(510, 0, 0);
	//		static Atom::Attr* OtherAttrValue = new Atom::Attr(0.276, 0, 0);
	//		SetAttr(MainAttrValue, Atom::Enum::AttrType::Atk);
	//		SetAttr(OtherAttrValue, Atom::Enum::AttrType::CritRate);
	//	};
	//	~螭骨剑() {
	//	}
	//	void Init(Role*, u32) {
	//	}
	//	void MainModifyDamage(Damage*) {
	//	}
	//	u32 unDmgCount = 0;
	//	u8 BuffCount = 0;
	//	bool Update(u32) {
	//		static const u32 BuffCoolDown = 帧一秒 * 4;
	//		//if(user->isOn)
	//		if (true) {
	//			++unDmgCount %= BuffCoolDown;
	//			if (!unDmgCount) {
	//				if (BuffCount < 5) {
	//					//新建Buff注入Buff
	//				}
	//			}
	//		}
	//		return false;
	//	}

	//private:

	//};

#pragma endregion
}




