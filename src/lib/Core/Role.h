#pragma once
#include "Character.h"
#include "Buff.h"
#include "Weapon.h"
#include "Artifact.h"
namespace Core {
	class Role {
	public:
		Role(Attr**, CharacterGender, CharacterGroup, ElementType, WeaponType);
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
	private:
		//数据改变标识
		bool Changed;

		//内部角色数据
		Character* rawCharacter;
		//内部武器数据
		Weapon* rawWeapon;
		//内部Buff池
		BuffPool* rawBuffPool;
	};
}
