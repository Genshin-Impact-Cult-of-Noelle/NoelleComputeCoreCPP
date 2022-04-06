#pragma once
#include "Atom.h"
namespace Atom {
	namespace Enum {

		enum class CharacterGender {
			//女
			Gril,
			//男
			Boy,
			//未知
			Unknow
		};
		enum class CharacterGroup {
			//提瓦特
			Tivat,
			//深渊
			Abyss,
			//未知
			Unknow
		};
		enum class WeaponType {
			//法器
			Catalyst,
			//弓箭
			Bow,
			//长枪
			Polearm,
			//单手剑
			Sword,
			//双手剑
			Claymore
		};
		enum class ElementType {
			//其他属性
			OtherElement,
			//水
			Water,
			//冰
			Ice,
			//火
			Fire,
			//电
			Electric,
			//草
			Grass,
			//岩
			Land,
			//风
			Wind,
			//物理
			Physical
		};

		enum class DamageType {
			//其他伤害
			OtherDamageType,
			//反应
			Mix,
			//普通攻击
			Normal,
			//重击
			Heavy,
			//下落
			Fall,
			//元素战技
			Skill,
			//元素爆发
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
