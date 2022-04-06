#pragma once
#include "Atom.h"
namespace Atom {
	namespace Err {
		enum class Code {
			Skill
		};
		class Base {

		public:
			Code errCode;
			Base(Code code) {
				errCode = code;
			};
		};
		class SkillErr :public Base {
		public:
			SkillErr() :Base(Code::Skill) {

			}
		};
	}



}

