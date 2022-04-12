﻿#pragma once
        #include "钟离.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO钟离.cpp
        const double HP =  14695.093513910891;
        const double ATK =  251.1372978774416;
        const double DEF =  737.81219098164;
        //岩元素伤害加成
        const double OTHER = 0.2879999876022339;
        
        钟离::~钟离() {
        }
        钟离::钟离(u32* frameCur):Role(frameCur) {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Male, CharacterGroup::Tivat, ElementType::Geo, WeaponType::Polearm);
            delete baseData;
        };        

        /*
        
        ****1:悬岩宸断
        ****************
        
            玉璋护盾受到伤害时，会产生坚璧效果：
            ·处于玉璋护盾庇护下的角色，护盾强效提升5%；
            ·该效果至多叠加5次，持续直到玉璋护盾消失。 

        ****************
        

        ****2:炊金馔玉
        ****************
        
            基于生命值上限，钟离的以下攻击造成的伤害提高：
            ·普通攻击、重击与下落攻击伤害提高值：生命值上限的1.39%
            ·❤地心❤的岩脊、共鸣伤害与长按伤害提高值：生命值上限的1.9%
            ·❤天星❤伤害提高值：生命值上限的33% 

        ****************
        

        ****3:晶石命理
        ****************
        
            锻造长柄武器时，返还15%消耗的矿石。 

        ****************
        
        */
        
            /*******普通攻击·岩雨
             * 
             * **普通攻击**
             * 进行至多六段的连续枪击。
             * 
             * **重击**
             * 消耗一定体力，向前方疾行，在行动路径上和终点投下如雨的岩枪。
             * 
             * **下落攻击**
             * 从空中下坠冲击地面，攻击下落路径上的敌人，并在落地时造成范围伤害。
             * 
             * 一段伤害|{param1:F1P}
             * 二段伤害|{param2:F1P}
             * 三段伤害|{param3:F1P}
             * 四段伤害|{param4:F1P}
             * 五段伤害|{param5:F1P}*4
             * 六段伤害|{param6:F1P}
             * 重击伤害|{param7:P}
             * 重击体力消耗|{param8:F1}点
             * 下坠期间伤害|{param9:F1P}
             * 低空/高空坠地冲击伤害|{param10:P}/{param11:P}
            */
            void 钟离::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[11]{ 0.3076910078525543,0.31151801347732544,0.3857620060443878,0.42938899993896484,0.10750000178813934,0.5449650287628174,1.110260009765625,25,0.6393240094184875,1.2783770561218262,1.59676194190979},
                        new const double[11]{ 0.33273500204086304,0.33687400817871094,0.4171609878540039,0.4643400013446808,0.11625000089406967,0.5893219709396362,1.2006299495697021,25,0.6913620233535767,1.3824310302734375,1.7267309427261353},
                        new const double[11]{ 0.35778000950813293,0.36223000288009644,0.4485599994659424,0.49928998947143555,0.125,0.633679986000061,1.2910000085830688,25,0.743399977684021,1.4864850044250488,1.8566999435424805},
                        new const double[11]{ 0.39355799555778503,0.3984529972076416,0.4934160113334656,0.549219012260437,0.13750000298023224,0.697048008441925,1.4200999736785889,25,0.8177400231361389,1.635133981704712,2.042370080947876},
                        new const double[11]{ 0.41860300302505493,0.4238089919090271,0.524815022945404,0.5841689705848694,0.14624999463558197,0.7414060235023499,1.5104700326919556,25,0.8697779774665833,1.7391870021820068,2.1723389625549316},
                        new const double[11]{ 0.44722500443458557,0.45278799533843994,0.560699999332428,0.6241130232810974,0.15625,0.7921000123023987,1.6137499809265137,25,0.9292500019073486,1.858106017112732,2.3208749294281006},
                        new const double[11]{ 0.4865809977054596,0.49263298511505127,0.6100419759750366,0.6790339946746826,0.17000000178813934,0.8618050217628479,1.7557599544525146,25,1.011023998260498,2.021620035171509,2.5251119136810303},
                        new const double[11]{ 0.525937020778656,0.5324779748916626,0.6593829989433289,0.733955979347229,0.1837500035762787,0.9315099716186523,1.8977700471878052,25,1.0927979946136475,2.1851329803466797,2.72934889793396},
                        new const double[11]{ 0.5652920007705688,0.5723230242729187,0.7087249755859375,0.7888780236244202,0.19750000536441803,1.0012140274047852,2.0397799015045166,25,1.1745719909667969,2.3486459255218506,2.9335858821868896},
                        new const double[11]{ 0.6082260012626648,0.6157910227775574,0.76255202293396,0.8487930297851562,0.21250000596046448,1.0772559642791748,2.194700002670288,25,1.2637799978256226,2.527024984359741,3.1563899517059326},
                        new const double[11]{ 0.6574209928512573,0.6655979752540588,0.8242290019989014,0.9174450039863586,0.22968700528144836,1.1643869876861572,2.3722119331359863,25,1.3529880046844482,2.7054030895233154,3.3791940212249756},
                        new const double[11]{ 0.7152739763259888,0.7241700291633606,0.8967610001564026,0.9981809854507446,0.2498999983072281,1.2668529748916626,2.5809669494628906,25,1.442196011543274,2.8837809562683105,3.6019980907440186},
                        new const double[11]{ 0.773127019405365,0.782742977142334,0.9692929983139038,1.0789159536361694,0.270112007856369,1.369318962097168,2.789721965789795,25,1.5314040184020996,3.0621590614318848,3.8248019218444824},
                        new const double[11]{ 0.8309800028800964,0.841314971446991,1.0418250560760498,1.1596510410308838,0.29032498598098755,1.4717849493026733,2.998476982116699,25,1.6206120252609253,3.24053692817688,4.047605991363525},
                        new const double[11]{ 0.8940920233726501,0.9052129983901978,1.1209510564804077,1.2477259635925293,0.312375009059906,1.5835659503936768,3.2262089252471924,25,1.709820032119751,3.418915033340454,4.270410060882568}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******地心
             * 
             * 山脉中、大地上、磐石间，都遍布着岩之力。能自如驱动这股力量的人却少之又少。
             * 
             * **点按**
             * 命令大地上岩元素积聚而起，创造岩脊。
             * 
             * **长按**
             * 令附近的岩元素爆发，造成以下效果：
             * ·如果岩脊数量没有达到上限，则创造岩脊；
             * ·形成玉璋护盾，伤害吸收量受益于钟离的生命值上限；
             * ·造成岩元素范围伤害；
             * ·身边如果有附带有岩元素的目标，则大量消耗至多两个目标的岩元素。这个效果不会造成伤害。
             * 
             * **岩脊**
             * 创造时，造成岩元素范围伤害。
             * 此外，存在期间会与周围的其他岩元素创造物间歇进行原岩共鸣，对周围的敌人造成岩元素伤害。
             * 岩脊视为岩元素创造物，可以阻拦攻击，可以攀爬。
             * 由钟离自己创造的岩脊，初始同时只能存在一个。
             * 
             * **玉璋护盾**
             * 对所有元素伤害与物理伤害有150%的吸收效果。
             * 处于玉璋护盾庇护下的角色，会使附近小范围内敌人的所有元素抗性与物理抗性降低20%，该效果不可叠加。
             * 
             * 岩脊伤害/共鸣伤害|{param1:F1P}/{param2:F1P}
             * 点按冷却时间|{param3:F1}秒
             * 长按伤害|{param4:P}
             * 护盾基础吸收量|{param5:I}
             * 护盾附加吸收量|{param6:F1P}最大生命值
             * 护盾持续时间|{param7:F1}秒
             * 长按冷却时间|{param8:F1}秒
            */
            void 钟离::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[8]{ 0.1599999964237213,0.3199999928474426,4,0.800000011920929,1232.4107666015625,0.12800000607967377,20,12},
                        new const double[8]{ 0.1720000058412552,0.3440000116825104,4,0.8600000143051147,1355.6690673828125,0.13760000467300415,20,12},
                        new const double[8]{ 0.18400000035762787,0.36800000071525574,4,0.9200000166893005,1489.19873046875,0.14720000326633453,20,12},
                        new const double[8]{ 0.20000000298023224,0.4000000059604645,4,1,1633,0.1599999964237213,20,12},
                        new const double[8]{ 0.21199999749660492,0.42399999499320984,4,1.059999942779541,1787.07275390625,0.1695999950170517,20,12},
                        new const double[8]{ 0.2240000069141388,0.4480000138282776,4,1.1200000047683716,1951.4169921875,0.17919999361038208,20,12},
                        new const double[8]{ 0.23999999463558197,0.47999998927116394,4,1.2000000476837158,2126.032958984375,0.19200000166893005,20,12},
                        new const double[8]{ 0.25600001215934753,0.5120000243186951,4,1.2799999713897705,2310.920166015625,0.20479999482631683,20,12},
                        new const double[8]{ 0.2720000147819519,0.5440000295639038,4,1.3600000143051147,2506.0791015625,0.2176000028848648,20,12},
                        new const double[8]{ 0.2879999876022339,0.5759999752044678,4,1.440000057220459,2711.50927734375,0.2303999960422516,20,12},
                        new const double[8]{ 0.30399999022483826,0.6079999804496765,4,1.5199999809265137,2927.211181640625,0.24320000410079956,20,12},
                        new const double[8]{ 0.3199999928474426,0.6399999856948853,4,1.600000023841858,3153.1845703125,0.25600001215934753,20,12},
                        new const double[8]{ 0.3400000035762787,0.6800000071525574,4,1.7000000476837158,3389.429443359375,0.2720000147819519,20,12},
                        new const double[8]{ 0.36000001430511475,0.7200000286102295,4,1.7999999523162842,3635.946044921875,0.2879999876022339,20,12},
                        new const double[8]{ 0.3799999952316284,0.7599999904632568,4,1.899999976158142,3892.73388671875,0.30399999022483826,20,12}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******天星
             * 
             * 降下巨大的星岩，对坠落范围内的敌人造成巨额岩元素伤害，并使其石化。
             * 
             * **石化**
             * 处于石化状态下的敌人无法行动。
             * 
             * 技能伤害|{param1:P}
             * 石化时间|{param2:F1}秒
             * 冷却时间|{param3:F1}秒
             * 元素能量|{param4:I}
            */
            void 钟离::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[4]{ 4.010799884796143,3.0999999046325684,12,40},
                        new const double[4]{ 4.444399833679199,3.200000047683716,12,40},
                        new const double[4]{ 4.877999782562256,3.299999952316284,12,40},
                        new const double[4]{ 5.420000076293945,3.4000000953674316,12,40},
                        new const double[4]{ 5.907800197601318,3.5,12,40},
                        new const double[4]{ 6.395599842071533,3.5999999046325684,12,40},
                        new const double[4]{ 7.046000003814697,3.700000047683716,12,40},
                        new const double[4]{ 7.696400165557861,3.799999952316284,12,40},
                        new const double[4]{ 8.346799850463867,3.9000000953674316,12,40},
                        new const double[4]{ 8.997200012207031,4,12,40},
                        new const double[4]{ 9.647600173950195,4,12,40},
                        new const double[4]{ 10.29800033569336,4,12,40},
                        new const double[4]{ 10.84000015258789,4,12,40},
                        new const double[4]{ 11.381999969482422,4,12,40},
                        new const double[4]{ 11.923999786376953,4,12,40}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };
        /*****钟离
        
            ***1命***
            岩者，六合引之为骨            
            ❤地心❤创造的岩脊至多可以同时存在2个。
            
            ***2命***
            石者，八荒韫玉而明            
            ❤天星❤陨落时，会为附近的当前场上角色赋予玉璋护盾。
            
            ***3命***
            圭璋，暝仍不移其晖            
            ❤地心❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            黄琮，破而不夺其坚            
            ❤天星❤的影响范围扩大20%。此外，天星的石化效果持续时间延长2秒。
            
            ***5命***
            苍璧，驱之长昭天理            
            ❤天星❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            金玉，礼予天地四方            
            玉璋护盾受到伤害时，将为当前角色恢复生命值，回复量为伤害的40%。单次回复量不超过当前角色最大生命值的8%。
            
        */
         
        