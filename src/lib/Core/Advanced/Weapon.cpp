#include "Weapon.h"
namespace Advanced {
	Weapon::Weapon() :BaseObject() {
		user = nullptr;
	}
	Weapon::~Weapon() {
		delete user;
	}
	void Weapon::SetRole(Role* role) {
		user = role;
		Init(role);
	}
}