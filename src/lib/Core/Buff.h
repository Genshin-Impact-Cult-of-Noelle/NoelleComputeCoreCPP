#pragma once
#include "BaseObject.h"
namespace Core {
#pragma region 增益类
	/// <summary>
	/// 增益
	/// </summary>
	class Buff : public  BaseObject {
	public:
		Buff(Attr**, uint32_t);
		void (*Action)();
		void (*DamageModify)();
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