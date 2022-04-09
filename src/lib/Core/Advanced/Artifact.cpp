#include "Artifact.h"
using namespace Atom;
namespace Advanced {
#pragma region 圣遗物类实现

	Artifact::Artifact(Attr** Data) :BaseObject(Data) {

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
