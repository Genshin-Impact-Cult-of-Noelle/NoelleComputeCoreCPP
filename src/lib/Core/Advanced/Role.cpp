#include "Role.h"
using namespace Atom;
namespace Advanced {
	Role::Role(u32* framCur) {
		_framCur = framCur;
		changed = true;
		rawWeapon = nullptr;
		rawCharacter = nullptr;
		rawBuffPool = new BuffPool();
		rawArtifactGroup = new ArtifactGroup();
		result = new BaseObject();
	}
	BaseObject* Role::GetLastData() {
		if (changed) {
			result->Clean();
			result
				//->Add(rawWeapon)
				//->Add(Group->BuffData())
				->Add(rawCharacter)
				->Add(rawArtifactGroup)
				->Add(rawBuffPool->Compute());
			changed = false;
		}
		return result;
	}
	Role* Role::AddBuff(Buff* data) {
		changed = true;
		rawBuffPool->PushBuff(data);
		return this;
	}
	Role* Role::SetArtifactSet(u32 SetID) {
		changed = true;
		//TODO:设置圣遗物套装
		return this;
	}

	void Role::Update(u32 frame) {
		if (rawBuffPool->Update(frame)) {
			changed = true;
		};

	}

}
