#pragma once
#include "Advanced.h"
using namespace Atom;
namespace Advanced {
#pragma region 圣遗物类

	class Artifact : public BaseObject {
	public:
		Artifact(Attr**);
	};

#pragma endregion

#pragma region 圣遗物组类
	class ArtifactGroup : public BaseObject {
	public:
		ArtifactGroup();
		~ArtifactGroup();
		//void	(*update) (u32);


	};
#pragma endregion
}

