#include "Artifact.h"
namespace Core {
#pragma region 圣遗物类实现

	Artifact::Artifact(Attr** Data) {
		BaseObject::BaseObject(Data);

	}

#pragma endregion

#pragma region 圣遗物组类实现
	ArtifactGroup::ArtifactGroup() {

	}
	ArtifactGroup::~ArtifactGroup() {
		// delete this;
	}


#pragma endregion
}
