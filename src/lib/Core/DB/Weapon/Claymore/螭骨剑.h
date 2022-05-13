#pragma once
#include "../Weapon.h"
namespace DB {
	namespace WeaponConstruct {
		class 螭骨剑 :public Advanced::Weapon {
		public:
			螭骨剑(u8);
			void Init(Advanced::Role*);
			void MainModifyDamage(Advanced::Damage*);
			void MainUpdate(u32);
		};
	}
}
/*
class 螭骨剑 :public Advanced::Weapon {
		public:
			螭骨剑(u8 extra) :Advanced::Weapon(extra) {
				static Atom::Attr* MainAttrValue = new Atom::Attr(510, 0, 0);
				static Atom::Attr* OtherAttrValue = new Atom::Attr(0.276, 0, 0);
				SetAttr(MainAttrValue, Atom::Enum::AttrType::Atk);
				SetAttr(OtherAttrValue, Atom::Enum::AttrType::CritRate);
			}
			void Init(Role*, u32) {};
			void MainModifyDamage(Damage*) {};
			bool Update(u32) {
				static const u32 BuffCoolDown = 帧一秒 * 4;
				//if(user->isOn)
				if (true) {
					(++unDmgCount) %= BuffCoolDown;
					if (!unDmgCount) {
						if (BuffCount < 5) {
							//新建Buff注入Buff
							//AddBuff()
						}
					}
				}
				return false;
			};

		private:
			u32 unDmgCount = 0;
			u8 BuffCount = 0;
		};*/
