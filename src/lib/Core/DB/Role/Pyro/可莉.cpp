﻿#pragma once
        #include "可莉.h"
        using namespace DB::RoleConstruct;
        //TODO:AUTO可莉.cpp
        const double HP =  10286.565419930499;
        const double ATK =  310.93189668962077;
        const double DEF =  614.8434950278315;
        //火元素伤害加成
        const double OTHER = 0.2879999876022339;
        
        可莉::~可莉() {
        }
        可莉::可莉() {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Pyro, WeaponType::Catalyst);
            delete baseData;
        };        

        /*
        
        ****1:砰砰礼物
        ****************
        
            ❤蹦蹦炸弹❤与普通攻击造成伤害时，有50%的几率赋予可莉一朵爆裂火花。
            施放重击时将消耗爆裂火花，使本次重击不消耗体力，造成的伤害提升50%。 

        ****************
        

        ****2:火花无限
        ****************
        
            可莉的重击造成暴击后，为队伍中所有角色恢复2点元素能量。 

        ****************
        

        ****3:全是宝藏
        ****************
        
            在小地图上显示周围的❤蒙德区域特产❤的位置。 

        ****************
        
        */
        
            /*******普通攻击·砰砰
            一段伤害|{param1:F1P}
            二段伤害|{param2:F1P}
            三段伤害|{param3:F1P}
            重击伤害|{param4:P}
            重击体力消耗|{param5:F1}点
            下坠期间伤害|{param6:F1P}
            低空/高空坠地冲击伤害|{param7:P}/{param8:P}
            */
            void 可莉::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[8]{ 0.7215999960899353,0.6240000128746033,0.8992000222206116,1.5736000537872314,50,0.5682880282402039,1.136335015296936,1.4193439483642578},
                        new const double[8]{ 0.7757200002670288,0.670799970626831,0.9666399955749512,1.6916199922561646,50,0.6145439743995667,1.228827953338623,1.534872055053711},
                        new const double[8]{ 0.8298400044441223,0.7175999879837036,1.0340800285339355,1.8096400499343872,50,0.6607999801635742,1.3213200569152832,1.6504000425338745},
                        new const double[8]{ 0.9020000100135803,0.7799999713897705,1.1239999532699585,1.9670000076293945,50,0.7268800139427185,1.4534519910812378,1.815440058708191},
                        new const double[8]{ 0.9561200141906738,0.8267999887466431,1.1914399862289429,2.085020065307617,50,0.7731360197067261,1.5459439754486084,1.9309680461883545},
                        new const double[8]{ 1.0102399587631226,0.8736000061035156,1.2588800191879272,2.2030398845672607,50,0.8259999752044678,1.6516499519348145,2.062999963760376},
                        new const double[8]{ 1.0823999643325806,0.9359999895095825,1.3487999439239502,2.3603999614715576,50,0.898688018321991,1.7969950437545776,2.24454402923584},
                        new const double[8]{ 1.1545599699020386,0.9983999729156494,1.4387199878692627,2.5177600383758545,50,0.9713760018348694,1.9423400163650513,2.4260880947113037},
                        new const double[8]{ 1.2267199754714966,1.0607999563217163,1.5286400318145752,2.6751201152801514,50,1.0440640449523926,2.087686061859131,2.6076319217681885},
                        new const double[8]{ 1.2988799810409546,1.1232000589370728,1.6185599565505981,2.832479953765869,50,1.12336003780365,2.246243953704834,2.8056800365448},
                        new const double[8]{ 1.373926043510437,1.188096046447754,1.712077021598816,2.996134042739868,50,1.2026560306549072,2.404802083969116,3.003727912902832},
                        new const double[8]{ 1.4720640182495117,1.2729599475860596,1.8343679904937744,3.21014404296875,50,1.2819520235061646,2.5633609294891357,3.2017760276794434},
                        new const double[8]{ 1.5702019929885864,1.3578239679336548,1.956658959388733,3.424154043197632,50,1.3612480163574219,2.721919059753418,3.3998239040374756},
                        new const double[8]{ 1.6683390140533447,1.44268798828125,2.0789499282836914,3.6381630897521973,50,1.4405440092086792,2.8804779052734375,3.597872018814087},
                        new const double[8]{ 1.7664769887924194,1.5275520086288452,2.201241970062256,3.852173089981079,50,1.5198400020599365,3.0390360355377197,3.795919895172119}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******蹦蹦炸弹
            蹦蹦炸弹伤害|{param1:F1P}
            诡雷伤害|{param4:F1P}
            诡雷持续时间|{param5:F1}秒
            冷却时间|{param6:F1}秒
            */
            void 可莉::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[6]{ 0.9520000219345093,0.9520000219345093,0.9520000219345093,0.328000009059906,15,20},
                        new const double[6]{ 1.0233999490737915,1.0233999490737915,1.0233999490737915,0.35260000824928284,15,20},
                        new const double[6]{ 1.0947999954223633,1.0947999954223633,1.0947999954223633,0.37720000743865967,15,20},
                        new const double[6]{ 1.190000057220459,1.190000057220459,1.190000057220459,0.4099999964237213,15,20},
                        new const double[6]{ 1.2613999843597412,1.2613999843597412,1.2613999843597412,0.43459999561309814,15,20},
                        new const double[6]{ 1.332800030708313,1.332800030708313,1.332800030708313,0.459199994802475,15,20},
                        new const double[6]{ 1.4279999732971191,1.4279999732971191,1.4279999732971191,0.492000013589859,15,20},
                        new const double[6]{ 1.5232000350952148,1.5232000350952148,1.5232000350952148,0.5248000025749207,15,20},
                        new const double[6]{ 1.618399977684021,1.618399977684021,1.618399977684021,0.5576000213623047,15,20},
                        new const double[6]{ 1.7136000394821167,1.7136000394821167,1.7136000394821167,0.590399980545044,15,20},
                        new const double[6]{ 1.8087999820709229,1.8087999820709229,1.8087999820709229,0.623199999332428,15,20},
                        new const double[6]{ 1.9040000438690186,1.9040000438690186,1.9040000438690186,0.656000018119812,15,20},
                        new const double[6]{ 2.0230000019073486,2.0230000019073486,2.0230000019073486,0.6970000267028809,15,20},
                        new const double[6]{ 2.1419999599456787,2.1419999599456787,2.1419999599456787,0.7379999756813049,15,20},
                        new const double[6]{ 2.260999917984009,2.260999917984009,2.260999917984009,0.7789999842643738,15,20}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******轰轰火花
            轰轰火花伤害|{param1:F1P}
            持续时间|{param5:F1}秒
            冷却时间|{param2:F1}秒
            元素能量|{param3:I}
            */
            void 可莉::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[5]{ 0.42640000581741333,15,60,0.511680006980896,10},
                        new const double[5]{ 0.4583800137042999,15,60,0.550055980682373,10},
                        new const double[5]{ 0.49035999178886414,15,60,0.5884320139884949,10},
                        new const double[5]{ 0.5329999923706055,15,60,0.6395999789237976,10},
                        new const double[5]{ 0.5649799704551697,15,60,0.6779760122299194,10},
                        new const double[5]{ 0.5969600081443787,15,60,0.7163519859313965,10},
                        new const double[5]{ 0.6395999789237976,15,60,0.767520010471344,10},
                        new const double[5]{ 0.6822400093078613,15,60,0.8186879754066467,10},
                        new const double[5]{ 0.7248799800872803,15,60,0.8698559999465942,10},
                        new const double[5]{ 0.767520010471344,15,60,0.9210240244865417,10},
                        new const double[5]{ 0.8101599812507629,15,60,0.9721919894218445,10},
                        new const double[5]{ 0.8528000116348267,15,60,1.023360013961792,10},
                        new const double[5]{ 0.9060999751091003,15,60,1.0873199701309204,10},
                        new const double[5]{ 0.9593999981880188,15,60,1.1512800455093384,10},
                        new const double[5]{ 1.0126999616622925,15,60,1.2152400016784668,10}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };
        /*****可莉
        
            ***1命***
            连环轰隆            
            攻击与施放技能时，有几率召唤火花轰击敌人，造成相当于❤轰轰火花❤攻击伤害120%的伤害。
            
            ***2命***
            破破弹片            
            ❤蹦蹦炸弹❤的诡雷会使敌人的防御力降低23%，持续10秒。
            
            ***3命***
            可莉特调            
            ❤蹦蹦炸弹❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            一触即发            
            如果在❤轰轰火花❤持续期间内退场，会引发爆炸，造成555%攻击力的火元素范围伤害。
            
            ***5命***
            轰击之星            
            ❤轰轰火花❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            火力全开            
            在❤轰轰火花❤的状态下，可莉每3秒会为队伍中所有角色（不包括可莉自己）恢复3点元素能量；施放❤轰轰火花❤后的25秒内，队伍中所有角色获得10%火元素伤害加成。
            
        */
         
        