#include "Role.h"
#include "Role.h"
namespace Advanced {

	Role::Role() {
		Changed = false;
		rawWeapon = nullptr;
		rawCharacter = nullptr;
		rawBuffPool = new BuffPool();
		rawArtifactGroup = new ArtifactGroup();
		result = new BaseObject::Result();
	}
	BaseObject::Result* Role::GetLastData() {
		if (Changed) {
			result->Clean();
			result->Merge(rawWeapon->LastValue())
				->Merge(rawCharacter->LastValue())
				->Merge(rawArtifactGroup->LastValue())
				->Merge(rawBuffPool->LastValue());
		}
		return result;
	}
	Role* Role::AddBuff(Buff* data) {
		rawBuffPool->PushBuff(data);
		return this;
	}
	Role* Role::SetArtifactSet(u32 SetID) {
		//TODO:设置圣遗物套装

		return this;
	}

	void Role::Update(u32 frame) {
		rawBuffPool->Update(frame);
	}
}