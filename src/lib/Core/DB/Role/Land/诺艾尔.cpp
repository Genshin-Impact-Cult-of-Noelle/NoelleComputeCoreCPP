#include "诺艾尔.h"


诺艾尔::诺艾尔() {

	BaseObject* baseData = new BaseObject();
	baseData->SetAttr((uint32_t)AttrType::Helath, new Attr(12071., 0., 0.));
	baseData->SetAttr((uint32_t)AttrType::Atk, new Attr(191., 0., 0.));
	baseData->SetAttr((uint32_t)AttrType::Def, new Attr(799., 0.3, 0.));
	baseData->SetAttr((uint32_t)AttrType::CritRate, new Attr(0.05, 0., 0.));
	baseData->SetAttr((uint32_t)AttrType::CritDamage, new Attr(0.5, 0., 0.));

	//Role::Role(baseData, CharacterGender::Gril, CharacterGroup::Tivat, ElementType::Land, WeaponType::Claymore);
	delete this->rawCharacter;
	this->rawCharacter = new Character(baseData, CharacterGender::Gril, CharacterGroup::Tivat, ElementType::Land, WeaponType::Claymore);
};
/// <summary>
/// 普攻第一段
/// </summary>
const double* A1 = new double[13]{};
const double* A2 = new double[13]{};
const double* A3 = new double[13]{};
const double* A4 = new double[13]{};
void 诺艾尔::A(Role* role, uint32_t cmd) {
	if (role->rawCharacter->group != rawCharacter->group) {
		try
		{
			Damage* readly = new Damage(this, role);
			switch ((cmd & 0xF00) >> 8)
			{
			case 0:
				switch ((cmd & 0xF0) >> 4)
				{
				case 0:
					//role->Hit(readly);
					role->Hit(readly);
					break;
				case 1:
					break;
				default:
					throw new exception("不受支持的指令");
				};
				break;
			case 1:
				break;
			case 2:
				break;
			default:
				throw new exception("不受支持的指令");
			}
		}
		catch (const std::exception& err)
		{
			throw err;
		}
	}

};
//一个继承Buff的类
class 大扫除 :public Buff {
public:
	大扫除(uint32_t endTime) :Buff(endTime) {
		//set
	};
	void  Action(uint32_t data) {

	};
	void DamageModify() {

	};
	//每帧刷新buff
	void BuffUpdate(uint32_t frame) {

	};


};

class 护心铠 :public Buff {
public:
	护心铠(uint32_t endTime) :Buff(endTime) {
		//set
	};
	void  Action(uint32_t data) {

	};
	void DamageModify() {

	};
};
