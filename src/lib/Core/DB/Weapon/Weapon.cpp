#pragma once
#include "Weapon.h"
using namespace Advanced;
Role* DB::RoleConstruct::Create(RoleName name, u32* frameCur) {
	switch (name)
	{
	case RoleName::阿贝多:
		return new 阿贝多(frameCur);
	case RoleName::埃洛伊:
		return new 埃洛伊(frameCur);
	case RoleName::安柏:
		return new 安柏(frameCur);
	case RoleName::荒泷一斗:
		return new 荒泷一斗(frameCur);
	case RoleName::芭芭拉:
		return new 芭芭拉(frameCur);
	case RoleName::北斗:
		return new 北斗(frameCur);
	case RoleName::班尼特:
		return new 班尼特(frameCur);
	case RoleName::重云:
		return new 重云(frameCur);
	case RoleName::迪卢克:
		return new 迪卢克(frameCur);
	case RoleName::迪奥娜:
		return new 迪奥娜(frameCur);
	case RoleName::优菈:
		return new 优菈(frameCur);
	case RoleName::菲谢尔:
		return new 菲谢尔(frameCur);
	case RoleName::甘雨:
		return new 甘雨(frameCur);
	case RoleName::五郎:
		return new 五郎(frameCur);
	case RoleName::胡桃:
		return new 胡桃(frameCur);
	case RoleName::琴:
		return new 琴(frameCur);
	case RoleName::枫原万叶:
		return new 枫原万叶(frameCur);
	case RoleName::凯亚:
		return new 凯亚(frameCur);
	case RoleName::神里绫华:
		return new 神里绫华(frameCur);
	case RoleName::神里绫人:
		return new 神里绫人(frameCur);
	case RoleName::刻晴:
		return new 刻晴(frameCur);
	case RoleName::可莉:
		return new 可莉(frameCur);
	case RoleName::九条裟罗:
		return new 九条裟罗(frameCur);
	case RoleName::丽莎:
		return new 丽莎(frameCur);
	case RoleName::莫娜:
		return new 莫娜(frameCur);
	case RoleName::凝光:
		return new 凝光(frameCur);
	case RoleName::诺艾尔:
		return new 诺艾尔(frameCur);
	case RoleName::七七:
		return new 七七(frameCur);
	case RoleName::雷电将军:
		return new 雷电将军(frameCur);
	case RoleName::雷泽:
		return new 雷泽(frameCur);
	case RoleName::罗莎莉亚:
		return new 罗莎莉亚(frameCur);
	case RoleName::珊瑚宫心海:
		return new 珊瑚宫心海(frameCur);
	case RoleName::早柚:
		return new 早柚(frameCur);
	case RoleName::申鹤:
		return new 申鹤(frameCur);
	case RoleName::砂糖:
		return new 砂糖(frameCur);
	case RoleName::达达利亚:
		return new 达达利亚(frameCur);
	case RoleName::托马:
		return new 托马(frameCur);
	case RoleName::温迪:
		return new 温迪(frameCur);
	case RoleName::香菱:
		return new 香菱(frameCur);
	case RoleName::魈:
		return new 魈(frameCur);
	case RoleName::行秋:
		return new 行秋(frameCur);
	case RoleName::辛焱:
		return new 辛焱(frameCur);
	case RoleName::八重神子:
		return new 八重神子(frameCur);
	case RoleName::烟绯:
		return new 烟绯(frameCur);
	case RoleName::宵宫:
		return new 宵宫(frameCur);
	case RoleName::云堇:
		return new 云堇(frameCur);
	case RoleName::钟离:
		return new 钟离(frameCur);
	default:
		throw "";
	}
}
