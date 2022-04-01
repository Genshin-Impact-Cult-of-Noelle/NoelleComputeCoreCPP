#pragma once
#include "Character.h"
#include "Buff.h"
#include "Weapon.h"
#include "Artifact.h"
#include "Damage.h"
namespace Core {
	class Damage;
	class Role {
	public:
		Role();
		Role(BaseObject*, CharacterGender, CharacterGroup, ElementType, WeaponType);
		//添加buff
		Role* AddBuff(Buff*);
		//设置武器
		Role* SetWeapon(Weapon*);
		//设置圣遗物
		Role* SetArtifact(Artifact*);
		//设置圣遗物套装
		Role* SetArtifactSet();
		//获取当前面板
		void GetLastData();
		//帧更新
		void Update();
		void Hit(Damage*);
		CharacterGroup group;
		void A(Role*, uint32_t);
		void E(Role*, uint32_t);
		void Q(Role*, uint32_t);

	private:
		//数据改变标识
		bool Changed;
		//內部圣遗物组
		ArtifactGroup* rawArtifactGroup;
		//内部角色数据
		Character* rawCharacter;
		//内部武器数据
		Weapon* rawWeapon;
		//内部Buff池
		BuffPool* rawBuffPool;
	};
}
