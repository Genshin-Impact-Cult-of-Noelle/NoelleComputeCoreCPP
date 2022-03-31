#include "Role.h"
namespace Core {
	Role::Role(Attr** attrs, CharacterGender gender, CharacterGroup group, ElementType element, WeaponType weaponType) {
		Changed = false;
		rawBuffPool = new BuffPool();
		rawWeapon = new Weapon();
		rawBuffPool = new BuffPool();
		rawCharacter = new Character(attrs, gender, group, element, weaponType);

	};

}