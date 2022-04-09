#pragma once
#include "Advanced.h"
namespace Advanced {



#pragma region 人物类

	class Character : public Atom::BaseObject {

	public:

		Character();
		~Character();
		Character(Atom::BaseObject*, Atom::Enum::CharacterGender, Atom::Enum::CharacterGroup, Atom::Enum::ElementType, Atom::Enum::WeaponType);

		//性别
		Atom::Enum::CharacterGender gender;

		//势力
		Atom::Enum::CharacterGroup group;

		//神之眼
		Atom::Enum::ElementType godEye;

		//武器类型
		Atom::Enum::WeaponType weaponType;

		//命之座
		//

		//技能等级
		//


	};

#pragma endregion


}