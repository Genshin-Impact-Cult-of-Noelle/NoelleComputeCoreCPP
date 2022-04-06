#pragma once
#include "Professional.h"
namespace Advanced {
	class Role;
	class RoleGroup
	{
	public:
		RoleGroup();
		Role* nowRole;
		Role** Role;
		void DO(u32);
	};
}


