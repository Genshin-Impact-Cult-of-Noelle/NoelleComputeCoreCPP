#include "Role.h"
using namespace Atom;
namespace Advanced {
	Role::Role(u32* framCur) {
		_frameCur = framCur;
		changed = true;
		rawWeapon = new Default::Weapon();
		rawCharacter = nullptr;
		rawGroup = nullptr;
		rawBuffPool = new BuffPool();
		rawArtifactGroup = new ArtifactGroup();
		result = new BaseObject();
		skillLevel = new SkillLevel(0, 0, 0);
	};
	BaseObject* Role::GetLastData() {
		if (changed) {
			result->Clean();
			result
				->Add(rawWeapon->Compute())
				->Add(rawGroup->Compute())
				->Add(rawCharacter)
				->Add(rawArtifactGroup)
				->Add(rawBuffPool->Compute());
			changed = false;
		}
		return result;
	};
	Role* Role::AddBuff(Buff* data) {
		changed = true;
		rawBuffPool->PushBuff(data);
		return this;
	};
	Role* Role::SetWeapon(Weapon* data) {
		data->SetRole(this);
		return this;
	}
	Role* Role::SetArtifactSet(u32 SetID) {
		changed = true;
		//TODO:设置圣遗物套装
		return this;
	};
	void Role::Update() {
		u32 frame = GetFrameCur();
		if (rawBuffPool->Update(frame)) {
			changed = true;
		};
		if (rawWeapon != nullptr && rawWeapon->Update(frame)) {
			changed = true;
		};
	};
	void Role::SetGroup(RoleGroup* group) {
		rawGroup = group;
	};
	void Role::Hit(Damage* dmg) {
		rawGroup->ModifyDamageStart(dmg);
	};
	void Role::ModifyDamage(Damage* dmg) {
		rawBuffPool->ModifyDamage(dmg);
	};

}
