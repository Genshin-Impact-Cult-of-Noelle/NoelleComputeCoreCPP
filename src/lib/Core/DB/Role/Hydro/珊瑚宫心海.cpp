#pragma once
        #include "珊瑚宫心海.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO珊瑚宫心海.cpp
        const double HP =  13470.501998988213;
        const double ATK =  234.39482610244158;
        const double DEF =  657.1140186767225;
        //水元素伤害加成
        const double OTHER = 0.2879999876022339;
        
        珊瑚宫心海::~珊瑚宫心海() {
        }
        珊瑚宫心海::珊瑚宫心海(u32* frameCur):Role(frameCur) {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Hydro, WeaponType::Catalyst);
            delete baseData;
        };        

        /*
        
        ****1:匣中玉栉
        ****************
        
            施放❤海人化羽❤时，若场上有珊瑚宫心海自己的化海月，则重置化海月的存在时间。 

        ****************
        

        ****2:真珠御呗
        ****************
        
            处于❤海人化羽❤的仪来羽衣状态下时，珊瑚宫心海的普通攻击与重击基于生命值上限造成的伤害获得额外提升，提升程度相当于她的治疗加成的15%。 

        ****************
        

        ****3:海祇姬君
        ****************
        
            队伍中自己的角色游泳消耗的体力降低20%。
            无法与效果完全相同的固有天赋叠加。 

        ****************
        

        ****4:庙算无遗
        ****************
        
            珊瑚宫心海的治疗加成提升25%，暴击率降低100%。 

        ****************
        
        */
        
            /*******普通攻击·水有常形
             * 
             * **普通攻击**
             * 以水元素幻造成的游鱼进行至多三段的攻击，造成水元素伤害。
             * 
             * **重击**
             * 消耗一定体力，短暂咏唱后，造成水元素范围伤害。
             * 
             * **下落攻击**
             * 凝聚水元素的力量，从空中下坠冲击地面，攻击下落路径上的敌人，并在落地时造成水元素范围伤害。
             * 
             * 一段伤害|{param1:F1P}
             * 二段伤害|{param2:F1P}
             * 三段伤害|{param3:F1P}
             * 重击伤害|{param4:P}
             * 重击体力消耗|{param5:F1}点
             * 下坠期间伤害|{param6:F1P}
             * 低空/高空坠地冲击伤害|{param7:P}/{param8:P}
            */
            void 珊瑚宫心海::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[8]{ 0.6837599873542786,0.6153839826583862,0.9430559873580933,1.483199954032898,50,0.5682880282402039,1.136335015296936,1.4193439483642578},
                        new const double[8]{ 0.7350419759750366,0.6615380048751831,1.0137850046157837,1.59443998336792,50,0.6145439743995667,1.228827953338623,1.534872055053711},
                        new const double[8]{ 0.7863240242004395,0.70769202709198,1.0845140218734741,1.705680012702942,50,0.6607999801635742,1.3213200569152832,1.6504000425338745},
                        new const double[8]{ 0.8547000288963318,0.7692300081253052,1.178820013999939,1.8539999723434448,50,0.7268800139427185,1.4534519910812378,1.815440058708191},
                        new const double[8]{ 0.9059820175170898,0.8153839707374573,1.2495490312576294,1.9652400016784668,50,0.7731360197067261,1.5459439754486084,1.9309680461883545},
                        new const double[8]{ 0.9572640061378479,0.8615379929542542,1.3202780485153198,2.076479911804199,50,0.8259999752044678,1.6516499519348145,2.062999963760376},
                        new const double[8]{ 1.0256400108337402,0.9230759739875793,1.4145840406417847,2.2248001098632812,50,0.898688018321991,1.7969950437545776,2.24454402923584},
                        new const double[8]{ 1.0940159559249878,0.9846140146255493,1.5088900327682495,2.373120069503784,50,0.9713760018348694,1.9423400163650513,2.4260880947113037},
                        new const double[8]{ 1.162392020225525,1.046152949333191,1.6031949520111084,2.521440029144287,50,1.0440640449523926,2.087686061859131,2.6076319217681885},
                        new const double[8]{ 1.2307679653167725,1.1076910495758057,1.6975009441375732,2.66975998878479,50,1.12336003780365,2.246243953704834,2.8056800365448},
                        new const double[8]{ 1.2991440296173096,1.1692299842834473,1.7918059825897217,2.818079948425293,50,1.2026560306549072,2.404802083969116,3.003727912902832},
                        new const double[8]{ 1.3675199747085571,1.2307679653167725,1.8861119747161865,2.966399908065796,50,1.2819520235061646,2.5633609294891357,3.2017760276794434},
                        new const double[8]{ 1.4529900550842285,1.307690978050232,2.0039939880371094,3.1517999172210693,50,1.3612480163574219,2.721919059753418,3.3998239040374756},
                        new const double[8]{ 1.5384600162506104,1.3846139907836914,2.1218760013580322,3.3371999263763428,50,1.4405440092086792,2.8804779052734375,3.597872018814087},
                        new const double[8]{ 1.6239299774169922,1.4615370035171509,2.239758014678955,3.522599935531616,50,1.5198400020599365,3.0390360355377197,3.795919895172119}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******海月之誓
             * 
             * 召唤能够治愈同伴的幻造水之生命「化海月」。
             * 施放的瞬间，为珊瑚宫心海施加潮湿状态。
             * 
             * **化海月**
             * 每隔一段时间，对周围的敌人造成水元素伤害，并为周围的当前场上角色恢复生命值，回复量受益于珊瑚宫心海的生命值上限。
             * 
             * 治疗量|{param1:F1P}生命值上限+{param2:I}
             * 波纹伤害|{param3:F1P}
             * 存在时间|{param4:F1}秒
             * 冷却时间|{param5:F1}秒
            */
            void 珊瑚宫心海::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[5]{ 0.04399999976158142,423.706298828125,1.0919040441513062,12,20},
                        new const double[5]{ 0.04729999974370003,466.08282470703125,1.1737970113754272,12,20},
                        new const double[5]{ 0.050599999725818634,511.99072265625,1.2556899785995483,12,20},
                        new const double[5]{ 0.054999999701976776,561.4299926757812,1.3648799657821655,12,20},
                        new const double[5]{ 0.05829999968409538,614.400634765625,1.4467730522155762,12,20},
                        new const double[5]{ 0.06159999966621399,670.9026489257812,1.5286660194396973,12,20},
                        new const double[5]{ 0.06599999964237213,730.9360961914062,1.6378560066223145,12,20},
                        new const double[5]{ 0.07039999961853027,794.5008544921875,1.7470459938049316,12,20},
                        new const double[5]{ 0.07479999959468842,861.5970458984375,1.8562370538711548,12,20},
                        new const double[5]{ 0.07919999957084656,932.2245483398438,1.965427041053772,12,20},
                        new const double[5]{ 0.0835999995470047,1006.3834838867188,2.074618101119995,12,20},
                        new const double[5]{ 0.08799999952316284,1084.07373046875,2.1838080883026123,12,20},
                        new const double[5]{ 0.09350000321865082,1165.29541015625,2.320296049118042,12,20},
                        new const double[5]{ 0.0989999994635582,1250.0484619140625,2.4567840099334717,12,20},
                        new const double[5]{ 0.10450000315904617,1338.3328857421875,2.5932719707489014,12,20}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******海人化羽
             * 
             * 请降海祇的力量，对周围的敌人造成水元素伤害，并披上珊瑚宫之水汇聚而成的「仪来羽衣」。
             * 
             * **仪来羽衣**
             * ·增加珊瑚宫心海的普通攻击，重击以及元素战技的「化海月」造成的伤害，增加值基于珊瑚宫心海的生命值上限；
             * ·普通攻击和重击命中敌人时，为队伍中附近的所有角色恢复生命值，回复量受益于珊瑚宫心海的生命值上限；
             * ·提升珊瑚宫心海的抗打断能力，并使她能在水面上移动。
             * 
             * 效果将在珊瑚宫心海退场时解除。
             * 
             * 技能伤害|{param1:F1P}生命值上限
             * 普通攻击伤害提升|{param4:F1P}生命值上限
             * 重击伤害提升|{param5:F1P}生命值上限
             * 化海月伤害提升|{param9:F1P}生命值上限
             * 命中治疗量|{param2:F2P}生命值上限+{param3:I}
             * 持续时间|{param6:F1}秒
             * 冷却时间|{param7:F1}秒
             * 元素能量|{param8:I}
            */
            void 珊瑚宫心海::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[9]{ 0.10416000336408615,0.008080000057816505,77.0373764038086,0.04839999973773956,0.06775999814271927,10,18,70,0.07096300274133682},
                        new const double[9]{ 0.11197199672460556,0.008685999549925327,84.74217987060547,0.05203000083565712,0.07284200191497803,10,18,70,0.0762849971652031},
                        new const double[9]{ 0.11978399753570557,0.009291999973356724,93.08905792236328,0.05565999820828438,0.07792399823665619,10,18,70,0.08160799741744995},
                        new const double[9]{ 0.13019999861717224,0.010099999606609344,102.0780029296875,0.060499999672174454,0.08470000326633453,10,18,70,0.08870399743318558},
                        new const double[9]{ 0.13801200687885284,0.010706000030040741,111.7090072631836,0.06413000077009201,0.0897819995880127,10,18,70,0.09402599930763245},
                        new const double[9]{ 0.14582400023937225,0.011312000453472137,121.98208618164062,0.06775999814271927,0.09486400336027145,10,18,70,0.09934800118207932},
                        new const double[9]{ 0.15624000132083893,0.012120000086724758,132.89723205566406,0.07259999960660934,0.1016400009393692,10,18,70,0.10644499957561493},
                        new const double[9]{ 0.1666560024023056,0.012927999719977379,144.45445251464844,0.07744000107049942,0.10841599851846695,10,18,70,0.11354099959135056},
                        new const double[9]{ 0.17707200348377228,0.013736000284552574,156.6537322998047,0.0822800025343895,0.1151920035481453,10,18,70,0.12063699960708618},
                        new const double[9]{ 0.18748800456523895,0.014543999917805195,169.4950714111328,0.08711999654769897,0.12196800112724304,10,18,70,0.1277340054512024},
                        new const double[9]{ 0.19790400564670563,0.015351999551057816,182.97848510742188,0.09195999801158905,0.1287440061569214,10,18,70,0.13482999801635742},
                        new const double[9]{ 0.2083200067281723,0.01616000011563301,197.10397338867188,0.09679999947547913,0.13551999628543854,10,18,70,0.14192600548267365},
                        new const double[9]{ 0.22134000062942505,0.017170000821352005,211.87152099609375,0.10284999758005142,0.14398999512195587,10,18,70,0.15079699456691742},
                        new const double[9]{ 0.2343599945306778,0.01817999966442585,227.2811279296875,0.10890000313520432,0.1524599939584732,10,18,70,0.1596670001745224},
                        new const double[9]{ 0.24738000333309174,0.019190000370144844,243.3328094482422,0.11495000123977661,0.16092999279499054,10,18,70,0.16853800415992737}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };
        /*****珊瑚宫心海
        
            ***1命***
            决水于溪            
            处于❤海人化羽❤的仪来羽衣状态下时，珊瑚宫心海普通攻击的最后一击会额外释放一只游鱼，造成相当于珊瑚宫心海生命值上限30%的水元素伤害。该伤害不被视为普通攻击伤害。
            
            ***2命***
            波起云海            
            基于珊瑚宫心海的生命值上限，珊瑚宫心海对生命值低于或等于50%的角色，通过以下途径进行治疗的回复量获得提升：·❤海月之誓❤的化海月：生命值上限的4.5%·❤海人化羽❤的普通攻击与重击：生命值上限的0.6%。
            
            ***3命***
            海渚月舟            
            ❤海人化羽❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            月摄千川            
            处于❤海人化羽❤的仪来羽衣状态下时，珊瑚宫心海普通攻击的攻击速度提升10%，并会在普通攻击命中敌人时，恢复0.8点元素能量。该效果每0.2秒至多触发一次。
            
            ***5命***
            百川集海            
            ❤海月之誓❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            珊瑚一心            
            处于❤海人化羽❤的仪来羽衣状态下时，珊瑚宫心海的普通攻击和重击对生命值高于或等于80%的角色进行治疗时，将获得40%水元素伤害加成，持续4秒。
            
        */
         
        