#pragma once
#include "BaseObject.h"
#include "Role.h"
namespace Core {
	class Role;
	class Damage {
	public:
		Damage(Role*, Role*);
		Role* from;
		Role* to;
	};
}

