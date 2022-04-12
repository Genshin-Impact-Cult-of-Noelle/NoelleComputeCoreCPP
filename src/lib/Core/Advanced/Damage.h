#pragma once
#include "Advanced.h"
namespace Advanced {
	class Role;
	class Damage {
	public:
		struct DamageResult
		{
			~DamageResult() {
				delete other;
			};
			DamageResult(double min, double avg, double max, DamageResult* other = nullptr) {
				this->min = min;
				this->avg = avg;
				this->max = max;
				this->other = other;
			}
			double min;
			double avg;
			double max;
			DamageResult* other;
		};
		~Damage();
		Damage(Role*, Role*);
		void Modify(void (*fun)(Damage*));
		/// <summary>
		/// 根属性值相加
		/// </summary>
		/// <param name="value">base(倍率之前的值)、rate(不可用)、extra(额外值)</param>
		void AddBase(Atom::Attr*, Atom::Enum::AttrType);
		void AddBase(Atom::Attr*, Atom::Enum::AttrType, Atom::Enum::ElementType);
		/// <summary>
		/// 倍率乘区以及额外伤害
		/// </summary>
		/// <param name="value">base(技能倍率)、rate(基础倍率乘区@行秋4C)、extra(额外倍率)</param>
		void AddRate(Atom::Attr*, Atom::Enum::AttrType);
		void AddRate(Atom::Attr*, Atom::Enum::AttrType, Atom::Enum::ElementType);
		/// <summary>
		/// 增伤
		/// </summary>
		/// <param name="value">base(不可用)、rate(不可用)、extra(增伤相加)</param>
		void AddExtraRate(Atom::Attr*);
		void SetOtherDMG(Damage*);
		void LastReasult();
		Atom::Enum::ElementType DMGElementType;
		Role* from;
		Role* to;
		Damage* otherDMG;
		Atom::BaseObject* fromBase;
		Atom::BaseObject* toBase;
		Atom::BaseObject* rateValue;
		Atom::Attr* extraRateValue;
	};
}

