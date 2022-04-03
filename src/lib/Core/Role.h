#pragma once
#include "Character.h"
#include "Buff.h"
#include "Weapon.h"
#include "Artifact.h"
#include "Damage.h"
namespace Core {
	class Damage;
	/// <summary>
	/// 高级角色类、真实角色的下一层
	/// </summary>
	class Role {
	public:
		Role();
		/// <summary>
		/// 添加buff
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		Role* AddBuff(Buff*);
		/// <summary>
		/// 设置武器
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		Role* SetWeapon(Weapon*);
		/// <summary>
		/// 设置圣遗物
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		Role* SetArtifact(Artifact*);
		/// <summary>
		/// 设置圣遗物套装
		/// </summary>
		/// <returns></returns>
		Role* SetArtifactSet();
		/// <summary>
		/// 当前最终面板
		/// </summary>
		void GetLastData();
		/// <summary>
		/// 帧更新
		/// </summary>
		void Update();
		/// <summary>
		/// 受伤
		/// </summary>
		/// <param name="data">伤害实例</param>
		void Hit(Damage*);
		/// <summary>
		/// 普攻模组
		/// </summary>
		/// <param name="target">目标角色</param>
		/// <param name="Value">|1111(某类型)|1111(某段)|1111(技能等级)</param>
		void A(Role*, uint32_t);
		/// <summary>
		/// 元素战技模组
		/// </summary>
		/// <param name="target">目标角色</param>
		/// <param name="Value">|1111(某类型)|1111(某段)|1111(技能等级)</param>
		void E(Role*, uint32_t);
		/// <summary>
		/// 元素爆发模组
		/// </summary>
		/// <param name="target">目标角色</param>
		/// <param name="Value">|1111(某类型)|1111(某段)|1111(技能等级)</param>
		void Q(Role*, uint32_t);
		/// <summary>
		/// 改变标记
		/// </summary>		
		bool Changed;
		/// <summary>
		/// 圣遗物组
		/// </summary>
		ArtifactGroup* rawArtifactGroup;
		/// <summary>
		/// 角色基
		/// </summary>
		Character* rawCharacter;
		/// <summary>
		/// 武器钩
		/// </summary>
		Weapon* rawWeapon;
		/// <summary>
		/// buff池子
		/// </summary>
		BuffPool* rawBuffPool;
	};
}
