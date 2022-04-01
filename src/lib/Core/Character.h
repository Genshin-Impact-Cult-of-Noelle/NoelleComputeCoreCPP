#pragma once
#include "BaseObject.h"
namespace Core {



#pragma region 人物类

	class Character : public BaseObject {

	public:

		Character();
		Character(BaseObject*, CharacterGender, CharacterGroup, ElementType, WeaponType);

		//性别
		CharacterGender gender;

		//势力
		CharacterGroup group;

		//神之眼
		ElementType godEye;

		//武器类型
		WeaponType weaponType;

		//命之座
		//

		//技能等级
		//


	};

#pragma endregion


}