#pragma once
#include <iostream>
namespace Core {
	namespace Enum {

		enum class CharacterGender {
			Gril,
			Boy,
			Unknow
		};
		enum class CharacterGroup {
			Tivat,
			Byss,
			Unknow
		};
		enum class WeaponType {
			Catalyst,
			Bow,
			Polearm,
			Sword,
			Claymore
		};
		enum class ElementType {
			OtherElement,
			Water,
			Ice,
			Fire,
			Electric,
			Grass,
			Land,
			Wind,
			Physical
		};

		enum class DamageType {
			Mix,
			OtherDamageType = 0,
			Normal,
			Heavy,
			Fall,
			Skill,
			Burst,
		};


		enum class AttrType {
			//攻击力
			Atk,
			//防御力
			Def,
			//生命值
			Helath,
			//元素精通
			ElementMaster,
			//暴击率
			CritRate,
			//暴击伤害
			CritDamage,
			//治疗率
			CureRate,
			//被治疗率
			BeCureRate,
			//充能效率
			ChargeRate,
			//冷却缩减
			ColdDownRate,
			//护盾
			ArmorRate,
			//属性防御，属性枚举左移8与运算得键
			ElementDef,
			//属性攻击，属性枚举左移8与运算得键
			ElementDmg
		};
	}
}
