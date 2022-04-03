#include "Buff.h"
namespace Core {
	Buff::Buff(uint32_t startFrame) {
	};
	bool  Buff::Update(uint32_t frame) {

	}


#pragma region Buff池子

	BuffPool::BuffPool() {
		buffStart = nullptr;
		changed = false;
		result = new BaseObject();

	};
	/// <summary>
	/// 刷新buff状态
	/// </summary>
	/// <param name="frame">帧位</param>
	void BuffPool::Update(uint32_t frame) {
		BuffNode* cur = buffStart;
		BuffNode* pre = buffStart;
		while (cur)
		{
			if (!cur->data->Update(frame)) {
				if (cur->next) {
					pre->next = cur->next;
				}
				cur = cur->next;
				pre->next = cur;
			}
			else {
				pre = cur;
				cur = cur->next;
			}

		}
	};
	/// <summary>
	/// 取最终的BaseObject
	/// </summary>
	/// <returns></returns>
	BaseObject* BuffPool::LastValue() {
		if (changed) {
			result->Clean();
			BuffNode* cur = buffStart;
			while (cur)
			{
				result->Add(cur->data);
				cur = cur->next;
			}
		}
		return result;
	};
	/// <summary>
	/// 传入buff
	/// </summary>
	/// <param name="buff">buff指针</param>
	void BuffPool::PushBuff(Buff* buff) {
		changed = true;
		BuffNode* buffCur = new BuffNode();
		buffCur->data = buff;
		buffCur->next = buffStart;
		buffStart = buffCur;
	}

#pragma endregion



}
