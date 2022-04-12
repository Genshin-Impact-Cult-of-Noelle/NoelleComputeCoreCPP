﻿#pragma once
        #include "甘雨.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO甘雨.cpp
        const double HP =  9796.729009273928;
        const double ATK =  334.84974830517604;
        const double DEF =  630.2146005977265;
        //暴击伤害
        const double OTHER = 0.8840000033378601;
        
        甘雨::~甘雨() {
        }
        甘雨::甘雨(u32* frameCur):Role(frameCur) {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Cryo, WeaponType::Bow);
            delete baseData;
        };        

        /*
        
        ****1:唯此一心
        ****************
        
            霜华矢发射后的5秒内，会使接下来的发射的霜华矢与这些霜华矢引发的霜华绽发的暴击率提高20%。 

        ****************
        

        ****2:天地交泰
        ****************
        
            ❤降众天华❤领域内的队伍中当前场上角色获得20%冰元素伤害加成。 

        ****************
        

        ****3:藏弓待用
        ****************
        
            锻造弓类武器时，返还15%消耗的矿石。 

        ****************
        
        */
        
            /*******普通攻击·流天射术
             * 
             * **普通攻击**
             * 进行至多六段的连续弓箭射击。
             * 
             * **重击**
             * 进行伤害更高、更为精准的**瞄准射击**。
             * 瞄准时，冰寒之气会在箭矢上持续积聚，并随攻击发射出去。根据蓄力时间长短，能造成不同的效果：
             * ·一段蓄力：射出附有寒气的箭矢，造成冰元素伤害；
             * ·二段蓄力：发射霜华矢，造成冰元素伤害；命中后霜华绽发，再次造成冰元素范围伤害。
             * 
             * **下落攻击**
             * 从空中射出箭雨，并迅速下坠冲击地面，在落地时造成范围伤害。
             * 
             * 一段伤害|{param1:F1P}
             * 二段伤害|{param2:F1P}
             * 三段伤害|{param3:F1P}
             * 四段伤害|{param4:F1P}
             * 五段伤害|{param5:F1P}
             * 六段伤害|{param6:F1P}
             * 瞄准射击|{param7:F1P}
             * 一段蓄力瞄准射击|{param8:P}
             * 霜华矢命中伤害|{param9:P}
             * 霜华矢·霜华绽发伤害|{param10:P}
             * 下坠期间伤害|{param11:F1P}
             * 低空/高空坠地冲击伤害|{param12:P}/{param13:P}
            */
            void 甘雨::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[13]{ 0.3173399865627289,0.35604000091552734,0.45493999123573303,0.45493999123573303,0.48245999217033386,0.576200008392334,0.43860000371932983,1.2400000095367432,1.2799999713897705,2.1760001182556152,0.5682880282402039,1.136335015296936,1.4193439483642578},
                        new const double[13]{ 0.3431699872016907,0.385019987821579,0.4919700026512146,0.4919700026512146,0.5217300057411194,0.6230999827384949,0.47429999709129333,1.3329999446868896,1.3760000467300415,2.339200019836426,0.6145439743995667,1.228827953338623,1.534872055053711},
                        new const double[13]{ 0.36899998784065247,0.414000004529953,0.5289999842643738,0.5289999842643738,0.5609999895095825,0.6700000166893005,0.5099999904632568,1.4259999990463257,1.472000002861023,2.5023999214172363,0.6607999801635742,1.3213200569152832,1.6504000425338745},
                        new const double[13]{ 0.4059000015258789,0.4553999900817871,0.5819000005722046,0.5819000005722046,0.6171000003814697,0.7369999885559082,0.5609999895095825,1.5499999523162842,1.600000023841858,2.7200000286102295,0.7268800139427185,1.4534519910812378,1.815440058708191},
                        new const double[13]{ 0.4317300021648407,0.48438000679016113,0.6189299821853638,0.6189299821853638,0.6563699841499329,0.7839000225067139,0.5967000126838684,1.6430000066757202,1.6959999799728394,2.88319993019104,0.7731360197067261,1.5459439754486084,1.9309680461883545},
                        new const double[13]{ 0.4612500071525574,0.5174999833106995,0.6612499952316284,0.6612499952316284,0.7012500166893005,0.8374999761581421,0.637499988079071,1.7359999418258667,1.7920000553131104,3.0464000701904297,0.8259999752044678,1.6516499519348145,2.062999963760376},
                        new const double[13]{ 0.5018399953842163,0.563040018081665,0.7194399833679199,0.7194399833679199,0.7629600167274475,0.9111999869346619,0.6935999989509583,1.8600000143051147,1.9199999570846558,3.2639999389648438,0.898688018321991,1.7969950437545776,2.24454402923584},
                        new const double[13]{ 0.5424299836158752,0.6085799932479858,0.7776299715042114,0.7776299715042114,0.8246700167655945,0.9848999977111816,0.7497000098228455,1.9839999675750732,2.0480000972747803,3.481600046157837,0.9713760018348694,1.9423400163650513,2.4260880947113037},
                        new const double[13]{ 0.5830199718475342,0.6541200280189514,0.8358200192451477,0.8358200192451477,0.8863800168037415,1.0585999488830566,0.8058000206947327,2.1080000400543213,2.1760001182556152,3.699199914932251,1.0440640449523926,2.087686061859131,2.6076319217681885},
                        new const double[13]{ 0.6273000240325928,0.7038000226020813,0.8992999792098999,0.8992999792098999,0.9537000060081482,1.1390000581741333,0.8669999837875366,2.2320001125335693,2.303999900817871,3.916800022125244,1.12336003780365,2.246243953704834,2.8056800365448},
                        new const double[13]{ 0.6780369877815247,0.7607250213623047,0.9720379710197449,0.9720379710197449,1.0308380126953125,1.231124997138977,0.9282000064849854,2.3559999465942383,2.431999921798706,4.134399890899658,1.2026560306549072,2.404802083969116,3.003727912902832},
                        new const double[13]{ 0.7377049922943115,0.8276690244674683,1.0575770139694214,1.0575770139694214,1.1215510368347168,1.3394639492034912,0.9894000291824341,2.4800000190734863,2.559999942779541,4.3520002365112305,1.2819520235061646,2.5633609294891357,3.2017760276794434},
                        new const double[13]{ 0.7973719835281372,0.8946130275726318,1.1431159973144531,1.1431159973144531,1.2122650146484375,1.447803020477295,1.0506000518798828,2.634999990463257,2.7200000286102295,4.624000072479248,1.3612480163574219,2.721919059753418,3.3998239040374756},
                        new const double[13]{ 0.8570389747619629,0.9615560173988342,1.2286549806594849,1.2286549806594849,1.3029789924621582,1.556141972541809,1.111799955368042,2.7899999618530273,2.880000114440918,4.895999908447266,1.4405440092086792,2.8804779052734375,3.597872018814087},
                        new const double[13]{ 0.9221310019493103,1.034585952758789,1.32197105884552,1.32197105884552,1.401939034461975,1.6743299961090088,1.1729999780654907,2.944999933242798,3.0399999618530273,5.168000221252441,1.5198400020599365,3.0390360355377197,3.795919895172119}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******山泽麟迹
             * 
             * 甘雨留下一朵冰莲并迅速后退，远离一切魑魅魍魉，造成冰元素范围伤害。
             * 
             * **冰莲**
             * ·持续嘲讽周围的敌人，吸引敌人攻击；
             * ·耐久度按比例继承甘雨的生命值上限；
             * ·被摧毁或持续时间结束时，会剧烈地绽放，造成冰元素范围伤害。
             * 
             * 继承生命|{param1:P}
             * 技能伤害|{param2:P}
             * 持续时间|{param3:F1}秒
             * 冷却时间|{param4:F1}秒
            */
            void 甘雨::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[4]{ 1.2000000476837158,1.3200000524520874,6,10},
                        new const double[4]{ 1.2899999618530273,1.4190000295639038,6,10},
                        new const double[4]{ 1.3799999952316284,1.5180000066757202,6,10},
                        new const double[4]{ 1.5,1.649999976158142,6,10},
                        new const double[4]{ 1.590000033378601,1.7489999532699585,6,10},
                        new const double[4]{ 1.6799999475479126,1.8480000495910645,6,10},
                        new const double[4]{ 1.7999999523162842,1.9800000190734863,6,10},
                        new const double[4]{ 1.9199999570846558,2.111999988555908,6,10},
                        new const double[4]{ 2.0399999618530273,2.24399995803833,6,10},
                        new const double[4]{ 2.1600000858306885,2.375999927520752,6,10},
                        new const double[4]{ 2.2799999713897705,2.507999897003174,6,10},
                        new const double[4]{ 2.4000000953674316,2.640000104904175,6,10},
                        new const double[4]{ 2.549999952316284,2.805000066757202,6,10},
                        new const double[4]{ 2.700000047683716,2.9700000286102295,6,10},
                        new const double[4]{ 2.8499999046325684,3.134999990463257,6,10}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******降众天华
             * 
             * 凝聚大气中的霜雪，召唤退魔的冰灵珠。
             * 存在期间内，冰灵珠会持续降下冰棱，攻击范围内的敌人，造成冰元素伤害。
             * 
             * 冰棱伤害|{param1:P}
             * 持续时间|{param2:F1}秒
             * 冷却时间|{param3:F1}秒
             * 元素能量|{param4:I}
            */
            void 甘雨::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[4]{ 0.7027199864387512,15,15,60},
                        new const double[4]{ 0.7554240226745605,15,15,60},
                        new const double[4]{ 0.8081279993057251,15,15,60},
                        new const double[4]{ 0.8784000277519226,15,15,60},
                        new const double[4]{ 0.9311040043830872,15,15,60},
                        new const double[4]{ 0.9838079810142517,15,15,60},
                        new const double[4]{ 1.0540800094604492,15,15,60},
                        new const double[4]{ 1.124351978302002,15,15,60},
                        new const double[4]{ 1.1946239471435547,15,15,60},
                        new const double[4]{ 1.264896035194397,15,15,60},
                        new const double[4]{ 1.3351680040359497,15,15,60},
                        new const double[4]{ 1.4054399728775024,15,15,60},
                        new const double[4]{ 1.493280053138733,15,15,60},
                        new const double[4]{ 1.5811200141906738,15,15,60},
                        new const double[4]{ 1.6689599752426147,15,15,60}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };
        /*****甘雨
        
            ***1命***
            饮露            
            二段蓄力重击的霜华矢或霜华绽发命中敌人时，会使敌人的冰元素抗性降低15%，持续6秒；此外，命中时会为甘雨恢复2点元素能量。每次二段蓄力重击只能触发一次元素能量恢复效果，无论霜华矢或霜华绽发是否都命中目标。
            
            ***2命***
            获麟            
            ❤山泽麟迹❤的可使用次数增加1次。
            
            ***3命***
            云行            
            ❤降众天华❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            西狩            
            在❤降众天华❤的领域内，敌人受到的伤害会增加，这个效果会随时间逐步加强。受伤害加成初始为5%，每3秒提升5%，至多提升至25%。离开领域后，效果至多持续3秒。
            
            ***5命***
            折草            
            ❤山泽麟迹❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            履虫            
            施放❤山泽麟迹❤后30秒内的第一次霜华矢，无需蓄力即可施放。
            
        */
         
        