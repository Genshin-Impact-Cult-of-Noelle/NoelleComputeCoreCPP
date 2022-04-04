#include "Character.h"
using namespace Core::Enum;
namespace Core {
	Character::Character(BaseObject* Data, CharacterGender Gender, CharacterGroup Group, ElementType Element, WeaponType Weapon) {
		Copy(Data);
		gender = Gender;
		group = Group;
		godEye = Element;
		weaponType = Weapon;
	}
	Character::Character() :BaseObject() {
		gender = CharacterGender::Unknow;
		group = CharacterGroup::Unknow;
		godEye = ElementType::OtherElement;
		weaponType = WeaponType::Sword;
	}
	Character::~Character() {
		// delete this;
	}
}