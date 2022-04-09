#pragma once
#include "Professional.h"
namespace Professional {
	class RoleGroup
	{
	public:
		RoleGroup();
		Advanced::Role* nowRole;
		Advanced::Role** Role;
		void DO(u32);
	};
}


