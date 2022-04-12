#pragma once
#include "Advanced.h"
namespace Advanced {
	class Role;
#pragma region 武器类
	/// <summary>
	/// 武器类
	/// </summary>
	class Weapon :public Atom::BaseObject {
	public:
		~Weapon();
		Weapon();
		virtual void Init(Role*) = 0;
		void SetRole(Role*);
		Role* user;
		//void (*skill)(Character*, Character*, u32);
	};
#pragma endregion
}


