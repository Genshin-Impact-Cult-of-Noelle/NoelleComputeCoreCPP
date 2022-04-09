﻿#pragma once
        #include "阿贝多.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO阿贝多.cpp
        const double HP =  13225.583793659927;
        const double ATK =  251.13731313623066;
        const double DEF =  876.1519925053435;
        //岩元素伤害加成
        const double OTHER = 0.2879999876022339;
        
        阿贝多::~阿贝多() {
        }
        阿贝多::阿贝多(u32* frameCur) {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Male, CharacterGroup::Tivat, ElementType::Geo, WeaponType::Sword);
            delete baseData;
        };        

        /*
        
        ****1:白垩色的威压
        ****************
        
            ❤创生法·拟造阳华❤的刹那之花对生命值低于50%的敌人造成的伤害提高25%。 

        ****************
        

        ****2:瓶中人的天慧
        ****************
        
            施放❤诞生式·大地之潮❤时，使附近的队伍中角色的元素精通提高125点，持续10秒。 

        ****************
        

        ****3:天才的发现
        ****************
        
            合成武器突破素材时，有10%概率获得2倍产出。 

        ****************
        
        */
        
            /*******普通攻击·西风剑术·白
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
            void 阿贝多::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[11]{ 0.36739200353622437,0.36739200353622437,0.47454801201820374,0.49750998616218567,0.6207389831542969,0.4729999899864197,0.6019999980926514,20,0.6393240094184875,1.2783770561218262,1.59676194190979},
                        new const double[11]{ 0.3972960114479065,0.3972960114479065,0.5131739974021912,0.538004994392395,0.6712650060653687,0.5115000009536743,0.6510000228881836,20,0.6913620233535767,1.3824310302734375,1.7267309427261353},
                        new const double[11]{ 0.42719998955726624,0.42719998955726624,0.551800012588501,0.578499972820282,0.7217900156974792,0.550000011920929,0.699999988079071,20,0.743399977684021,1.4864850044250488,1.8566999435424805},
                        new const double[11]{ 0.46992000937461853,0.46992000937461853,0.60698002576828,0.6363499760627747,0.7939689755439758,0.6050000190734863,0.7699999809265137,20,0.8177400231361389,1.635133981704712,2.042370080947876},
                        new const double[11]{ 0.49982398748397827,0.49982398748397827,0.6456059813499451,0.6768450140953064,0.8444939851760864,0.6434999704360962,0.8190000057220459,20,0.8697779774665833,1.7391870021820068,2.1723389625549316},
                        new const double[11]{ 0.5339999794960022,0.5339999794960022,0.6897500157356262,0.7231249809265137,0.9022380113601685,0.6875,0.875,20,0.9292500019073486,1.858106017112732,2.3208749294281006},
                        new const double[11]{ 0.5809919834136963,0.5809919834136963,0.7504479885101318,0.7867599725723267,0.9816340208053589,0.7480000257492065,0.9520000219345093,20,1.011023998260498,2.021620035171509,2.5251119136810303},
                        new const double[11]{ 0.6279839873313904,0.6279839873313904,0.8111460208892822,0.8503950238227844,1.0610309839248657,0.8084999918937683,1.0290000438690186,20,1.0927979946136475,2.1851329803466797,2.72934889793396},
                        new const double[11]{ 0.6749759912490845,0.6749759912490845,0.8718439936637878,0.9140300154685974,1.1404279470443726,0.8690000176429749,1.1059999465942383,20,1.1745719909667969,2.3486459255218506,2.9335858821868896},
                        new const double[11]{ 0.7262399792671204,0.7262399792671204,0.9380599856376648,0.9834499955177307,1.2270430326461792,0.9350000023841858,1.190000057220459,20,1.2637799978256226,2.527024984359741,3.1563899517059326},
                        new const double[11]{ 0.7849799990653992,0.7849799990653992,1.0139319896697998,1.0629940032958984,1.3262890577316284,1.0106250047683716,1.2862499952316284,20,1.3529880046844482,2.7054030895233154,3.3791940212249756},
                        new const double[11]{ 0.854058027267456,0.854058027267456,1.103158950805664,1.1565370559692383,1.4430030584335327,1.099560022354126,1.399440050125122,20,1.442196011543274,2.8837809562683105,3.6019980907440186},
                        new const double[11]{ 0.9231359958648682,0.9231359958648682,1.192384958267212,1.250080943107605,1.559715986251831,1.1884950399398804,1.5126299858093262,20,1.5314040184020996,3.0621590614318848,3.8248019218444824},
                        new const double[11]{ 0.9922149777412415,0.9922149777412415,1.2816109657287598,1.3436239957809448,1.676429033279419,1.2774300575256348,1.6258200407028198,20,1.6206120252609253,3.24053692817688,4.047605991363525},
                        new const double[11]{ 1.0675729513168335,1.0675729513168335,1.3789479732513428,1.4456709623336792,1.8037530183792114,1.3744499683380127,1.7493000030517578,20,1.709820032119751,3.418915033340454,4.270410060882568}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******创生法·拟造阳华
            技能伤害|{param1:P}
            刹那之花伤害|{param2:P}防御力
            持续时间|{param3:F1}秒
            技能冷却|{param4:F1}秒
            */
            void 阿贝多::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[4]{ 1.3040000200271606,1.3359999656677246,30,4},
                        new const double[4]{ 1.4018000364303589,1.4362000226974487,30,4},
                        new const double[4]{ 1.4996000528335571,1.5363999605178833,30,4},
                        new const double[4]{ 1.6299999952316284,1.6699999570846558,30,4},
                        new const double[4]{ 1.7278000116348267,1.7702000141143799,30,4},
                        new const double[4]{ 1.825600028038025,1.8703999519348145,30,4},
                        new const double[4]{ 1.9559999704360962,2.003999948501587,30,4},
                        new const double[4]{ 2.086400032043457,2.1375999450683594,30,4},
                        new const double[4]{ 2.2167999744415283,2.271199941635132,30,4},
                        new const double[4]{ 2.3471999168395996,2.4047999382019043,30,4},
                        new const double[4]{ 2.47760009765625,2.5383999347686768,30,4},
                        new const double[4]{ 2.6080000400543213,2.671999931335449,30,4},
                        new const double[4]{ 2.7709999084472656,2.8389999866485596,30,4},
                        new const double[4]{ 2.934000015258789,3.00600004196167,30,4},
                        new const double[4]{ 3.0969998836517334,3.1730000972747803,30,4}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******诞生式·大地之潮
            爆发伤害|{param1:P}
            生灭之花伤害|每朵{param2:F1P}
            冷却时间|{param3:F1}秒
            元素能量|{param4:I}
            */
            void 阿贝多::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[4]{ 3.671999931335449,0.7200000286102295,12,40},
                        new const double[4]{ 3.9474000930786133,0.7739999890327454,12,40},
                        new const double[4]{ 4.222799777984619,0.828000009059906,12,40},
                        new const double[4]{ 4.590000152587891,0.8999999761581421,12,40},
                        new const double[4]{ 4.8653998374938965,0.9539999961853027,12,40},
                        new const double[4]{ 5.1407999992370605,1.0080000162124634,12,40},
                        new const double[4]{ 5.507999897003174,1.0800000429153442,12,40},
                        new const double[4]{ 5.875199794769287,1.1519999504089355,12,40},
                        new const double[4]{ 6.242400169372559,1.2239999771118164,12,40},
                        new const double[4]{ 6.609600067138672,1.2960000038146973,12,40},
                        new const double[4]{ 6.976799964904785,1.3680000305175781,12,40},
                        new const double[4]{ 7.343999862670898,1.440000057220459,12,40},
                        new const double[4]{ 7.802999973297119,1.5299999713897705,12,40},
                        new const double[4]{ 8.26200008392334,1.6200000047683716,12,40},
                        new const double[4]{ 8.720999717712402,1.7100000381469727,12,40}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };
        /*****阿贝多
        
            ***1命***
            伊甸之花            
            阿贝多的❤创生法·拟造阳华❤生成的刹那之花绽放时，为阿贝多自己回复1.2点元素能量。
            
            ***2命***
            显生之宙            
            ❤创生法·拟造阳华❤的刹那之花绽放时，会为阿贝多赋予生灭计数效果，持续30秒：·施放❤诞生式·大地之潮❤时，清除所有生灭计数效果，并根据清除的层数，提高诞生式·大地之潮的爆发伤害与生灭之花造成的伤害；·每层生灭计数，会提高等同于阿贝多防御力的30%的伤害；·该效果至多叠加4次。
            
            ***3命***
            太阳之华            
            ❤创生法·拟造阳华❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            神性之陨            
            处于阳华的领域中的队伍中当前场上角色，造成的下落攻击伤害提高30%。
            
            ***5命***
            冥古之潮            
            ❤诞生式·大地之潮❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            无垢之土            
            处在阳华的领域中的队伍中当前场上角色，若处于结晶反应产生的护盾庇护下，造成的伤害提高17%。
            
        */
         
        