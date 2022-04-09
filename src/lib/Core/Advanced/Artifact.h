#pragma once
#include "Advanced.h"
namespace Advanced {
#pragma region 圣遗物类

	class Artifact : public Atom::BaseObject {
	public:
		Artifact(Atom::Attr**);
	};

#pragma endregion

#pragma region 圣遗物组类
	class ArtifactGroup : public Atom::BaseObject {
	public:
		ArtifactGroup();
		~ArtifactGroup();
		//void	(*update) (u32);


	};
#pragma endregion
}

