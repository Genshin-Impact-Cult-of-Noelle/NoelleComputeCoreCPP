#include "Weapon.h"
namespace Advanced {
	Weapon::Weapon() :BaseObject() {
		user = nullptr;
		//buffPool = new BuffPool();
	}
	Weapon::~Weapon() {
		//delete user;
		//delete buffPool;
	}
	void Weapon::SetRole(Role* role) {
		user = role;
		Init(role);
	}
}