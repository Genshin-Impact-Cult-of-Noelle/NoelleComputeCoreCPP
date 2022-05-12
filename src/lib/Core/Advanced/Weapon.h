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
		virtual void ModifyDamage(Damage* dmg) = 0;
		virtual bool Update(u32) = 0;
		//void (*skill)(Character*, Character*, u32);
		//Advanced::BuffPool* buffPool;

	};
	namespace Default {
		class Weapon :public Advanced::Weapon {
			void Init(Role*) {};
			void ModifyDamage(Damage*) {};
			bool Update(u32) {
				return false;
			};
		};
	}
	class  螭骨剑 :public Advanced::Weapon
	{

	public:
		螭骨剑() {
			static const double ATK = 0;
		};
		~螭骨剑() {

		}
		void Init(Role*) {

		}
		void ModifyDamage(Damage*) {

		}
		bool Update() {

		}

	private:

	};

#pragma endregion
}




