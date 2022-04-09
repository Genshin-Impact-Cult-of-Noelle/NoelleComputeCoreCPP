﻿#pragma once
        #include "香菱.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO香菱.cpp
        const double HP =  10874.91499475576;
        const double ATK =  225.14102222725342;
        const double DEF =  668.8711049900703;
        //元素精通
        const double OTHER = 96;
        
        香菱::~香菱() {
        }
        香菱::香菱(u32* frameCur) {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Pyro, WeaponType::Polearm);
            delete baseData;
        };        

        /*
        
        ****1:交叉火力
        ****************
        
            锅巴的喷火距离提高20%。 

        ****************
        

        ****2:绝云朝天椒
        ****************
        
            ❤锅巴出击❤效果结束时，锅巴会在消失的位置留下辣椒。拾取辣椒会提高10%攻击力，持续10秒。 

        ****************
        

        ****3:万民堂大厨
        ****************
        
            完美烹饪攻击类食物时，有12%概率获得2倍产出。 

        ****************
        
        */
        
            /*******普通攻击·白案功夫
            一段伤害|{param1:F1P}
            二段伤害|{param2:F1P}
            三段伤害|{param3:F1P}+{param3:F1P}
            四段伤害|{param4:F1P}*4
            五段伤害|{param5:F1P}
            重击伤害|{param6:P}
            重击体力消耗|{param7:F1}点
            下坠期间伤害|{param8:F1P}
            低空/高空坠地冲击伤害|{param9:P}/{param10:P}
            */
            void 香菱::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[10]{ 0.4205400049686432,0.4214000105857849,0.26058000326156616,0.14103999733924866,0.7103599905967712,1.2168999910354614,25,0.6393240094184875,1.2783770561218262,1.59676194190979},
                        new const double[10]{ 0.4547699987888336,0.45570001006126404,0.28178998827934265,0.15252000093460083,0.7681800127029419,1.3159500360488892,25,0.6913620233535767,1.3824310302734375,1.7267309427261353},
                        new const double[10]{ 0.48899999260902405,0.49000000953674316,0.30300000309944153,0.164000004529953,0.8259999752044678,1.4149999618530273,25,0.743399977684021,1.4864850044250488,1.8566999435424805},
                        new const double[10]{ 0.5378999710083008,0.5389999747276306,0.33329999446868896,0.18039999902248383,0.9085999727249146,1.55649995803833,25,0.8177400231361389,1.635133981704712,2.042370080947876},
                        new const double[10]{ 0.572130024433136,0.5733000040054321,0.35451000928878784,0.191880002617836,0.9664199948310852,1.6555500030517578,25,0.8697779774665833,1.7391870021820068,2.1723389625549316},
                        new const double[10]{ 0.6112499833106995,0.612500011920929,0.3787499964237213,0.20499999821186066,1.0325000286102295,1.7687499523162842,25,0.9292500019073486,1.858106017112732,2.3208749294281006},
                        new const double[10]{ 0.6650400161743164,0.6664000153541565,0.41207998991012573,0.22303999960422516,1.12336003780365,1.924399971961975,25,1.011023998260498,2.021620035171509,2.5251119136810303},
                        new const double[10]{ 0.7188299894332886,0.720300018787384,0.44541001319885254,0.24108000099658966,1.2142200469970703,2.080049991607666,25,1.0927979946136475,2.1851329803466797,2.72934889793396},
                        new const double[10]{ 0.7726200222969055,0.7742000222206116,0.47874000668525696,0.25911998748779297,1.3050800561904907,2.2356998920440674,25,1.1745719909667969,2.3486459255218506,2.9335858821868896},
                        new const double[10]{ 0.8313000202178955,0.8330000042915344,0.5151000022888184,0.27880001068115234,1.4041999578475952,2.4054999351501465,25,1.2637799978256226,2.527024984359741,3.1563899517059326},
                        new const double[10]{ 0.8985369801521301,0.9003750085830688,0.5567619800567627,0.3013499975204468,1.517775058746338,2.6000618934631348,25,1.3529880046844482,2.7054030895233154,3.3791940212249756},
                        new const double[10]{ 0.9776089787483215,0.9796079993247986,0.605758011341095,0.3278689980506897,1.651339054107666,2.8288679122924805,25,1.442196011543274,2.8837809562683105,3.6019980907440186},
                        new const double[10]{ 1.0566799640655518,1.0588409900665283,0.6547530293464661,0.3543879985809326,1.7849030494689941,3.0576729774475098,25,1.5314040184020996,3.0621590614318848,3.8248019218444824},
                        new const double[10]{ 1.1357510089874268,1.1380740404129028,0.7037479877471924,0.38090598583221436,1.9184679985046387,3.2864789962768555,25,1.6206120252609253,3.24053692817688,4.047605991363525},
                        new const double[10]{ 1.2220109701156616,1.2245099544525146,0.7571970224380493,0.4098359942436218,2.064173936843872,3.5360848903656006,25,1.709820032119751,3.418915033340454,4.270410060882568}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******锅巴出击
            喷火伤害|{param1:P}
            冷却时间|{param2:F1}秒
            */
            void 香菱::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[2]{ 1.1128000020980835,12},
                        new const double[2]{ 1.1962599754333496,12},
                        new const double[2]{ 1.2797199487686157,12},
                        new const double[2]{ 1.3910000324249268,12},
                        new const double[2]{ 1.4744600057601929,12},
                        new const double[2]{ 1.557919979095459,12},
                        new const double[2]{ 1.6691999435424805,12},
                        new const double[2]{ 1.7804800271987915,12},
                        new const double[2]{ 1.891759991645813,12},
                        new const double[2]{ 2.003040075302124,12},
                        new const double[2]{ 2.1143200397491455,12},
                        new const double[2]{ 2.225600004196167,12},
                        new const double[2]{ 2.3647000789642334,12},
                        new const double[2]{ 2.5037999153137207,12},
                        new const double[2]{ 2.642899990081787,12}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******旋火轮
            一段挥舞伤害|{param1:F1P}
            二段挥舞伤害|{param2:F1P}
            三段挥舞伤害|{param3:P}
            旋火轮伤害|{param4:P}
            持续时间|{param5:F1}秒
            冷却时间|{param6:F1}秒
            元素能量|{param7:I}
            */
            void 香菱::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[7]{ 0.7200000286102295,0.8799999952316284,1.0959999561309814,1.1200000047683716,10,20,80},
                        new const double[7]{ 0.7739999890327454,0.9459999799728394,1.1782000064849854,1.2039999961853027,10,20,80},
                        new const double[7]{ 0.828000009059906,1.0119999647140503,1.2604000568389893,1.2879999876022339,10,20,80},
                        new const double[7]{ 0.8999999761581421,1.100000023841858,1.3700000047683716,1.399999976158142,10,20,80},
                        new const double[7]{ 0.9539999961853027,1.1660000085830688,1.4522000551223755,1.4839999675750732,10,20,80},
                        new const double[7]{ 1.0080000162124634,1.2319999933242798,1.5343999862670898,1.5679999589920044,10,20,80},
                        new const double[7]{ 1.0800000429153442,1.3200000524520874,1.6440000534057617,1.6799999475479126,10,20,80},
                        new const double[7]{ 1.1519999504089355,1.4079999923706055,1.753600001335144,1.7920000553131104,10,20,80},
                        new const double[7]{ 1.2239999771118164,1.496000051498413,1.8631999492645264,1.9040000438690186,10,20,80},
                        new const double[7]{ 1.2960000038146973,1.5839999914169312,1.9728000164031982,2.0160000324249268,10,20,80},
                        new const double[7]{ 1.3680000305175781,1.6720000505447388,2.08240008354187,2.128000020980835,10,20,80},
                        new const double[7]{ 1.440000057220459,1.7599999904632568,2.191999912261963,2.240000009536743,10,20,80},
                        new const double[7]{ 1.5299999713897705,1.8700000047683716,2.3289999961853027,2.380000114440918,10,20,80},
                        new const double[7]{ 1.6200000047683716,1.9800000190734863,2.4660000801086426,2.5199999809265137,10,20,80},
                        new const double[7]{ 1.7100000381469727,2.0899999141693115,2.6029999256134033,2.6600000858306885,10,20,80}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };
        /*****香菱
        
            ***1命***
            外酥里嫩            
            受到锅巴攻击的敌人，火元素抗性降低15%，持续6秒。
            
            ***2命***
            大火宽油            
            普通攻击的最后一击会对敌人施加持续2秒的内爆效果，持续时间结束时会发生爆炸，造成75%攻击力的火元素范围伤害。
            
            ***3命***
            武火急烹            
            ❤旋火轮❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            文火慢煨            
            ❤旋火轮❤的持续时间延长40%。
            
            ***5命***
            锅巴凶猛            
            ❤锅巴出击❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            大龙卷旋火轮            
            ❤旋火轮❤持续期间，队伍中所有角色获得15%火元素伤害加成。
            
        */
         
        