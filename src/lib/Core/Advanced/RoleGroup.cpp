#include "RoleGroup.h"
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
	void  RoleGroup::ModifyDamageStart(Damage* dmg) {
		auto cur = 0;
		while (roles[cur])
		{
			roles[cur]->ModifyDamage(dmg);
			++cur;
		}
		std::cout << dmg->LastReasult()->avg << std::endl;
		if (dmg->otherDMG) {
			std::cout << dmg->LastReasult()->avg << std::endl;
		}
	};

	void RoleGroup::Update() {
		++(*_frameCur);
		u32 cur = 0;
		while (cur < 4)
		{
			roles[cur]->Update();
		}
		rawBuffPool->Update(*_frameCur);
	};

}