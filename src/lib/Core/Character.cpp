#include "Character.h"
using namespace Core::Enum;
namespace Core {
	Character::Character(Attr** Data, CharacterGender Gender, CharacterGroup Group, ElementType Element, WeaponType Weapon) {
		BaseObject::BaseObject(Data);
		gender = Gender;
		group = Group;
		godEye = Element;
		weaponType = Weapon;
	}
}