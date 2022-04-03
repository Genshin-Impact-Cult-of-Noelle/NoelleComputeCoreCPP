#include "Role.h"
namespace Core {

	Role::Role() {
		cout << "无参构造" << this << endl;
		Changed = false;
		rawBuffPool = new BuffPool();
		rawWeapon = new Weapon();
		rawBuffPool = new BuffPool();
		rawCharacter = new Character();
		rawArtifactGroup = new ArtifactGroup();
	}

}