#include "诺艾尔.h"


诺艾尔::~诺艾尔() {

}
诺艾尔::诺艾尔() {

	BaseObject* baseData = new BaseObject();
	static Attr
		* HelathAttr = new Attr(12071., 0., 0.),
		* AtkAttr = new Attr(191., 0., 0.),
		* DefAttr = new Attr(799., 0.3, 0.),
		* CritRateAttr = new Attr(0.05, 0., 0.),
		* CritDamageAttr = new Attr(0.5, 0., 0.);
	baseData->SetAttr((u32)AttrType::Helath, HelathAttr);
	baseData->SetAttr((u32)AttrType::Atk, AtkAttr);
	baseData->SetAttr((u32)AttrType::Def, DefAttr);
	baseData->SetAttr((u32)AttrType::CritRate, CritRateAttr);
	baseData->SetAttr((u32)AttrType::CritDamage, CritDamageAttr);
	this->rawCharacter = new Character(baseData, CharacterGender::Gril, CharacterGroup::Tivat, ElementType::Land, WeaponType::Claymore);
	delete baseData;
};
//p
const static double* A1 = new double[13]{};
const static double* A2 = new double[13]{};
const static double* A3 = new double[13]{};
const static double* A4 = new double[13]{};
/// <summary>
/// ww
/// </summary>
/// <param name="role"></param>
/// <param name="cmd"></param>
void 诺艾尔::A(Role* role, u8* cmd) {
	if (role->rawCharacter->group != rawCharacter->group) {
		Damage* readly = new Damage(this, role);
		switch (cmd[0])
		{
		case 0:
			switch (cmd[2])
			{
			case 0:
				//role->Hit(readly);
				//role->Hit(readly);
				break;
			case 1:
				break;
			default:
				throw new Err::SkillErr();
			};
			break;
		case 1:
			break;
		case 2:
			break;
		default:
			throw new Err::SkillErr();
		}
	}
};
void 诺艾尔::Q(Role* role, u8* cmd) {

}
void 诺艾尔::E(Role* role, u8* cmd) {

}
//一个继承Buff的类
class 大扫除 :public Buff {
public:
	大扫除(诺艾尔* role, u32 endTime) :Buff(role, endTime) {
		//set
	};
	void  Action(u32 data) {

	};
	void DamageModify() {

	};
	//每帧刷新buff
	void BuffUpdate(u32 frame) {

	};


};

class 护心铠 :public Buff {
public:
	护心铠(诺艾尔* role, u32 endTime) :Buff(role, endTime) {
		//set
	};
	void  Action(u32 data) {

	};
	void DamageModify() {

	};
};
