#pragma once
#include "Advanced.h"
using namespace Atom;
namespace Advanced {
	class Damage;
	class ArtifactGroup;
	class Artifact;
	class Weapon;
	class BuffPool;
	class Character;
	class Character;
	class Buff;
	/// <summary>
	/// 高级角色类、真实角色的下一层
	/// </summary>
	class Role {
	public:
		~Role() {
			delete rawWeapon;
			delete rawBuffPool;
			delete rawCharacter;
			delete rawArtifactGroup;
			delete result;
			// delete this;
		};
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
		Role* SetArtifactSet(u32);
		/// <summary>
		/// 当前最终面板
		/// </summary>
		BaseObject::Result* GetLastData();
		/// <summary>
		/// 帧更新
		/// </summary>
		void Update(u32);
		/// <summary>
		/// 受伤
		/// </summary>
		/// <param name="data">伤害实例</param>
		void Hit(Damage*);
		/// <summary>
		/// 普攻模组
		/// </summary>
		/// <param name="target">目标角色</param>
		/// <param name="Value">|[0](某类型)|[1](某段)|[2](技能等级)</param>
		virtual	void A(Role*, u32) = 0;
		/// <summary>
		/// 元素战技模组
		/// </summary>
		/// <param name="target">目标角色</param>
		/// <param name="Value">|[0](某类型)|[1](某段)|[2](技能等级)</param>

		virtual	void E(Role*, u32) = 0;
		/// <summary>
		/// 元素爆发模组
		/// </summary>
		/// <param name="target">目标角色</param>
		/// <param name="Value">|[0](某类型)|[1](某段)|[2](技能等级)</param>

		virtual	void Q(Role*, u32) = 0;

		/// <summary>
		/// 结果
		/// </summary>
		BaseObject::Result* result;
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
