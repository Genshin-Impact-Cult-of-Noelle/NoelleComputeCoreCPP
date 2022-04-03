#pragma once
#include "BaseObject.h"

namespace Core {
	class Role;
#pragma region 增益类


	/// 增益类
	/// 注意实现
	/// void Action(uint32_t)
	/// void DamageModify(Damage*)
	/// void BuffUpdate(uint32_t)
	class Buff : public  BaseObject {
	public:
		Buff(uint32_t);
		virtual	void Action(uint32_t) = 0;
		virtual void DamageModify(Damage*) = 0;
		virtual void BuffUpdate(uint32_t) = 0;
		bool Update(uint32_t);
	private:

	};
	/// <summary>
	/// buff池子
	/// </summary>
	class BuffPool {
	public:
		BuffPool();
		void Update(uint32_t);
		void PushBuff(Buff*);
		BaseObject* LastValue();
	private:
		BaseObject* result;
		bool changed;
		struct BuffNode {
			Buff* data;
			BuffNode* next;
		};
		BuffNode* buffStart;
	};
#pragma endregion
}