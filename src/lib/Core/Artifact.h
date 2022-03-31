#pragma once
#include "BaseObject.h"
namespace Core {
#pragma region 圣遗物类

	class Artifact : BaseObject {
	public:
		Artifact(Attr**);

	};

#pragma endregion

#pragma region 圣遗物组类
	class ArtifactGroup : BaseObject {
	public:
		ArtifactGroup(Artifact**);
		void	(*update) (uint32_t);


	};
#pragma endregion
}

