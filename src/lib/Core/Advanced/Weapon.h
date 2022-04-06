#pragma once
#include "Advanced.h"
using namespace Atom;
namespace Advanced {
#pragma region 武器类
	/// <summary>
	/// 武器类
	/// </summary>
	class Weapon :public BaseObject {
	public:
		~Weapon();
		Weapon();
		virtual void init() = 0;
		void SetRole();
		//void (*skill)(Character*, Character*, u32);
	};
#pragma endregion
}


