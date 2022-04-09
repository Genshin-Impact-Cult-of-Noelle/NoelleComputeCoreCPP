﻿#pragma once
        #include "班尼特.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO班尼特.cpp
        const double HP =  12397.403338391683;
        const double ATK =  191.15747659430235;
        const double DEF =  771.2493414536075;
        //元素充能效率
        const double OTHER = 0.26669999957084656;
        
        班尼特::~班尼特() {
        }
        班尼特::班尼特(u32* frameCur) {
            _framCur = frameCur;
            BaseObject* baseData = new BaseObject();
            static Attr
			* HelathAttr = new Attr(HP, 0., 0.),
			* AtkAttr = new Attr(ATK, 0., 0.),
			* DefAttr = new Attr(DEF, 0., 0.),
			* CritRateAttr = new Attr(0.05, 0., 0.),
			* CritDamageAttr = new Attr(0.5, 0., 0.);
            baseData->SetAttr((u32)AttrType::Helath, HelathAttr);
		    baseData->SetAttr((u32)AttrType::Atk, AtkAttr);
		    baseData->SetAttr((u32)AttrType::Def, DefAttr);
		    baseData->SetAttr((u32)AttrType::CritRate, CritRateAttr);
		    baseData->SetAttr((u32)AttrType::CritDamage, CritDamageAttr);
            this->rawCharacter = new Character(baseData, CharacterGender::Male, CharacterGroup::Tivat, ElementType::Pyro, WeaponType::Sword);
            delete baseData;
        };        

        /*
        
        ****1:热情复燃
        ****************
        
            ❤热情过载❤的冷却时间减少20%。 

        ****************
        

        ****2:无畏的热血
        ****************
        
            在❤美妙旅程❤领域内，❤热情过载❤具有如下效果：
            ·冷却时间减少50%；
            ·二段蓄力不会将班尼特自身击飞。 

        ****************
        

        ****3:应该安全
        ****************
        
            在蒙德执行探索派遣任务时，消耗的时间缩短25%。 

        ****************
        
        */
        
            /*******普通攻击·好运剑
            一段伤害|{param1:F1P}
            二段伤害|{param2:F1P}
            三段伤害|{param3:F1P}
            四段伤害|{param4:F1P}
            五段伤害|{param5:F1P}
            重击伤害|{param6:F1P}+{param7:F1P}
            重击体力消耗|{param8:F1}点
            下坠期间伤害|{param9:F1P}
            低空/高空坠地冲击伤害|{param10:P}/{param11:P}
            */
            void 班尼特::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[11]{ 0.44547998905181885,0.4274199903011322,0.5461000204086304,0.5968400239944458,0.7189599871635437,0.5590000152587891,0.6071599721908569,20,0.6393240094184875,1.2783770561218262,1.59676194190979},
                        new const double[11]{ 0.48173999786376953,0.4622099995613098,0.5905500054359436,0.6454200148582458,0.7774800062179565,0.6044999957084656,0.6565799713134766,20,0.6913620233535767,1.3824310302734375,1.7267309427261353},
                        new const double[11]{ 0.5180000066757202,0.4970000088214874,0.6349999904632568,0.6940000057220459,0.8360000252723694,0.6499999761581421,0.7059999704360962,20,0.743399977684021,1.4864850044250488,1.8566999435424805},
                        new const double[11]{ 0.5698000192642212,0.5467000007629395,0.6984999775886536,0.7634000182151794,0.9196000099182129,0.7149999737739563,0.7766000032424927,20,0.8177400231361389,1.635133981704712,2.042370080947876},
                        new const double[11]{ 0.6060600280761719,0.5814899802207947,0.7429500222206116,0.8119800090789795,0.9781200289726257,0.7605000138282776,0.8260200023651123,20,0.8697779774665833,1.7391870021820068,2.1723389625549316},
                        new const double[11]{ 0.6474999785423279,0.6212499737739563,0.793749988079071,0.8675000071525574,1.0449999570846558,0.8125,0.8824999928474426,20,0.9292500019073486,1.858106017112732,2.3208749294281006},
                        new const double[11]{ 0.704479992389679,0.6759200096130371,0.8636000156402588,0.9438400268554688,1.1369600296020508,0.8840000033378601,0.9601600170135498,20,1.011023998260498,2.021620035171509,2.5251119136810303},
                        new const double[11]{ 0.76146000623703,0.7305899858474731,0.9334499835968018,1.0201799869537354,1.2289199829101562,0.9555000066757202,1.0378199815750122,20,1.0927979946136475,2.1851329803466797,2.72934889793396},
                        new const double[11]{ 0.8184400200843811,0.785260021686554,1.0032999515533447,1.096519947052002,1.3208800554275513,1.0269999504089355,1.1154799461364746,20,1.1745719909667969,2.3486459255218506,2.9335858821868896},
                        new const double[11]{ 0.8805999755859375,0.8449000120162964,1.0794999599456787,1.179800033569336,1.4212000370025635,1.1050000190734863,1.2001999616622925,20,1.2637799978256226,2.527024984359741,3.1563899517059326},
                        new const double[11]{ 0.9427599906921387,0.9045400023460388,1.1556999683380127,1.2630800008773804,1.5215200185775757,1.1829999685287476,1.2849199771881104,20,1.3529880046844482,2.7054030895233154,3.3791940212249756},
                        new const double[11]{ 1.0049200057983398,0.9641799926757812,1.2318999767303467,1.3463599681854248,1.621840000152588,1.2610000371932983,1.3696399927139282,20,1.442196011543274,2.8837809562683105,3.6019980907440186},
                        new const double[11]{ 1.067080020904541,1.0238200426101685,1.3080999851226807,1.4296400547027588,1.7221599817276,1.3389999866485596,1.454360008239746,20,1.5314040184020996,3.0621590614318848,3.8248019218444824},
                        new const double[11]{ 1.1292400360107422,1.0834599733352661,1.3842999935150146,1.5129200220108032,1.8224799633026123,1.4170000553131104,1.539080023765564,20,1.6206120252609253,3.24053692817688,4.047605991363525},
                        new const double[11]{ 1.1914000511169434,1.1431000232696533,1.4605000019073486,1.5961999893188477,1.9227999448776245,1.4950000047683716,1.6238000392913818,20,1.709820032119751,3.418915033340454,4.270410060882568}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******热情过载
            点按伤害|{param1:P}
            一段蓄力伤害|{param2:F1P}+{param3:F1P}
            二段蓄力伤害|{param4:F1P}+{param5:F1P}
            爆炸伤害|{param6:P}
            冷却时间|{param7:F1}/{param8:F1}/{param9:F1}秒
            */
            void 班尼特::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[9]{ 1.3760000467300415,0.8399999737739563,0.9200000166893005,0.8799999952316284,0.9599999785423279,1.3200000524520874,5,7.5,10},
                        new const double[9]{ 1.479200005531311,0.902999997138977,0.9890000224113464,0.9459999799728394,1.031999945640564,1.4190000295639038,5,7.5,10},
                        new const double[9]{ 1.5823999643325806,0.9660000205039978,1.0579999685287476,1.0119999647140503,1.1039999723434448,1.5180000066757202,5,7.5,10},
                        new const double[9]{ 1.7200000286102295,1.0499999523162842,1.149999976158142,1.100000023841858,1.2000000476837158,1.649999976158142,5,7.5,10},
                        new const double[9]{ 1.823199987411499,1.1130000352859497,1.218999981880188,1.1660000085830688,1.2719999551773071,1.7489999532699585,5,7.5,10},
                        new const double[9]{ 1.9263999462127686,1.1759999990463257,1.2879999876022339,1.2319999933242798,1.343999981880188,1.8480000495910645,5,7.5,10},
                        new const double[9]{ 2.063999891281128,1.2599999904632568,1.3799999952316284,1.3200000524520874,1.440000057220459,1.9800000190734863,5,7.5,10},
                        new const double[9]{ 2.2016000747680664,1.343999981880188,1.472000002861023,1.4079999923706055,1.5360000133514404,2.111999988555908,5,7.5,10},
                        new const double[9]{ 2.339200019836426,1.4279999732971191,1.5640000104904175,1.496000051498413,1.6319999694824219,2.24399995803833,5,7.5,10},
                        new const double[9]{ 2.476799964904785,1.5119999647140503,1.656000018119812,1.5839999914169312,1.7280000448226929,2.375999927520752,5,7.5,10},
                        new const double[9]{ 2.6143999099731445,1.5959999561309814,1.7480000257492065,1.6720000505447388,1.8240000009536743,2.507999897003174,5,7.5,10},
                        new const double[9]{ 2.752000093460083,1.6799999475479126,1.840000033378601,1.7599999904632568,1.9199999570846558,2.640000104904175,5,7.5,10},
                        new const double[9]{ 2.9240000247955322,1.784999966621399,1.9550000429153442,1.8700000047683716,2.0399999618530273,2.805000066757202,5,7.5,10},
                        new const double[9]{ 3.0959999561309814,1.8899999856948853,2.069999933242798,1.9800000190734863,2.1600000858306885,2.9700000286102295,5,7.5,10},
                        new const double[9]{ 3.2679998874664307,1.9950000047683716,2.184999942779541,2.0899999141693115,2.2799999713897705,3.134999990463257,5,7.5,10}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******美妙旅程
            技能伤害|{param1:P}
            持续治疗|每秒{param2:F2P}生命值上限+{param3:I}
            攻击力加成比例|{param4:P}
            持续时间|{param5:F1}秒
            冷却时间|{param6:F1}秒
            元素能量|{param7:I}
            */
            void 班尼特::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[7]{ 2.328000068664551,0.05999999865889549,577.3388061523438,0.5600000023841858,12,15,60},
                        new const double[7]{ 2.5025999546051025,0.06449999660253525,635.0806884765625,0.6019999980926514,12,15,60},
                        new const double[7]{ 2.6772000789642334,0.0689999982714653,697.6344604492188,0.6439999938011169,12,15,60},
                        new const double[7]{ 2.9100000858306885,0.07500000298023224,765,0.699999988079071,12,15,60},
                        new const double[7]{ 3.0845999717712402,0.0794999971985817,837.1773681640625,0.7419999837875366,12,15,60},
                        new const double[7]{ 3.259200096130371,0.08399999886751175,914.1665649414062,0.7839999794960022,12,15,60},
                        new const double[7]{ 3.492000102996826,0.09000000357627869,995.9676513671875,0.8399999737739563,12,15,60},
                        new const double[7]{ 3.7248001098632812,0.09600000083446503,1082.5804443359375,0.8960000276565552,12,15,60},
                        new const double[7]{ 3.9576001167297363,0.10199999809265137,1174.005126953125,0.9520000219345093,12,15,60},
                        new const double[7]{ 4.190400123596191,0.1080000028014183,1270.24169921875,1.0080000162124634,12,15,60},
                        new const double[7]{ 4.4232001304626465,0.11400000005960464,1371.2900390625,1.0640000104904175,12,15,60},
                        new const double[7]{ 4.656000137329102,0.11999999731779099,1477.150146484375,1.1200000047683716,12,15,60},
                        new const double[7]{ 4.947000026702881,0.1274999976158142,1587.8221435546875,1.190000057220459,12,15,60},
                        new const double[7]{ 5.23799991607666,0.13500000536441803,1703.305908203125,1.2599999904632568,12,15,60},
                        new const double[7]{ 5.5289998054504395,0.14249999821186066,1823.6015625,1.3300000429153442,12,15,60}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };
        /*****班尼特
        
            ***1命***
            冒险憧憬            
            ❤美妙旅程❤的攻击力提升效果不再有生命值限制，数值上追加班尼特基础攻击力的20%。
            
            ***2命***
            踏破绝境            
            班尼特的生命值低于70%时，元素充能效率提高30%。
            
            ***3命***
            火热激情            
            ❤热情过载❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            热情不灭            
            施放一段蓄力的❤热情过载❤时，在技能第二段攻击中进行普通攻击，可以施放额外的追击。追击的伤害等同于第二段攻击的135%。
            
            ***5命***
            开拓的心魂            
            ❤美妙旅程❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            烈火与勇气            
            处在❤美妙旅程❤领域内的队伍中当前场上单手剑、双手剑、长柄武器角色获得15%火元素伤害加成，并获得火元素附魔。
            
        */
         
        