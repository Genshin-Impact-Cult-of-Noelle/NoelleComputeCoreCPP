#include "Weapon.h"
using namespace Atom;
namespace Advanced {
	Weapon::Weapon(u8 extra) :BaseObject() {
		user = nullptr;
		buffPool = new BuffPool();
		baseResult = new BaseObject();
		extraLevel = extra;
	}
	Weapon::~Weapon() {
		//delete user;
		delete buffPool;
		delete baseResult;
	}
	void Weapon::SetRole(Role* role) {
		user = role;
		Init(role);
	}
	BaseObject* Weapon::Compute() {
		if (changed) {
			baseResult->Copy(this)->Add(buffPool->Compute());
		}
		return baseResult;
	}
	bool Weapon::Update(u32 frame) {
		MainUpdate(frame);
		buffPool->Update(frame);
		return changed;
	}
	void Weapon::ModifyDamage(Damage* dmg) {
		MainModifyDamage(dmg);
		buffPool->ModifyDamage(dmg);
	}
	void Weapon::AddBuff(Buff* buff) {
		changed = true;
		buffPool->PushBuff(buff);
	}
}