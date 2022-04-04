#include "Role.h"
namespace Core {

	Role::Role() {
		//cout << "无参构造" << this << endl;
		Changed = false;
		rawWeapon = new Weapon();
		rawBuffPool = new BuffPool();
		rawCharacter = new Character();
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
		else {
			return result;
		}
	}
}