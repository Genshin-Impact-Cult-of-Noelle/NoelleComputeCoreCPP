﻿#pragma once
        #include "荒泷一斗.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO荒泷一斗.cpp
        const double HP =  12858.207019053749;
        const double ATK =  227.2194615206754;
        const double DEF =  959.1558753436984;
        //暴击率
        const double OTHER = 0.2420000024139881;
        
        荒泷一斗::~荒泷一斗() {
        }
        荒泷一斗::荒泷一斗(u32* frameCur):Role(frameCur) {
            BaseObject* baseData = new BaseObject();
            static Attr
			* HelathAttr = new Attr(HP, 0., 0.),
			* AtkAttr = new Attr(ATK, 0., 0.),
			* DefAttr = new Attr(DEF, 0., 0.),
			* CritRateAttr = new Attr(0.05, 0., 0.),
			* CritDamageAttr = new Attr(0.5, 0., 0.);
            baseData->SetAttr(HelathAttr,AttrType::Helath);
		    baseData->SetAttr(AtkAttr,AttrType::Atk);
		    baseData->SetAttr(DefAttr,AttrType::Def);
		    baseData->SetAttr(CritRateAttr,AttrType::CritRate);
		    baseData->SetAttr(CritDamageAttr,AttrType::CritDamage);
            this->rawCharacter = new Character(baseData, CharacterGender::Male, CharacterGroup::Tivat, ElementType::Geo, WeaponType::Claymore);
            delete baseData;
        };        

        /*
        
        ****1:荒泷第一
        ****************
        
            荒泷一斗施展连续的「荒泷逆袈裟」时，获得以下效果：
            ·每次斩击都将使接下来的斩击攻击速度提升10%，通过这种方法至多提升30%；
            ·提升抗打断能力。
            
            这些效果将在连续施展结束时消失。 

        ****************
        

        ****2:赤鬼之血
        ****************
        
            「荒泷逆袈裟」造成的伤害提高，伤害提高值基于荒泷一斗防御力的35%。 

        ****************
        

        ****3:干裂枝碎
        ****************
        
            队伍中自己的角色通过攻击树木获取木材时，有25%的几率获得额外的木材。 

        ****************
        
        */
        
            /*******普通攻击· 喧哗屋传说
             * 
             * **普通攻击**
             * 进行至多四段的连续挥砍。
             * 在第二段与第四段攻击命中敌人时，会分别产生1层与2层「乱神之怪力」效果。
             * 最多拥有5层乱神之怪力，每次触发都会刷新已有的乱神之怪力持续时间。
             * 
             * 此外，施放元素战技「魔杀绝技·赤牛发破！」或进行冲刺后的一小段时间内，普通攻击连击段数不会重置。
             * 
             * **重击**
             * 长按进行重击时，若拥有乱神之怪力，将进行不消耗体力的「荒泷逆袈裟」斩击。荒泷逆袈裟的每次攻击都将消耗一层乱神之怪力；消耗最后一层时，将施展格外强力的终结一击。
             * 没有乱神之怪力时，将消耗体力，进行一次猛烈的左一文字斩。
             * 
             * **下落攻击**
             * 从空中下坠冲击地面，攻击下落路径上的敌人，并在落地时造成范围伤害。
             * 
             * 一段伤害|{param1:F1P}
             * 二段伤害|{param2:F1P}
             * 三段伤害|{param3:F1P}
             * 四段伤害|{param4:F1P}
             * 荒泷逆袈裟连斩伤害|{param6:F1P}
             * 荒泷逆袈裟终结伤害|{param7:F1P}
             * 乱神之怪力持续时间|{param12:F1}秒
             * 左一文字斩伤害|{param5:F1P}
             * 左一文字斩体力消耗|{param8:F1}点
             * 下坠期间伤害|{param9:F1P}
             * 低空/高空坠地冲击伤害|{param10:P}/{param11:P}
            */
            void 荒泷一斗::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[12]{ 0.7923179864883423,0.7636799812316895,0.9164159893989563,1.1722489595413208,0.9047200083732605,0.9115999937057495,1.9091999530792236,20,0.8183349967002869,1.6363229751586914,2.0438549518585205,60},
                        new const double[12]{ 0.8568090200424194,0.8258399963378906,0.9910079836845398,1.2676639556884766,0.9783599972724915,0.98580002784729,2.0645999908447266,20,0.8849430084228516,1.7695120573043823,2.2102160453796387,60},
                        new const double[12]{ 0.9212999939918518,0.8880000114440918,1.065600037574768,1.3630800247192383,1.0520000457763672,1.059999942779541,2.2200000286102295,20,0.9515519738197327,1.9027010202407837,2.3765759468078613,60},
                        new const double[12]{ 1.0134299993515015,0.9768000245094299,1.172160029411316,1.4993879795074463,1.1571999788284302,1.1660000085830688,2.441999912261963,20,1.046707034111023,2.092971086502075,2.61423397064209,60},
                        new const double[12]{ 1.0779210329055786,1.0389599800109863,1.2467520236968994,1.594804048538208,1.2308399677276611,1.2402000427246094,2.597399950027466,20,1.1133160591125488,2.2261600494384766,2.7805941104888916,60},
                        new const double[12]{ 1.1516250371932983,1.1100000143051147,1.3320000171661377,1.7038500308990479,1.315000057220459,1.3250000476837158,2.7750000953674316,20,1.1894400119781494,2.378376007080078,2.970720052719116,60},
                        new const double[12]{ 1.2529679536819458,1.2076799869537354,1.4492160081863403,1.85378897190094,1.4307199716567993,1.44159996509552,3.019200086593628,20,1.2941110134124756,2.5876729488372803,3.232142925262451,60},
                        new const double[12]{ 1.3543109893798828,1.305359959602356,1.566431999206543,2.003727912902832,1.5464400053024292,1.5582000017166138,3.263400077819824,20,1.3987809419631958,2.7969698905944824,3.4935669898986816,60},
                        new const double[12]{ 1.4556540250778198,1.4030400514602661,1.6836479902267456,2.1536660194396973,1.662160038948059,1.6748000383377075,3.5076000690460205,20,1.503451943397522,3.0062670707702637,3.7549901008605957,60},
                        new const double[12]{ 1.5662100315093994,1.509600043296814,1.811519980430603,2.3172359466552734,1.7884000539779663,1.8020000457763672,3.7739999294281006,20,1.6176379919052124,3.234591007232666,4.0401787757873535,60},
                        new const double[12]{ 1.6928889751434326,1.631700038909912,1.9580399990081787,2.5046589374542236,1.9330500364303589,1.9477499723434448,4.079249858856201,20,1.7318249940872192,3.4629149436950684,4.3253679275512695,60},
                        new const double[12]{ 1.8418630361557007,1.7752900123596191,2.130347967147827,2.725069999694824,2.1031579971313477,2.119152069091797,4.438223838806152,20,1.8460110425949097,3.691240072250366,4.6105570793151855,60},
                        new const double[12]{ 1.9908369779586792,1.9188790321350098,2.302654981613159,2.9454801082611084,2.2732670307159424,2.2905540466308594,4.7971978187561035,20,1.9601969718933105,3.9195640087127686,4.895747184753418,60},
                        new const double[12]{ 2.1398110389709473,2.062469005584717,2.4749629497528076,3.1658899784088135,2.4433751106262207,2.461956024169922,5.156171798706055,20,2.074383020401001,4.14788818359375,5.180935859680176,60},
                        new const double[12]{ 2.3023290634155273,2.219111919403076,2.6629340648651123,3.406337022781372,2.6289479732513428,2.648940086364746,5.5477800369262695,20,2.188570022583008,4.376212120056152,5.466125011444092,60}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******魔杀绝技·赤牛发破！
             * 
             * 将荒泷派编外成员小赤牛「阿丑」高速投掷出去，对命中的敌人造成岩元素伤害！「阿丑」命中敌人时，会为荒泷一斗提供1层「乱神之怪力」效果。
             * 
             * 「阿丑」会留在场上提供支援：
             * ·持续嘲讽周围的敌人，吸引火力；
             * ·耐久度按比例继承荒泷一斗的生命值上限；
             * ·受到伤害时，会为荒泷一斗自己提供1层「乱神之怪力」效果。每2秒至多通过这种方式提供1层；
             * ·耐久度耗尽或持续时间结束时会逃走，并在离开时为荒泷一斗自己提供1层「乱神之怪力」效果。
             * 
             * **长按**
             * 调整投掷方向。
             * 
             * 「阿丑」被视为岩元素创造物；同时只能存在一个由荒泷一斗自己召唤的「阿丑」。
             * 
             * 技能伤害|{param1:P}
             * 继承生命|{param2:P}
             * 持续时间|{param3:F1}秒
             * 冷却时间|{param5:F1}秒
            */
            void 荒泷一斗::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[5]{ 3.072000026702881,1,6,2,10},
                        new const double[5]{ 3.3024001121520996,1,6,2,10},
                        new const double[5]{ 3.5327999591827393,1,6,2,10},
                        new const double[5]{ 3.8399999141693115,1,6,2,10},
                        new const double[5]{ 4.070400238037109,1,6,2,10},
                        new const double[5]{ 4.30079984664917,1,6,2,10},
                        new const double[5]{ 4.607999801635742,1,6,2,10},
                        new const double[5]{ 4.915200233459473,1,6,2,10},
                        new const double[5]{ 5.222400188446045,1,6,2,10},
                        new const double[5]{ 5.529600143432617,1,6,2,10},
                        new const double[5]{ 5.8368000984191895,1,6,2,10},
                        new const double[5]{ 6.144000053405762,1,6,2,10},
                        new const double[5]{ 6.5279998779296875,1,6,2,10},
                        new const double[5]{ 6.9120001792907715,1,6,2,10},
                        new const double[5]{ 7.296000003814697,1,6,2,10}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******最恶鬼王·一斗轰临！！
             * 
             * 是时候展现荒泷派的一斗之威名了！在接下来的一段时间内化身「怒目鬼王」，使用鬼王金碎棒战斗。
             * 具有如下特性：
             * ·普通攻击、重击与下落攻击造成的伤害转为无法被附魔覆盖的岩元素伤害；
             * ·提高荒泷一斗普通攻击的攻击速度，并基于其防御力，提高攻击力；
             * ·第一与第三段攻击在命中敌人时，将为荒泷一斗自己提供1层「乱神之怪力」效果；
             * ·荒泷一斗的所有元素抗性与物理抗性降低20%。
             * 
             * 「怒目鬼王」状态将在荒泷一斗退场时解除。
             * 
             * 攻击力提高|{param2:F1P}防御力
             * 攻击速度提高|{param1:P}
             * 持续时间|{param4:F1}秒
             * 冷却时间|{param5:F1}秒
             * 元素能量|{param6:I}
            */
            void 荒泷一斗::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[6]{ 0.10000000149011612,0.5759999752044678,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,0.6191999912261963,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,0.6624000072479248,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,0.7200000286102295,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,0.7631999850273132,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,0.8064000010490417,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,0.8640000224113464,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,0.9215999841690063,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,0.979200005531311,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,1.0368000268936157,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,1.0944000482559204,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,1.1519999504089355,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,1.2239999771118164,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,1.2960000038146973,0.20000000298023224,11,18,70},
                        new const double[6]{ 0.10000000149011612,1.3680000305175781,0.20000000298023224,11,18,70}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };
        /*****荒泷一斗
        
            ***1命***
            倘若不知，我讲你听            
            施放❤最恶鬼王·一斗轰临！！❤后，荒泷一斗获得2层「乱神之怪力」效果。1秒后，荒泷一斗每0.5秒再获得1层「乱神之怪力」效果，持续1.5秒。
            
            ***2命***
            纠集众人，斗倒御岳            
            施放❤最恶鬼王·一斗轰临！！❤后，队伍中每个元素类型为岩元素的角色，都将使其冷却时间减少1.5秒，使荒泷一斗的元素能量恢复6点。通过这种方式，至多减少4.5秒冷却时间，恢复18点元素能量。
            
            ***3命***
            水陆自在，牛王同行            
            ❤魔杀绝技·赤牛发破！❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            奉行牢狱，茶饭之所            
            ❤最恶鬼王·一斗轰临！！❤施加的「怒目鬼王」状态结束后，附近的队伍中所有角色的防御力提升20%，攻击力提升20%，持续10秒。
            
            ***5命***
            十年花坂，皆知我名            
            ❤最恶鬼王·一斗轰临！！❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            在下荒泷一斗是也            
            荒泷一斗的重击的暴击伤害提高70%；此外，施展「荒泷逆袈裟」时，有50%的几率不消耗「乱神之怪力」。
            
        */
         
        