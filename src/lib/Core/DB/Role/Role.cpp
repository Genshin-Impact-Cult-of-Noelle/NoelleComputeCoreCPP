#pragma once
#include "Role.h"
Role* DB::RoleConstruct::Create(RoleName name) {
    switch (name)
    {
    case RoleName::阿贝多:
        return new 阿贝多();
    case RoleName::埃洛伊:
        return new 埃洛伊();
    case RoleName::安柏:
        return new 安柏();
    case RoleName::荒泷一斗:
        return new 荒泷一斗();
    case RoleName::芭芭拉:
        return new 芭芭拉();
    case RoleName::北斗:
        return new 北斗();
    case RoleName::班尼特:
        return new 班尼特();
    case RoleName::重云:
        return new 重云();
    case RoleName::迪卢克:
        return new 迪卢克();
    case RoleName::迪奥娜:
        return new 迪奥娜();
    case RoleName::优菈:
        return new 优菈();
    case RoleName::菲谢尔:
        return new 菲谢尔();
    case RoleName::甘雨:
        return new 甘雨();
    case RoleName::五郎:
        return new 五郎();
    case RoleName::胡桃:
        return new 胡桃();
    case RoleName::琴:
        return new 琴();
    case RoleName::枫原万叶:
        return new 枫原万叶();
    case RoleName::凯亚:
        return new 凯亚();
    case RoleName::神里绫华:
        return new 神里绫华();
    case RoleName::神里绫人:
        return new 神里绫人();
    case RoleName::刻晴:
        return new 刻晴();
    case RoleName::可莉:
        return new 可莉();
    case RoleName::九条裟罗:
        return new 九条裟罗();
    case RoleName::丽莎:
        return new 丽莎();
    case RoleName::莫娜:
        return new 莫娜();
    case RoleName::凝光:
        return new 凝光();
    case RoleName::诺艾尔:
        return new 诺艾尔();
    case RoleName::七七:
        return new 七七();
    case RoleName::雷电将军:
        return new 雷电将军();
    case RoleName::雷泽:
        return new 雷泽();
    case RoleName::罗莎莉亚:
        return new 罗莎莉亚();
    case RoleName::珊瑚宫心海:
        return new 珊瑚宫心海();
    case RoleName::早柚:
        return new 早柚();
    case RoleName::申鹤:
        return new 申鹤();
    case RoleName::砂糖:
        return new 砂糖();
    case RoleName::达达利亚:
        return new 达达利亚();
    case RoleName::托马:
        return new 托马();
    case RoleName::温迪:
        return new 温迪();
    case RoleName::香菱:
        return new 香菱();
    case RoleName::魈:
        return new 魈();
    case RoleName::行秋:
        return new 行秋();
    case RoleName::辛焱:
        return new 辛焱();
    case RoleName::八重神子:
        return new 八重神子();
    case RoleName::烟绯:
        return new 烟绯();
    case RoleName::宵宫:
        return new 宵宫();
    case RoleName::云堇:
        return new 云堇();
    case RoleName::钟离:
        return new 钟离();
    default:
        throw "";
    }
}
