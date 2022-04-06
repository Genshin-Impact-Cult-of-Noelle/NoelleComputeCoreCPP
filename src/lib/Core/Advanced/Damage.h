#pragma once
#include "Advanced.h"
using namespace Atom;
namespace Advanced {
	class Role;
	class Damage {
	public:
		~Damage();
		Damage(Role*, Role*);
		Role* from;
		Role* to;
	};
}

