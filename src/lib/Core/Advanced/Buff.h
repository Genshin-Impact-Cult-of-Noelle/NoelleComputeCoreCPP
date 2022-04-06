#pragma once
#include "Advanced.h"
using namespace Atom;
namespace Advanced {
	class Damage;
	class Role;
#pragma region 增益类
	/// 增益类
	/// 注意实现3个虚函数
	/// void Action(u32)
	/// void DamageModify(Damage*)
	/// void BuffUpdate(u32)
	class Buff : public  BaseObject {
	public:
		Buff(Role*, u32 = 0);
		virtual	void Action(u32) = 0;
		virtual void DamageModify(Damage*) = 0;
		virtual void BuffUpdate(u32) = 0;
		bool Update(u32);
	protected:
		u32 deadFrame;
		Role* from;
	};
	/// <summary>
	/// buff池子
	/// </summary>
	class BuffPool :public BaseObject {
	public:
		~BuffPool() {
			delete buffStart;
		};
		BuffPool();
		void Update(u32);
		void PushBuff(Buff*);
		BaseObject::Result* LastValue();
	private:
		struct BuffNode {
			BuffNode(Buff* buff) {
				data = buff;
				next = nullptr;
			};
			~BuffNode() {
				delete data;
				delete next;
			};
			Buff* data;
			BuffNode* next;
		};
		BuffNode* buffStart;
	};
#pragma endregion
}