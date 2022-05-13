import * as genshindb from "genshin-db"
import * as fs from "fs"
const RolePath = "..\\src\\lib\\Core\\DB\\Role\\"
const ElementMap: any = {}
const SkillDefName = ['A','E','Q','SP']
let RoleNames:any[] = [];
genshindb.characters('names', { matchCategories: true }).map(name => {
    let character = genshindb.characters(name)
    let characterC = genshindb.characters(name, { resultLanguage: genshindb.Languages.ChineseSimplified })
    let data = genshindb.talents(name, { resultLanguage: genshindb.Languages.ChineseSimplified })
    let star = genshindb.constellations(name, { resultLanguage: genshindb.Languages.ChineseSimplified })
    // console.log(character);

    if (data && character && star) {
        let { gender: 性别, element: 属性, weapontype: 武器, substat: 突破属性 } = character;
        let 技能表 = [data.combat1, data.combat2, data.combat3];
        
        let 被动表 = [data.passive1, data.passive2]
        data.passive3 && 被动表.push(data.passive3)
        data.passive4 && 被动表.push(data.passive4)
        data.combatsp && 被动表.push(data.combatsp)
        let stat = character.stats(90);
        let 命座 = [star.c1, star.c2, star.c3, star.c4, star.c5, star.c6]
        let 名字 = data.name;
        ElementMap[属性] = ""
        let H =
            `\uFEFF#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class ${名字} : public Advanced::Role
                {
                public:
                    ~${名字}();
                    ${名字}(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        `;
        let CPP =
            `\uFEFF#pragma once
        #include "${名字}.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO${名字}.cpp
        const double HP =  ${stat.hp || 0};
        const double ATK =  ${stat.attack || 0};
        const double DEF =  ${stat.defense || 0};
        //${characterC?.substat}
        const double OTHER = ${stat.specialized || 0};
        
        ${名字}::~${名字}() {
        }
        ${名字}::${名字}(u32* frameCur):Role(frameCur) {
            BaseObject* baseData = new BaseObject();
            static Attr
			* HelathAttr = new Attr(HP, DOUBLEZERO, DOUBLEZERO),
			* AtkAttr = new Attr(ATK, DOUBLEZERO, DOUBLEZERO),
			* DefAttr = new Attr(DEF, DOUBLEZERO, DOUBLEZERO),
			* CritRateAttr = new Attr(0.05, DOUBLEZERO, DOUBLEZERO),
			* CritDamageAttr = new Attr(0.5, DOUBLEZERO, DOUBLEZERO);
            baseData->SetAttr(HelathAttr,AttrType::Helath);
		    baseData->SetAttr(AtkAttr,AttrType::Atk);
		    baseData->SetAttr(DefAttr,AttrType::Def);
		    baseData->SetAttr(CritRateAttr,AttrType::CritRate);
		    baseData->SetAttr(CritDamageAttr,AttrType::CritDamage);
            this->rawCharacter = new Character(baseData, CharacterGender::${性别}, CharacterGroup::Tivat, ElementType::${属性}, WeaponType::${武器});
            delete baseData;
        };        

        /*
        ${被动表.map((被动, 序号) => {
                return `
        ****${序号 + 1}:${被动.name}
        ****************
        ${被动.info.split("\n").map(i => {
                    return `
            ${i}`
                }).join("").replace(/\*\*/g, "❤")} 

        ****************
        `
            }).join("\n")}
        */
        ${技能表.map((技能, 序号) => {
                return `
            /*******${技能.name}
             * ${技能.info.split("\n").map(info=>`
             * ${info}`).join("")}
             * ${技能.attributes.labels.map(label => {
                    return `
             * ${label}`
                }).join("")}
            */
            void ${名字}::${SkillDefName[序号]}(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{${
                        [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14].map(index=>{
                        return `
                        new const double[${Object.keys(技能.attributes.parameters).length}]{ ${Object.keys(技能.attributes.parameters).map((参数键, 参数序号) => {
                            return 技能.attributes.parameters[参数键][index]
                        }).join(",")
                    }}`
                    })}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };`}).join("\n\n")}
        /*****${star.name}
        ${命座.map((命, 序号) => {
                return `
            ***${序号 + 1}命***
            ${命.name}            
            ${命.effect.split("\n").map(i => {
                    return `${i}`
                }).join("").replace(/\*\*/g, "❤")}
            `
            }).join("")}
        */
         
        `
        let CPPPath = RolePath + `${属性}/${名字}.cpp`
        let HPath = RolePath + `${属性}/${名字}.h`
        // fs.writeFileSync(CPPPath, CPP)
        // fs.writeFileSync(HPath, H)
        fs.stat(CPPPath, (e, stat) => {
            if (stat && stat.isFile()) {
                console.log(!!fs.readFileSync(CPPPath).toString().match(/TODO:AUTO/),名字);
                
                if (!!fs.readFileSync(CPPPath).toString().match(/TODO:AUTO/)) {
                    fs.writeFileSync(CPPPath, CPP)
                    fs.writeFile(HPath, H, () => { })
                }

            }else{
                fs.writeFileSync(CPPPath, CPP)
                fs.writeFile(HPath, H, () => { })
            }
        })
        // console.log(CPPPath,HPath);       
        RoleNames.push({名字,属性})

    }

});
const RoleH = `\uFEFF#pragma once
#include "../DB.h"

namespace DB {
	namespace RoleConstruct {
        enum class RoleName
		{${RoleNames.map(i=>`
            ${i.名字},`).join("")}
		};
		Advanced::Role* Create(RoleName, u32*);
	}    
}
${RoleNames.map(i=>{
    return `#include "${i.属性}/${i.名字}.h"\n`
}).join("")}
`
const RoleCPP = 
`\uFEFF#pragma once
#include "Role.h"
using namespace Advanced;
Role* DB::RoleConstruct::Create(RoleName name, u32* frameCur) {
    switch (name)
    {${RoleNames.map(i=>`
    case RoleName::${i.名字}:
        return new ${i.名字}(frameCur);`).join("")}
    default:
        throw "";
    }
}
`
// console.log(RoleH, RolePath + "Role.h");


fs.writeFile(RolePath + "Role.h", RoleH, () => { })
fs.writeFile(RolePath + "Role.cpp", RoleCPP, () => { })
