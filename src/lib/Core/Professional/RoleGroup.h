#pragma once
#include "Professional.h"
using namespace Advanced;
namespace Professional {
	class RoleGroup
	{
	public:
		RoleGroup();
		Role* nowRole;
		Role** Role;
		void DO(u32);
	};
}


