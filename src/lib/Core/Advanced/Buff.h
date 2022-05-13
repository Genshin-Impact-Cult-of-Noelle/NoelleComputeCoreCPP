#pragma once

#include "Advanced.h"
namespace Advanced {
	class Damage;
	class Role;
#pragma region 增益类
	/// 增益类
	/// 注意实现3个虚函数
	/// void Action(u32)
	/// void DamageModify(Damage*)
	/// void BuffUpdate(u32&)
	class Buff : public  Atom::BaseObject {
	public:
		Buff(Role*, Role*, u32 = 0);
		/// <summary>
		/// 操作指令
		/// </summary>
		/// <param name=""></param>
		virtual	void Action(u32) = 0;
		/// <summary>
		/// 伤害修饰
		/// </summary>
		/// <param name=""></param>
		virtual void DamageModify(Damage*) = 0;
		/// <summary>
		/// 帧刷新
		/// </summary>
		/// <param name=""></param>
		virtual void BuffUpdate(u32&) = 0;
		bool Update(u32&);
	protected:
		u32 deadFrame;
		Role* from;
		Role* to;
	};
	/// <summary>
	/// buff池子
	/// </summary>
	class BuffPool :public Atom::BaseObject {
	public:
		~BuffPool() {
			delete buffStart;
		};
		BuffPool();
		bool Update(u32&);
		void PushBuff(Buff*);
		void ModifyDamage(Damage*);
		Atom::BaseObject* Compute();
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