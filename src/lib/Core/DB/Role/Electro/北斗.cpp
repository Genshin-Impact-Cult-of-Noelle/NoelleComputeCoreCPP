﻿#pragma once
        #include "北斗.h"
        using namespace DB::RoleConstruct;
        //TODO:AUTO北斗.cpp
        const double HP =  13049.897586040897;
        const double ATK =  225.14102222725342;
        const double DEF =  648.3954482758236;
        //雷元素伤害加成
        const double OTHER = 0.23999999463558197;
        
        北斗::~北斗() {
        }
        北斗::北斗() {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Electro, WeaponType::Claymore);
            delete baseData;
        };        

        /*
        
        ****1:遍宇灵光
        ****************
        
            在被攻击瞬间施放的❤捉浪❤反击，拥有最高伤害加成。 

        ****************
        

        ****2:霹雳连霄
        ****************
        
            施放拥有最高伤害加成的❤捉浪❤后的10秒内，获得如下效果：
            ·普通攻击与重击造成的伤害提高15%，攻击速度提高15%；
            ·大幅减少重击需要的准备时间。 

        ****************
        

        ****3:拥涛踏潮
        ****************
        
            队伍中自己的角色游泳消耗的体力降低20%。
            无法与效果完全相同的固有天赋叠加。 

        ****************
        
        */
        
            /*******普通攻击·征涛
            一段伤害|{param1:F1P}
            二段伤害|{param2:F1P}
            三段伤害|{param3:F1P}
            四段伤害|{param4:F1P}
            五段伤害|{param5:P}
            重击循环伤害|{param6:F1P}
            重击终结伤害|{param7:P}
            重击体力消耗|每秒{param8:F1}点
            最大持续时间|{param9:F1}秒
            下坠期间伤害|{param10:F1P}
            低空/高空坠地冲击伤害|{param11:P}/{param12:P}
            */
            void 北斗::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[12]{ 0.7112200260162354,0.7086399793624878,0.8832200169563293,0.8651599884033203,1.121440052986145,0.5624399781227112,1.018239974975586,40,5,0.7458779811859131,1.4914400577545166,1.862889051437378},
                        new const double[12]{ 0.7691100239753723,0.766319990158081,0.9551100134849548,0.9355800151824951,1.2127200365066528,0.6082199811935425,1.1011199951171875,40,5,0.8065890073776245,1.6128360033035278,2.0145199298858643},
                        new const double[12]{ 0.8270000219345093,0.8240000009536743,1.0269999504089355,1.00600004196167,1.3040000200271606,0.6539999842643738,1.184000015258789,40,5,0.8672999739646912,1.734233021736145,2.1661500930786133},
                        new const double[12]{ 0.9096999764442444,0.9064000248908997,1.129699945449829,1.106600046157837,1.434399962425232,0.7193999886512756,1.30239999294281,40,5,0.9540299773216248,1.907655954360962,2.382765054702759},
                        new const double[12]{ 0.9675899744033813,0.9640799760818481,1.2015899419784546,1.1770199537277222,1.5256799459457397,0.7651799917221069,1.3852800130844116,40,5,1.0147409439086914,2.0290520191192627,2.534395933151245},
                        new const double[12]{ 1.033750057220459,1.0299999713897705,1.283750057220459,1.2575000524520874,1.6299999952316284,0.8174999952316284,1.4800000190734863,40,5,1.08412504196167,2.1677908897399902,2.707688093185425},
                        new const double[12]{ 1.1247199773788452,1.1206400394439697,1.396720051765442,1.3681600093841553,1.7734400033950806,0.8894400000572205,1.6102399826049805,40,5,1.179527997970581,2.358556032180786,2.9459640979766846},
                        new const double[12]{ 1.215690016746521,1.2112799882888794,1.5096900463104248,1.4788199663162231,1.9168800115585327,0.9613800048828125,1.7404799461364746,40,5,1.2749309539794922,2.5493218898773193,3.1842410564422607},
                        new const double[12]{ 1.3066600561141968,1.3019200563430786,1.6226600408554077,1.5894800424575806,2.0603199005126953,1.0333199501037598,1.8707200288772583,40,5,1.3703340291976929,2.7400870323181152,3.4225170612335205},
                        new const double[12]{ 1.405900001525879,1.4007999897003174,1.74590003490448,1.7101999521255493,2.2167999744415283,1.111799955368042,2.0127999782562256,40,5,1.474410057067871,2.948194980621338,3.682455062866211},
                        new const double[12]{ 1.5196130275726318,1.5140999555587769,1.887112021446228,1.848525047302246,2.3961000442504883,1.2017250061035156,2.175600051879883,40,5,1.5784859657287598,3.1563029289245605,3.9423930644989014},
                        new const double[12]{ 1.6533379554748535,1.647341012954712,2.053178071975708,2.011194944381714,2.606956958770752,1.3074769973754883,2.3670530319213867,40,5,1.682561993598938,3.3644111156463623,4.202331066131592},
                        new const double[12]{ 1.7870639562606812,1.7805819511413574,2.2192440032958984,2.1738650798797607,2.8178141117095947,1.413228988647461,2.5585060119628906,40,5,1.7866380214691162,3.572519063949585,4.462268829345703},
                        new const double[12]{ 1.9207899570465088,1.913822054862976,2.385309934616089,2.336535930633545,3.028670072555542,1.5189800262451172,2.749958038330078,40,5,1.8907140493392944,3.7806270122528076,4.722207069396973},
                        new const double[12]{ 2.0666730403900146,2.059175968170166,2.5664730072021484,2.513993978500366,3.2586960792541504,1.6343460083007812,2.9588160514831543,40,5,1.994789958000183,3.9887349605560303,4.982144832611084}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******捉浪
            护盾吸收量|{param1:F1P}生命值上限+{param2:I}
            基础伤害|{param3:P}
            受击时伤害提升|{param4:P}
            冷却时间|{param5:F1}秒
            */
            void 北斗::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[5]{ 0.14399999380111694,1386.3677978515625,1.215999960899353,1.600000023841858,7.5},
                        new const double[5]{ 0.15479999780654907,1525.02392578125,1.3071999549865723,1.7200000286102295,7.5},
                        new const double[5]{ 0.1656000018119812,1675.234619140625,1.3983999490737915,1.840000033378601,7.5},
                        new const double[5]{ 0.18000000715255737,1837,1.5199999809265137,2,7.5},
                        new const double[5]{ 0.1907999962568283,2010.320068359375,1.611199975013733,2.119999885559082,7.5},
                        new const double[5]{ 0.20160000026226044,2195.19482421875,1.7023999691009521,2.240000009536743,7.5},
                        new const double[5]{ 0.2160000056028366,2391.624267578125,1.8240000009536743,2.4000000953674316,7.5},
                        new const double[5]{ 0.2303999960422516,2599.6083984375,1.9456000328063965,2.559999942779541,7.5},
                        new const double[5]{ 0.24480000138282776,2819.14697265625,2.067199945449829,2.7200000286102295,7.5},
                        new const double[5]{ 0.25920000672340393,3050.240478515625,2.188800096511841,2.880000114440918,7.5},
                        new const double[5]{ 0.2736000120639801,3292.888671875,2.3104000091552734,3.0399999618530273,7.5},
                        new const double[5]{ 0.2879999876022339,3547.09130859375,2.431999921798706,3.200000047683716,7.5},
                        new const double[5]{ 0.3059999942779541,3812.848876953125,2.5840001106262207,3.4000000953674316,7.5},
                        new const double[5]{ 0.3240000009536743,4090.160888671875,2.7360000610351562,3.5999999046325684,7.5},
                        new const double[5]{ 0.34200000762939453,4379.02783203125,2.888000011444092,3.799999952316284,7.5}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******斫雷
            技能伤害|{param1:P}
            闪雷伤害|{param2:F1P}
            伤害减免|{param3:P}
            持续时间|{param4:F1}秒
            冷却时间|{param5:F1}秒
            元素能量|{param6:I}
            */
            void 北斗::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[6]{ 1.215999960899353,0.9599999785423279,0.20000000298023224,15,20,80},
                        new const double[6]{ 1.3071999549865723,1.031999945640564,0.20999999344348907,15,20,80},
                        new const double[6]{ 1.3983999490737915,1.1039999723434448,0.2199999988079071,15,20,80},
                        new const double[6]{ 1.5199999809265137,1.2000000476837158,0.23999999463558197,15,20,80},
                        new const double[6]{ 1.611199975013733,1.2719999551773071,0.25,15,20,80},
                        new const double[6]{ 1.7023999691009521,1.343999981880188,0.25999999046325684,15,20,80},
                        new const double[6]{ 1.8240000009536743,1.440000057220459,0.2800000011920929,15,20,80},
                        new const double[6]{ 1.9456000328063965,1.5360000133514404,0.30000001192092896,15,20,80},
                        new const double[6]{ 2.067199945449829,1.6319999694824219,0.3199999928474426,15,20,80},
                        new const double[6]{ 2.188800096511841,1.7280000448226929,0.3400000035762787,15,20,80},
                        new const double[6]{ 2.3104000091552734,1.8240000009536743,0.3499999940395355,15,20,80},
                        new const double[6]{ 2.431999921798706,1.9199999570846558,0.36000001430511475,15,20,80},
                        new const double[6]{ 2.5840001106262207,2.0399999618530273,0.3700000047683716,15,20,80},
                        new const double[6]{ 2.7360000610351562,2.1600000858306885,0.3799999952316284,15,20,80},
                        new const double[6]{ 2.888000011444092,2.2799999713897705,0.38999998569488525,15,20,80}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };
        /*****北斗
        
            ***1命***
            鱼龙沉四方            
            施放❤斫雷❤时：生成一个伤害吸收量等于生命值上限16%的护盾，持续15秒。该护盾对雷元素伤害有250%的吸收效果。
            
            ***2命***
            赫赫雷涌起            
            ❤斫雷❤的闪雷能额外弹跳2个敌人。
            
            ***3命***
            潮奔蓦引电            
            ❤捉浪❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            牵星觅乡岸            
            受到攻击后的10秒内，北斗的普通攻击附带20%额外雷元素伤害。
            
            ***5命***
            踏浪霞连阶            
            ❤斫雷❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            北斗祓幽孽            
            ❤斫雷❤持续期间，周围敌人的雷元素抗性降低15%。
            
        */
         
        