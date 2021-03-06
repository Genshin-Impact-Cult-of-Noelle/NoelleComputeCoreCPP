#pragma once
#include "Advanced.h"
namespace Advanced {
	class Role;
	class Damage;
	class RoleGroup
	{
	public:
		RoleGroup(u32*);
		Role* nowRole;
		void DO(u32);
		void Update();
		RoleGroup* Join(Role*);
		RoleGroup* Swap(Role*);
		Atom::BaseObject* Compute();
		void ModifyDamageStart(Damage*);
	private:
		BuffPool* rawBuffPool;
		u32 joinCur = 0;
		u32* _frameCur;
		Role** roles;
	};
}


