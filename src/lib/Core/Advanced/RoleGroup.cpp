#include "RoleGroup.h"
#include <iostream>
namespace Advanced {
	using namespace Atom;
	RoleGroup::RoleGroup(u32* framCur) {
		rawBuffPool = new BuffPool();
		roles = new Role * [4]{
			nullptr,
			nullptr,
			nullptr,
			nullptr,
		};
		_frameCur = framCur;
		nowRole = roles[0];
	}
	RoleGroup* RoleGroup::Join(Role* role) {
		if (joinCur < 4) {
			roles[joinCur] = role;
			role->SetGroup(this);
			++joinCur;
		}
		return this;
	}
	RoleGroup* RoleGroup::Swap(Role* role) {
		u32 cur = 0;
		while (cur < 4)
		{
			if (roles[cur] == role) {
				nowRole = role;
				break;
			}
		}
		return this;
	}
	BaseObject* RoleGroup::Compute() {
		return rawBuffPool->Compute();
	};
	/// <summary>
	/// 开始伤害修饰
	/// </summary>
	/// <param name="dmg">伤害实例</param>
	void  RoleGroup::ModifyDamageStart(Damage* dmg) {
		u32 cur = 0;
		Damage* dmgCur = dmg;
		while (dmgCur)
		{
			cur = 0;
			while (roles[cur])
			{
				roles[cur]->ModifyDamage(dmgCur);
				++cur;
			}

			std::cout << dmgCur->LastReasult()->min << std::endl;
			dmgCur = dmgCur->otherDMG;
		}
	};

	void RoleGroup::Update() {
		++(*_frameCur);
		u32 cur = 0;
		while (roles[cur])
		{
			roles[cur]->Update();
			++cur;
		}
		rawBuffPool->Update(*_frameCur);
	};

}