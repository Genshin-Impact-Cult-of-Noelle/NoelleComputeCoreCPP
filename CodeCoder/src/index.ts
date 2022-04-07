import * as genshindb from "genshin-db"
import * as fs from "fs"
const RolePath = "E:\\work\\noelleCoreCPP\\src\\lib\\Core\\DB\\Role\\"
const ElementMap: any = {}
genshindb.characters('names', { matchCategories: true }).map(name => {
    let character = genshindb.characters(name)
    let characterC = genshindb.characters(name, { resultLanguage: genshindb.Languages.ChineseSimplified })
    let data = genshindb.talents(name, { resultLanguage: genshindb.Languages.ChineseSimplified })
    let star = genshindb.constellations(name, { resultLanguage: genshindb.Languages.ChineseSimplified })
    // console.log(character);

    if (data && character && star) {
        let { gender: 性别, element: 属性, weapontype: 武器, substat: 突破属性 } = character;
        let 技能表 = [data.combat1, data.combat2, data.combat3];
        data.combatsp && 技能表.push(data.combatsp)
        let 被动表 = [data.passive1, data.passive2]
        data.passive3 && 被动表.push(data.passive3)
        data.passive4 && 被动表.push(data.passive4)
        let stat = character.stats(90);
        let 命座 = [star.c1, star.c2, star.c3, star.c4, star.c5, star.c6]
        let 名字 = data.name;
        ElementMap[属性] = ""
        let H =
            `\uFEFF
        #pragma once
        #include "../Role.h"
        using namespace Professional;
        namespace  ${属性}{
        class ${名字} : public Role
        {
        public:
            ~${名字}();
            ${名字}();
            void A(Role*, u8*);
            void E(Role*, u8*);
            void Q(Role*, u8*);
        private:
        
        };
        }
        `;
        let CPP =
            `\uFEFF
        #include "${名字}.h"
        using namespace Role;
        //TODO:AUTO${名字}.cpp
        const double HP =  ${stat.hp || 0};
        const double ATK =  ${stat.attack || 0};
        const double DEF =  ${stat.defense || 0};
        //${characterC?.substat}
        const double OTHER = ${stat.specialized || 0};
        
        namespace ${属性}{
        ${名字}::~${名字}() {
        }
        ${名字}::${名字}() {
            BaseObject* baseData = new BaseObject();
            static Attr
			* HelathAttr = new Attr(HP, 0., 0.),
			* AtkAttr = new Attr(ATK, 0., 0.),
			* DefAttr = new Attr(DEF, 0., 0.),
			* CritRateAttr = new Attr(0.05, 0., 0.),
			* CritDamageAttr = new Attr(0.5, 0., 0.);
            baseData->SetAttr((u32)AttrType::Helath, HelathAttr);
		    baseData->SetAttr((u32)AttrType::Atk, DefAttr);
		    baseData->SetAttr((u32)AttrType::Def, AtkAttr);
		    baseData->SetAttr((u32)AttrType::CritRate, CritRateAttr);
		    baseData->SetAttr((u32)AttrType::CritDamage, CritDamageAttr);
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
            /*******${技能.name}${技能.attributes.labels.map(label => {
                    return `
            ${label}`
                }).join("")}
            */

            ${Object.keys(技能.attributes.parameters).map((参数键, 参数序号) => {

                    return `
                    const static double* Skill_${序号 + 1}_${参数序号 + 1} = new double[15]{ ${技能.attributes.parameters[参数键].join(",")} };`

                }).join("")}`
            }).join("\n")}
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
        void ${名字}::A(Role* role, u8* cmd) {
        };
        void ${名字}::Q(Role* role, u8* cmd) {        
        };
        void ${名字}::E(Role* role, u8* cmd) {        
        };    
        }
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

            }
        })

        // console.log(CPPPath,HPath);       


    }

});
const RoleH = `
#include "../DB.h"
namespace Role{
   ${Object.keys(ElementMap).map(i => {
    return `
    namespace ${i}{};`
}).join("")} 
}
`
let coder = new TextEncoder()
let decoder = new TextDecoder()
console.log(RoleH, RolePath + "Role.h");


fs.writeFile(RolePath + "Role.h", RoleH, () => { })


// genshindb.weapons('names', { matchCategories: true }).map(name=>{

//   let data =  genshindb.weapons(name,{ resultLanguage: genshindb.Languages.ChineseSimplified })
// console.log(data?.substat,data?.stats(90)?.specialized);


// })

