﻿#pragma once
        #include "云堇.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO云堇.cpp
        const double HP =  10657.416653864551;
        const double ATK =  191.15747659430235;
        const double DEF =  734.393168256971;
        //元素充能效率
        const double OTHER = 0.26669999957084656;
        
        云堇::~云堇() {
        }
        云堇::云堇(u32* frameCur):Role(frameCur) {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Geo, WeaponType::Polearm);
            delete baseData;
        };        

        /*
        
        ****1:务守本真
        ****************
        
            在被攻击瞬间施放的❤旋云开相❤，会以长按二段蓄力的形式施放。 

        ****************
        

        ****2:莫从恒蹊
        ****************
        
            ❤「飞云旗阵」❤提供的普通攻击伤害提高，当队伍中存在1/2/3/4种元素类型的角色时，数值上进一步追加云堇防御力的2.5%/5%/7.5%/11.5%。 

        ****************
        

        ****3:清食养性
        ****************
        
            完美烹饪冒险类食物时，有12%概率获得2倍产出。 

        ****************
        
        */
        
            /*******普通攻击·拂云出手
             * 
             * **普通攻击**
             * 进行至多五段的连续枪击。
             * 
             * **重击**
             * 消耗一定体力，向前方突进，对路径上的敌人造成伤害。
             * 
             * **下落攻击**
             * 从空中下坠冲击地面，攻击下落路径上的敌人，并在落地时造成范围伤害。
             * 
             * 一段伤害|{param1:F1P}
             * 二段伤害|{param2:F1P}
             * 三段伤害|{param3:F1P}+{param4:F1P}
             * 四段伤害|{param5:F1P}+{param6:F1P}
             * 五段伤害|{param7:F1P}
             * 重击伤害|{param8:F1P}
             * 重击体力消耗|{param9:F1}点
             * 下坠期间伤害|{param10:F1P}
             * 低空/高空坠地冲击伤害|{param11:P}/{param12:P}
            */
            void 云堇::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[12]{ 0.4050599932670593,0.40248000621795654,0.22961999475955963,0.2752000093460083,0.23994000256061554,0.288100004196167,0.6733800172805786,1.2168999910354614,25,0.6393240094184875,1.2783770561218262,1.59676194190979},
                        new const double[12]{ 0.4380300045013428,0.4352400004863739,0.24830999970436096,0.29760000109672546,0.25946998596191406,0.31154999136924744,0.728190004825592,1.3159500360488892,25,0.6913620233535767,1.3824310302734375,1.7267309427261353},
                        new const double[12]{ 0.47099998593330383,0.46799999475479126,0.2669999897480011,0.3199999928474426,0.27900001406669617,0.33500000834465027,0.7829999923706055,1.4149999618530273,25,0.743399977684021,1.4864850044250488,1.8566999435424805},
                        new const double[12]{ 0.5181000232696533,0.5148000121116638,0.2937000095844269,0.35199999809265137,0.3068999946117401,0.3684999942779541,0.861299991607666,1.55649995803833,25,0.8177400231361389,1.635133981704712,2.042370080947876},
                        new const double[12]{ 0.551069974899292,0.5475599765777588,0.312389999628067,0.37439998984336853,0.32642999291419983,0.39195001125335693,0.9161099791526794,1.6555500030517578,25,0.8697779774665833,1.7391870021820068,2.1723389625549316},
                        new const double[12]{ 0.5887500047683716,0.5849999785423279,0.33375000953674316,0.4000000059604645,0.3487499952316284,0.41874998807907104,0.9787499904632568,1.7687499523162842,25,0.9292500019073486,1.858106017112732,2.3208749294281006},
                        new const double[12]{ 0.64055997133255,0.6364799737930298,0.3631199896335602,0.4352000057697296,0.3794400095939636,0.45559999346733093,1.0648800134658813,1.924399971961975,25,1.011023998260498,2.021620035171509,2.5251119136810303},
                        new const double[12]{ 0.6923699975013733,0.6879600286483765,0.3924899995326996,0.47040000557899475,0.41012999415397644,0.4924499988555908,1.1510100364685059,2.080049991607666,25,1.0927979946136475,2.1851329803466797,2.72934889793396},
                        new const double[12]{ 0.7441800236701965,0.7394400238990784,0.421860009431839,0.5055999755859375,0.44082000851631165,0.5292999744415283,1.2371400594711304,2.2356998920440674,25,1.1745719909667969,2.3486459255218506,2.9335858821868896},
                        new const double[12]{ 0.8007000088691711,0.7955999970436096,0.453900009393692,0.5440000295639038,0.47429999709129333,0.5695000290870667,1.3310999870300293,2.4054999351501465,25,1.2637799978256226,2.527024984359741,3.1563899517059326},
                        new const double[12]{ 0.8572199940681458,0.8517600297927856,0.48594000935554504,0.5824000239372253,0.5077800154685974,0.6097000241279602,1.4250600337982178,2.6000618934631348,25,1.3529880046844482,2.7054030895233154,3.3791940212249756},
                        new const double[12]{ 0.9137399792671204,0.9079200029373169,0.5179799795150757,0.6208000183105469,0.5412600040435791,0.6499000191688538,1.5190199613571167,2.8288679122924805,25,1.442196011543274,2.8837809562683105,3.6019980907440186},
                        new const double[12]{ 0.9702600240707397,0.9640799760818481,0.5500199794769287,0.6592000126838684,0.5747399926185608,0.6901000142097473,1.6129800081253052,3.0576729774475098,25,1.5314040184020996,3.0621590614318848,3.8248019218444824},
                        new const double[12]{ 1.0267800092697144,1.0202399492263794,0.5820599794387817,0.6976000070571899,0.6082199811935425,0.7303000092506409,1.7069400548934937,3.2864789962768555,25,1.6206120252609253,3.24053692817688,4.047605991363525},
                        new const double[12]{ 1.083299994468689,1.0764000415802002,0.6140999794006348,0.7360000014305115,0.641700029373169,0.7705000042915344,1.8008999824523926,3.5360848903656006,25,1.709820032119751,3.418915033340454,4.270410060882568}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******旋云开相
             * 
             * 云先生的武戏架势，是真能御敌的。
             * 
             * **点按**
             * 以拨云之势旋舞长枪，造成岩元素伤害。
             * 
             * **长按**
             * 摆出旋云开相之架势蓄力，形成护盾，伤害吸收量受益于云堇的生命值上限，对所有元素伤害与物理伤害有150%的吸收效果。护盾持续至元素战技施放完毕。
             * 松开技能、持续时间结束时，或护盾被破坏时，会挥舞长枪释放积攒的力量进行攻击，造成岩元素伤害。
             * 依据蓄力的时间，释放时的状态将分为一段蓄力与二段蓄力。
             * 
             * 点按伤害|{param3:F1P}防御力
             * 一段蓄力伤害|{param4:F1P}防御力
             * 二段蓄力伤害|{param5:F1P}防御力
             * 护盾吸收量|{param1:P}生命值上限+{param2:I}
             * 冷却时间|{param6:F1}秒
            */
            void 云堇::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[6]{ 0.11999999731779099,1155.4322509765625,1.4911999702453613,2.609600067138672,3.7279999256134033,9},
                        new const double[6]{ 0.1289999932050705,1270.9915771484375,1.6030399799346924,2.8053200244903564,4.007599830627441,9},
                        new const double[6]{ 0.1379999965429306,1396.1807861328125,1.7148799896240234,3.001039981842041,4.287199974060059,9},
                        new const double[6]{ 0.15000000596046448,1531,1.8639999628067017,3.26200008392334,4.659999847412109,9},
                        new const double[6]{ 0.1589999943971634,1675.4490966796875,1.9758399724960327,3.4577200412750244,4.939599990844727,9},
                        new const double[6]{ 0.1679999977350235,1829.5281982421875,2.0876801013946533,3.653439998626709,5.219200134277344,9},
                        new const double[6]{ 0.18000000715255737,1993.2371826171875,2.236799955368042,3.914400100708008,5.5920000076293945,9},
                        new const double[6]{ 0.19200000166893005,2166.576171875,2.3859200477600098,4.175360202789307,5.964799880981445,9},
                        new const double[6]{ 0.20399999618530273,2349.544921875,2.5350399017333984,4.436319828033447,6.337600231170654,9},
                        new const double[6]{ 0.2160000056028366,2542.143798828125,2.684159994125366,4.697279930114746,6.710400104522705,9},
                        new const double[6]{ 0.2280000001192093,2744.37255859375,2.833280086517334,4.958240032196045,7.083199977874756,9},
                        new const double[6]{ 0.23999999463558197,2956.231201171875,2.9823999404907227,5.219200134277344,7.455999851226807,9},
                        new const double[6]{ 0.2549999952316284,3177.719970703125,3.168800115585327,5.545400142669678,7.921999931335449,9},
                        new const double[6]{ 0.27000001072883606,3408.83837890625,3.3552000522613525,5.871600151062012,8.387999534606934,9},
                        new const double[6]{ 0.2849999964237213,3649.5869140625,3.541599988937378,6.197800159454346,8.854000091552734,9}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******破嶂见旌仪
             * 
             * 造成岩元素范围伤害，并为附近的队伍中所有角色赋予「飞云旗阵」。
             * 
             * **飞云旗阵**
             * 对敌人造成普通攻击伤害时，基于云堇自己当前的防御力，提高造成的伤害。
             * 
             * 「飞云旗阵」效果会在持续时间结束或生效一定次数后消失。
             * 一次普通攻击同时命中多名敌人时，会依据命中敌人的数量消耗生效次数；队伍中具有「飞云旗阵」的角色，其生效次数单独计算。
             * 
             * 技能伤害|{param1:P}
             * 伤害值提升|{param2:P}防御力
             * 持续时间|{param3:F1}秒
             * 生效次数|{param6:I}次
             * 冷却时间|{param4:F1}秒
             * 元素能量|{param5:I}
            */
            void 云堇::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[6]{ 2.440000057220459,0.3215999901294708,12,15,60,30},
                        new const double[6]{ 2.622999906539917,0.34571999311447144,12,15,60,30},
                        new const double[6]{ 2.805999994277954,0.36983999609947205,12,15,60,30},
                        new const double[6]{ 3.049999952316284,0.4020000100135803,12,15,60,30},
                        new const double[6]{ 3.2330000400543213,0.42612001299858093,12,15,60,30},
                        new const double[6]{ 3.4159998893737793,0.45023998618125916,12,15,60,30},
                        new const double[6]{ 3.6600000858306885,0.48240000009536743,12,15,60,30},
                        new const double[6]{ 3.9040000438690186,0.5145599842071533,12,15,60,30},
                        new const double[6]{ 4.1479997634887695,0.546720027923584,12,15,60,30},
                        new const double[6]{ 4.392000198364258,0.5788800120353699,12,15,60,30},
                        new const double[6]{ 4.636000156402588,0.6110399961471558,12,15,60,30},
                        new const double[6]{ 4.880000114440918,0.6431999802589417,12,15,60,30},
                        new const double[6]{ 5.184999942779541,0.6833999752998352,12,15,60,30},
                        new const double[6]{ 5.489999771118164,0.7235999703407288,12,15,60,30},
                        new const double[6]{ 5.795000076293945,0.7638000249862671,12,15,60,30}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };
        /*****云堇
        
            ***1命***
            飞身趟马            
            ❤旋云开相❤的冷却时间减少18%。
            
            ***2命***
            诸般切末            
            施放❤破嶂见旌仪❤后，附近队伍中所有角色普通攻击造成的伤害提升15%，持续12秒。
            
            ***3命***
            牙纛探海            
            ❤破嶂见旌仪❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            昇堂吊云            
            云堇触发结晶反应后，防御力提升20%，持续12秒。
            
            ***5命***
            翘楚名坤            
            ❤旋云开相❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            庄谐并举            
            处于❤「飞云旗阵」❤状态下的角色，普通攻击的攻击速度提升12%。
            
        */
         
        