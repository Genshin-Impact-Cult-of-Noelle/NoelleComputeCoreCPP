#pragma once
#include "螭骨剑.h"
using namespace DB::WeaponConstruct;
using namespace Atom;
using namespace Atom::Enum;
using namespace Advanced;
using namespace Professional;
螭骨剑::螭骨剑(u8 extra) :Weapon(extra) {
	static Atom::Attr* MainAttrValue = new Atom::Attr(510, 0, 0);
	static Atom::Attr* OtherAttrValue = new Atom::Attr(0.276, 0, 0);
	SetAttr(MainAttrValue, Atom::Enum::AttrType::Atk);
	SetAttr(OtherAttrValue, Atom::Enum::AttrType::CritRate);
}
void 螭骨剑::Init(Role* role) {

}
void 螭骨剑::MainModifyDamage(Advanced::Damage*) {

};
void 螭骨剑::MainUpdate(u32 frame) {



};

//class 破浪 :public Buff {
//	void Action(u32 cmd) {
//
//	};
//	void DamageModify(Damage* dmg) {
//		if (dmg->to == )
//		{
//
//		}
//	};
//	void BuffUpdate(u32& frame) {
//
//	}
//};
