#include "Role.h"
namespace Core {
	Role::Role(BaseObject* roleData, CharacterGender gender, CharacterGroup group, ElementType element, WeaponType weaponType) {

		Changed = false;
		rawBuffPool = new BuffPool();
		rawWeapon = new Weapon();
		rawBuffPool = new BuffPool();
		rawCharacter = new Character(roleData, gender, group, element, weaponType);

	};
	Role::Role() {
		Changed = false;
		rawBuffPool = new BuffPool();
		rawWeapon = new Weapon();
		rawBuffPool = new BuffPool();
		rawCharacter = new Character();

	}

}