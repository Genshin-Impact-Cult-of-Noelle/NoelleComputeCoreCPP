﻿#pragma once
        #include "芭芭拉.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO芭芭拉.cpp
        const double HP =  9787.423311600985;
        const double ATK =  159.29789376111603;
        const double DEF =  668.8711049900703;
        //生命值
        const double OTHER = 0.23999999463558197;
        
        芭芭拉::~芭芭拉() {
        }
        芭芭拉::芭芭拉(u32* frameCur):Role(frameCur) {
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
        
        ****1:光辉的季节
        ****************
        
            角色在❤演唱，开始♪❤的歌声之环中时，体力消耗降低12%。 

        ****************
        

        ****2:安可
        ****************
        
            当前场上自己的角色获得元素晶球或元素微粒时，延长❤演唱，开始♪❤歌声之环持续时间1秒。
            通过这种方式，至多延长5秒。 

        ****************
        

        ****3:心意♪注入
        ****************
        
            完美烹饪恢复类食物时，有12%概率获得2倍产出。 

        ****************
        
        */
        
            /*******普通攻击·水之浅唱
             * 
             * **普通攻击**
             * 进行至多四段的水花攻击，造成水元素伤害。
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
             * 四段伤害|{param4:F1P}
             * 重击伤害|{param5:P}
             * 重击体力消耗|{param6:F1}点
             * 下坠期间伤害|{param7:F1P}
             * 低空/高空坠地冲击伤害|{param8:P}/{param9:P}
            */
            void 芭芭拉::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[9]{ 0.3783999979496002,0.35519999265670776,0.41040000319480896,0.5519999861717224,1.6624000072479248,50,0.5682880282402039,1.136335015296936,1.4193439483642578},
                        new const double[9]{ 0.4067800045013428,0.3818399906158447,0.4411799907684326,0.5934000015258789,1.7870800495147705,50,0.6145439743995667,1.228827953338623,1.534872055053711},
                        new const double[9]{ 0.4351600110530853,0.4084799885749817,0.47196000814437866,0.6348000168800354,1.9117599725723267,50,0.6607999801635742,1.3213200569152832,1.6504000425338745},
                        new const double[9]{ 0.4729999899864197,0.4440000057220459,0.5130000114440918,0.6899999976158142,2.078000068664551,50,0.7268800139427185,1.4534519910812378,1.815440058708191},
                        new const double[9]{ 0.5013800263404846,0.47064000368118286,0.5437800288200378,0.7314000129699707,2.2026801109313965,50,0.7731360197067261,1.5459439754486084,1.9309680461883545},
                        new const double[9]{ 0.5297600030899048,0.4972800016403198,0.5745599865913391,0.7728000283241272,2.327359914779663,50,0.8259999752044678,1.6516499519348145,2.062999963760376},
                        new const double[9]{ 0.5676000118255615,0.532800018787384,0.6155999898910522,0.828000009059906,2.4935998916625977,50,0.898688018321991,1.7969950437545776,2.24454402923584},
                        new const double[9]{ 0.6054400205612183,0.5683199763298035,0.6566399931907654,0.8831999897956848,2.6598401069641113,50,0.9713760018348694,1.9423400163650513,2.4260880947113037},
                        new const double[9]{ 0.643280029296875,0.6038399934768677,0.6976799964904785,0.9383999705314636,2.826080083847046,50,1.0440640449523926,2.087686061859131,2.6076319217681885},
                        new const double[9]{ 0.681119978427887,0.6393600106239319,0.7387199997901917,0.9936000108718872,2.9923200607299805,50,1.12336003780365,2.246243953704834,2.8056800365448},
                        new const double[9]{ 0.7204740047454834,0.6763010025024414,0.7814019918441772,1.0510079860687256,3.165210008621216,50,1.2026560306549072,2.404802083969116,3.003727912902832},
                        new const double[9]{ 0.7719359993934631,0.7246080040931702,0.8372160196304321,1.12608003616333,3.391295909881592,50,1.2819520235061646,2.5633609294891357,3.2017760276794434},
                        new const double[9]{ 0.8233979940414429,0.7729150056838989,0.8930299878120422,1.201151967048645,3.617382049560547,50,1.3612480163574219,2.721919059753418,3.3998239040374756},
                        new const double[9]{ 0.8748610019683838,0.8212220072746277,0.9488450288772583,1.2762240171432495,3.8434689044952393,50,1.4405440092086792,2.8804779052734375,3.597872018814087},
                        new const double[9]{ 0.9263229966163635,0.8695300221443176,1.0046590566635132,1.3512959480285645,4.069554805755615,50,1.5198400020599365,3.0390360355377197,3.795919895172119}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******演唱，开始♪
             * 
             * 唤出歌声般跃动的水珠，形成歌声之环，对周围的敌人造成水元素伤害，并施加潮湿状态。
             * 
             * **歌声之环**
             * ·芭芭拉的普通攻击命中时，为队伍中自己的角色，以及附近的友方角色恢复生命值，回复量受益于芭芭拉的生命值上限；
             * ·重击命中时，能产生4倍回复量；
             * ·每隔一段时间，为当前场上自己的角色恢复生命值；
             * ·对角色与触及的敌人施加潮湿状态。
             * 
             * 命中治疗量|{param3:F2P}生命值上限+{param4:I}
             * 持续治疗量|{param1:F2P}生命值上限+{param2:I}
             * 水珠伤害|{param5:F1P}
             * 持续时间|{param6:F1}秒
             * 冷却时间|{param7:F1}秒
            */
            void 芭芭拉::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[7]{ 0.03999999910593033,385.187744140625,0.007499999832361937,72.22270202636719,0.5839999914169312,15,32},
                        new const double[7]{ 0.0430000014603138,423.7118835449219,0.008062999695539474,79.44597625732422,0.6277999877929688,15,32},
                        new const double[7]{ 0.04600000008940697,465.44635009765625,0.008624999783933163,87.27119445800781,0.6715999841690063,15,32},
                        new const double[7]{ 0.05000000074505806,510.39117431640625,0.00937500037252903,95.6983413696289,0.7300000190734863,15,32},
                        new const double[7]{ 0.05299999937415123,558.5463256835938,0.00993799977004528,104.72743225097656,0.7738000154495239,15,32},
                        new const double[7]{ 0.0560000017285347,609.9118041992188,0.010499999858438969,114.35846710205078,0.8176000118255615,15,32},
                        new const double[7]{ 0.05999999865889549,664.4876708984375,0.011250000447034836,124.59143829345703,0.8759999871253967,15,32},
                        new const double[7]{ 0.06400000303983688,722.2738647460938,0.012000000104308128,135.4263458251953,0.9344000220298767,15,32},
                        new const double[7]{ 0.06800000369548798,783.2703857421875,0.012749999761581421,146.8632049560547,0.9927999973297119,15,32},
                        new const double[7]{ 0.07199999690055847,847.477294921875,0.013500000350177288,158.90199279785156,1.051200032234192,15,32},
                        new const double[7]{ 0.07599999755620956,914.89453125,0.01425000000745058,171.542724609375,1.1095999479293823,15,32},
                        new const double[7]{ 0.07999999821186066,985.5220947265625,0.014999999664723873,184.78538513183594,1.1679999828338623,15,32},
                        new const double[7]{ 0.08500000089406967,1059.3599853515625,0.01593800075352192,198.6300048828125,1.2410000562667847,15,32},
                        new const double[7]{ 0.09000000357627869,1136.408203125,0.016875000670552254,213.07655334472656,1.3140000104904175,15,32},
                        new const double[7]{ 0.0949999988079071,1216.6668701171875,0.017812000587582588,228.12503051757812,1.3869999647140503,15,32}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******闪耀奇迹♪
             * 
             * 为附近的友方角色及队伍中自己的角色恢复大量生命值，回复量受益于芭芭拉的生命值上限。
             * 
             * 治疗量|{param1:F1P}生命值上限+{param2:I}
             * 冷却时间|{param3:F1}秒
             * 元素能量|{param4:I}
            */
            void 芭芭拉::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[4]{ 0.17599999904632568,1694.2818603515625,20,80},
                        new const double[4]{ 0.1891999989748001,1863.733642578125,20,80},
                        new const double[4]{ 0.20239999890327454,2047.3062744140625,20,80},
                        new const double[4]{ 0.2199999988079071,2245,20,80},
                        new const double[4]{ 0.23319999873638153,2456.814697265625,20,80},
                        new const double[4]{ 0.24639999866485596,2682.750244140625,20,80},
                        new const double[4]{ 0.2639999985694885,2922.806884765625,20,80},
                        new const double[4]{ 0.2815999984741211,3176.984619140625,20,80},
                        new const double[4]{ 0.29919999837875366,3445.283203125,20,80},
                        new const double[4]{ 0.31679999828338623,3727.70263671875,20,80},
                        new const double[4]{ 0.3343999981880188,4024.2431640625,20,80},
                        new const double[4]{ 0.35199999809265137,4334.90478515625,20,80},
                        new const double[4]{ 0.37400001287460327,4659.68701171875,20,80},
                        new const double[4]{ 0.3959999978542328,4998.5908203125,20,80},
                        new const double[4]{ 0.4180000126361847,5351.615234375,20,80}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };
        /*****芭芭拉
        
            ***1命***
            彩色歌谣            
            芭芭拉每10秒恢复1点元素能量。
            
            ***2命***
            元气迸发            
            ❤演唱，开始♪❤的冷却时间降低15%；技能持续期间，当前场上自己的角色获得15%水元素伤害加成。
            
            ***3命***
            明日之星            
            ❤闪耀奇迹♪❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            努力即魔法            
            芭芭拉使用重击时，每命中一个敌人，就恢复1点元素能量。通过这种方式，一次至多回复5点元素能量。
            
            ***5命***
            纯真的羁绊            
            ❤演唱，开始♪❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            将一切美好献给你            
            芭芭拉处于队伍后台时，队伍中自己的角色倒下时，则立即：·复苏该角色；·将该角色生命值恢复至100%。该效果每15分钟只能触发一次。
            
        */
         
        