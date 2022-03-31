#pragma once
#include "BaseObject.h"
namespace Core {
#pragma region 增益类
	//增益
	class Buff : BaseObject {
		Buff(Attr**, uint32_t);
		//角色指令监听
		void	(*Action)();
		//伤害修饰
		void	(*DamageModify)();
		//帧刷新
		void	(*update) (uint32_t, Buff);
	};
	//增益组
	class BuffPool {
		BuffPool(Buff*);
		void Update(uint32_t);
	};
#pragma endregion
}