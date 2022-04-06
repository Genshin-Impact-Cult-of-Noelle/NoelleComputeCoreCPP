#include "Buff.h"
namespace Advanced {
	Buff::Buff(Role* role, u32 startFrame) {
		from = role;
		deadFrame = startFrame;
	};
	bool  Buff::Update(u32 frame) {
		BuffUpdate(frame);
		return frame > deadFrame;
	}


#pragma region Buff池子

	BuffPool::BuffPool() :BaseObject() {
		buffStart = nullptr;
	};
	/// <summary>
	/// 刷新buff状态
	/// </summary>
	/// <param name="frame">帧位</param>
	void BuffPool::Update(u32 frame) {
		BuffNode* cur = buffStart;
		BuffNode* pre = nullptr;
		while (cur)
		{
			if (cur->data->Update(frame)) {
				pre = cur;
			}
			else if (cur->next) {
				if (pre) {
					pre->next = cur->next;
				}
				else {
					buffStart = cur->next;
				}
			}
			cur = cur->next;
		}
	};
	/// <summary>
	/// 取最终的BaseObject
	/// </summary>
	/// <returns></returns>
	BaseObject::Result* BuffPool::LastValue() {
		if (changed) {
			Clean();
			BuffNode* cur = buffStart;
			while (cur)
			{
				Add(cur->data);
				cur = cur->next;
			}
		}
		return BaseObject::LastValue();
	};
	/// <summary>
	/// 传入buff
	/// </summary>
	/// <param name="buff">buff指针</param>
	void BuffPool::PushBuff(Buff* buff) {
		changed = true;
		BuffNode* buffCur = new BuffNode(buff);
		buffCur->next = buffStart;
		buffStart = buffCur;
	}
#pragma endregion



}
