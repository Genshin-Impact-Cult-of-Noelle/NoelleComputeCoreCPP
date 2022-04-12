﻿#pragma once
        #include "神里绫华.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO神里绫华.cpp
        const double HP =  12858.207019053749;
        const double ATK =  342.0250962186219;
        const double DEF =  783.9254743546844;
        //暴击伤害
        const double OTHER = 0.8840000033378601;
        
        神里绫华::~神里绫华() {
        }
        神里绫华::神里绫华(u32* frameCur):Role(frameCur) {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Cryo, WeaponType::Sword);
            delete baseData;
        };        

        /*
        
        ****1:天罪国罪镇词
        ****************
        
            施放❤神里流·冰华❤后的6秒内，神里绫华的普通攻击与重击造成的伤害提升30%。 

        ****************
        

        ****2:寒天宣命祝词
        ****************
        
            ❤神里流·霰步❤结束时释放的寒冰命中了敌人时，神里绫华将获得如下效果：
            ·恢复10点体力；
            ·获得18%冰元素伤害加成，持续10秒。 

        ****************
        

        ****3:鉴查心得
        ****************
        
            合成武器突破素材时，有10%概率获得2倍产出。 

        ****************
        

        ****4:神里流·霰步
        ****************
        
            ❤替代冲刺❤
            隐入碎冰，以消耗体力为代价，化为激流快速移动。
            
            在霰步状态下，神里绫华可以在水面上高速移动。
            结束霰步现身时，将产生如下效果：
            ·释放寒冰的力量，对周围的敌人施加冰元素附着；
            ·将寒气凝聚在剑上，使神里绫华在短时间内获得冰元素附魔。 

        ****************
        
        */
        
            /*******普通攻击·神里流·倾
             * 
             * **普通攻击**
             * 进行至多五段的连续剑击。
             * 
             * **重击**
             * 消耗一定体力，在居合中放出连续的剑风。
             * 
             * **下落攻击**
             * 从空中下坠冲击地面，攻击下落路径上的敌人，并在落地时造成范围伤害。
             * 
             * 一段伤害|{param1:F1P}
             * 二段伤害|{param2:F1P}
             * 三段伤害|{param3:F1P}
             * 四段伤害|{param4:F1P}*3
             * 五段伤害|{param7:F1P}
             * 重击伤害|{param8:F1P}*3
             * 重击体力消耗|{param9:F1}点
             * 下坠期间伤害|{param10:P}
             * 低空/高空坠地冲击伤害|{param11:P}/{param12:P}
            */
            void 神里绫华::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[10]{ 0.45725300908088684,0.486845999956131,0.6262180209159851,0.22646400332450867,0.7818170189857483,0.5512599945068359,20,0.6393240094184875,1.2783770561218262,1.59676194190979},
                        new const double[10]{ 0.4944719970226288,0.5264729857444763,0.6771889925003052,0.2448969930410385,0.8454539775848389,0.5961300134658813,20,0.6913620233535767,1.3824310302734375,1.7267309427261353},
                        new const double[10]{ 0.5316900014877319,0.566100001335144,0.72816002368927,0.26333001255989075,0.909089982509613,0.640999972820282,20,0.743399977684021,1.4864850044250488,1.8566999435424805},
                        new const double[10]{ 0.5848590135574341,0.6227099895477295,0.8009759783744812,0.2896629869937897,0.9999989867210388,0.7050999999046326,20,0.8177400231361389,1.635133981704712,2.042370080947876},
                        new const double[10]{ 0.6220769882202148,0.6623370051383972,0.851947009563446,0.3080959916114807,1.063634991645813,0.749970018863678,20,0.8697779774665833,1.7391870021820068,2.1723389625549316},
                        new const double[10]{ 0.6646130084991455,0.7076249718666077,0.9101999998092651,0.3291630148887634,1.1363630294799805,0.8012499809265137,20,0.9292500019073486,1.858106017112732,2.3208749294281006},
                        new const double[10]{ 0.7230979800224304,0.7698959708213806,0.9902979731559753,0.35812899470329285,1.2363619804382324,0.8717600107192993,20,1.011023998260498,2.021620035171509,2.5251119136810303},
                        new const double[10]{ 0.7815840244293213,0.8321670293807983,1.0703949928283691,0.38709500432014465,1.3363620042800903,0.9422699809074402,20,1.0927979946136475,2.1851329803466797,2.72934889793396},
                        new const double[10]{ 0.8400700092315674,0.8944380283355713,1.1504930257797241,0.41606101393699646,1.4363620281219482,1.012779951095581,20,1.1745719909667969,2.3486459255218506,2.9335858821868896},
                        new const double[10]{ 0.9038730263710022,0.962369978427887,1.2378720045089722,0.44766101241111755,1.5454529523849487,1.0896999835968018,20,1.2637799978256226,2.527024984359741,3.1563899517059326},
                        new const double[10]{ 0.9676759839057922,1.0303020477294922,1.3252509832382202,0.47926101088523865,1.6545439958572388,1.1666200160980225,20,1.3529880046844482,2.7054030895233154,3.3791940212249756},
                        new const double[10]{ 1.031479001045227,1.0982340574264526,1.4126299619674683,0.510860025882721,1.7636350393295288,1.2435400485992432,20,1.442196011543274,2.8837809562683105,3.6019980907440186},
                        new const double[10]{ 1.0952810049057007,1.1661659479141235,1.5000100135803223,0.542460024356842,1.872725009918213,1.3204599618911743,20,1.5314040184020996,3.0621590614318848,3.8248019218444824},
                        new const double[10]{ 1.1590839624404907,1.234097957611084,1.5873889923095703,0.574059009552002,1.981816053390503,1.397379994392395,20,1.6206120252609253,3.24053692817688,4.047605991363525},
                        new const double[10]{ 1.2228870391845703,1.3020299673080444,1.6747679710388184,0.605659008026123,2.090907096862793,1.4743000268936157,20,1.709820032119751,3.418915033340454,4.270410060882568}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******神里流·冰华
             * 
             * 唤起盛开的冰之华，击飞身边的敌人并造成冰元素范围伤害。
             * 
             * 技能伤害|{param1:P}
             * 冷却时间|{param2:F1}秒
            */
            void 神里绫华::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[2]{ 2.3919999599456787,10},
                        new const double[2]{ 2.5713999271392822,10},
                        new const double[2]{ 2.7507998943328857,10},
                        new const double[2]{ 2.990000009536743,10},
                        new const double[2]{ 3.1693999767303467,10},
                        new const double[2]{ 3.34879994392395,10},
                        new const double[2]{ 3.5880000591278076,10},
                        new const double[2]{ 3.827199935913086,10},
                        new const double[2]{ 4.066400051116943,10},
                        new const double[2]{ 4.305600166320801,10},
                        new const double[2]{ 4.5447998046875,10},
                        new const double[2]{ 4.783999919891357,10},
                        new const double[2]{ 5.083000183105469,10},
                        new const double[2]{ 5.381999969482422,10},
                        new const double[2]{ 5.681000232696533,10}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******神里流·霜灭
             * 
             * 以倾奇之姿汇聚寒霜，放出持续行进的霜见雪关扉。
             * 
             * **霜见雪关扉**
             * ·以刀锋般尖锐的霜风持续切割触及的敌人，造成冰元素伤害；
             * ·持续时间结束时绽放，造成冰元素范围伤害。
             * 
             * 切割伤害|{param1:P}
             * 绽放伤害|{param2:P}
             * 持续时间|{param3:F1}秒
             * 冷却时间|{param4:F1}秒
             * 元素能量|{param5:I}
            */
            void 神里绫华::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[5]{ 1.1230000257492065,1.684499979019165,5,20,80},
                        new const double[5]{ 1.20722496509552,1.8108370304107666,5,20,80},
                        new const double[5]{ 1.291450023651123,1.9371750354766846,5,20,80},
                        new const double[5]{ 1.403749942779541,2.1056249141693115,5,20,80},
                        new const double[5]{ 1.487975001335144,2.231961965560913,5,20,80},
                        new const double[5]{ 1.5721999406814575,2.358299970626831,5,20,80},
                        new const double[5]{ 1.684499979019165,2.526750087738037,5,20,80},
                        new const double[5]{ 1.7968000173568726,2.695199966430664,5,20,80},
                        new const double[5]{ 1.90910005569458,2.86365008354187,5,20,80},
                        new const double[5]{ 2.021399974822998,3.032099962234497,5,20,80},
                        new const double[5]{ 2.133699893951416,3.200550079345703,5,20,80},
                        new const double[5]{ 2.246000051498413,3.36899995803833,5,20,80},
                        new const double[5]{ 2.3863749504089355,3.579561948776245,5,20,80},
                        new const double[5]{ 2.526750087738037,3.7901248931884766,5,20,80},
                        new const double[5]{ 2.6671249866485596,4.000687122344971,5,20,80}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };
        /*****神里绫华
        
            ***1命***
            霜杀墨染樱            
            神里绫华的普通攻击或重击对敌人造成冰元素伤害时，有50%的几率使❤神里流·冰华❤的冷却时间缩减0.3秒。该效果每0.1秒只能触发一次。
            
            ***2命***
            三重雪关扉            
            施放❤神里流·霜灭❤时，会额外释放两股规模较小的霜见雪关扉，各自能造成原本20%的伤害。
            
            ***3命***
            花白锦画纸吹雪            
            ❤神里流·霜灭❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            盈缺流返            
            敌人受到❤神里流·霜灭❤的霜见雪关扉造成的伤害后，防御力降低30%，持续6秒。
            
            ***5命***
            花云钟入月            
            ❤神里流·冰华❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            间水月            
            每过10秒，神里绫华会获得「薄冰舞踏」，使重击造成的伤害提高298%。薄冰舞踏效果将在重击命中敌人的0.5秒后清除，并重新开始计算时间。
            
        */
         
        