﻿#pragma once
        #include "莫娜.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO莫娜.cpp
        const double HP =  10409.024522594642;
        const double ATK =  287.0140617423858;
        const double DEF =  653.2712256159284;
        //元素充能效率
        const double OTHER = 0.3199999928474426;
        
        莫娜::~莫娜() {
        }
        莫娜::莫娜(u32* frameCur):Role(frameCur) {
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
        
        ****1:「老太婆来抓我啊！」
        ****************
        
            进入❤虚实流动❤状态2秒后，如果周围存在敌人，则自动凝聚一个虚影。
            通过这种方式产生的虚影持续2秒，造成的破裂伤害相当于❤水中幻愿❤伤害的50%。 

        ****************
        

        ****2:「托付于命运吧！」
        ****************
        
            莫娜的水元素伤害加成获得额外提升，提升程度相当于她的元素充能效率的20%。 

        ****************
        

        ****3:运行原理
        ****************
        
            合成武器突破素材时，有25%概率返还部分合成材料。 

        ****************
        

        ****4:虚实流动
        ****************
        
            ❤替代冲刺❤
            隐入流水，以消耗体力为代价，化为激流快速移动。
            
            在虚实流动状态下，莫娜可以在水面上高速移动。
            结束虚实流动现身时，对周围的敌人施加潮湿状态。 

        ****************
        
        */
        
            /*******普通攻击·因果点破
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
            void 莫娜::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[9]{ 0.37599998712539673,0.36000001430511475,0.4480000138282776,0.5616000294685364,1.4972000122070312,50,0.5682880282402039,1.136335015296936,1.4193439483642578},
                        new const double[9]{ 0.4041999876499176,0.3869999945163727,0.48159998655319214,0.6037200093269348,1.6094900369644165,50,0.6145439743995667,1.228827953338623,1.534872055053711},
                        new const double[9]{ 0.4323999881744385,0.414000004529953,0.5152000188827515,0.6458399891853333,1.7217799425125122,50,0.6607999801635742,1.3213200569152832,1.6504000425338745},
                        new const double[9]{ 0.4699999988079071,0.44999998807907104,0.5600000023841858,0.7020000219345093,1.871500015258789,50,0.7268800139427185,1.4534519910812378,1.815440058708191},
                        new const double[9]{ 0.498199999332428,0.47699999809265137,0.5935999751091003,0.7441200017929077,1.9837900400161743,50,0.7731360197067261,1.5459439754486084,1.9309680461883545},
                        new const double[9]{ 0.5264000296592712,0.5040000081062317,0.6272000074386597,0.7862399816513062,2.0960800647735596,50,0.8259999752044678,1.6516499519348145,2.062999963760376},
                        new const double[9]{ 0.5640000104904175,0.5400000214576721,0.671999990940094,0.8424000144004822,2.245800018310547,50,0.898688018321991,1.7969950437545776,2.24454402923584},
                        new const double[9]{ 0.6015999913215637,0.5759999752044678,0.7167999744415283,0.8985599875450134,2.395519971847534,50,0.9713760018348694,1.9423400163650513,2.4260880947113037},
                        new const double[9]{ 0.63919997215271,0.6119999885559082,0.7616000175476074,0.9547200202941895,2.5452399253845215,50,1.0440640449523926,2.087686061859131,2.6076319217681885},
                        new const double[9]{ 0.676800012588501,0.6480000019073486,0.8064000010490417,1.0108799934387207,2.694960117340088,50,1.12336003780365,2.246243953704834,2.8056800365448},
                        new const double[9]{ 0.7143999934196472,0.6840000152587891,0.8511999845504761,1.067039966583252,2.8506689071655273,50,1.2026560306549072,2.404802083969116,3.003727912902832},
                        new const double[9]{ 0.7519999742507935,0.7200000286102295,0.8960000276565552,1.1232000589370728,3.054287910461426,50,1.2819520235061646,2.5633609294891357,3.2017760276794434},
                        new const double[9]{ 0.7990000247955322,0.7649999856948853,0.9520000219345093,1.1934000253677368,3.257906913757324,50,1.3612480163574219,2.721919059753418,3.3998239040374756},
                        new const double[9]{ 0.8460000157356262,0.8100000023841858,1.0080000162124634,1.2635999917984009,3.4615259170532227,50,1.4405440092086792,2.8804779052734375,3.597872018814087},
                        new const double[9]{ 0.8930000066757202,0.8550000190734863,1.0640000104904175,1.333799958229065,3.6651461124420166,50,1.5198400020599365,3.0390360355377197,3.795919895172119}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******水中幻愿
             * 
             * 聚集水花汇成命运的虚影。
             * 
             * **虚影**
             * 具有如下特性：
             * ·持续嘲讽周围的敌人，吸引火力；
             * ·持续对附近的敌人造成水元素伤害；
             * ·持续时间结束时，虚影破裂，造成水元素范围伤害。
             * 
             * **长按**
             * 借助水流之势迅速后退，并唤出虚影。
             * 
             * 场上同时只能存在一个通过水中幻愿创造的虚影。
             * 
             * 持续伤害|{param1:F1P}
             * 爆裂伤害|{param2:P}
             * 冷却时间|{param5:F1}秒
            */
            void 莫娜::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[3]{ 0.3199999928474426,1.3279999494552612,12},
                        new const double[3]{ 0.3440000116825104,1.4276000261306763,12},
                        new const double[3]{ 0.36800000071525574,1.5271999835968018,12},
                        new const double[3]{ 0.4000000059604645,1.659999966621399,12},
                        new const double[3]{ 0.42399999499320984,1.759600043296814,12},
                        new const double[3]{ 0.4480000138282776,1.8592000007629395,12},
                        new const double[3]{ 0.47999998927116394,1.9919999837875366,12},
                        new const double[3]{ 0.5120000243186951,2.124799966812134,12},
                        new const double[3]{ 0.5440000295639038,2.2576000690460205,12},
                        new const double[3]{ 0.5759999752044678,2.390399932861328,12},
                        new const double[3]{ 0.6079999804496765,2.523200035095215,12},
                        new const double[3]{ 0.6399999856948853,2.6559998989105225,12},
                        new const double[3]{ 0.6800000071525574,2.822000026702881,12},
                        new const double[3]{ 0.7200000286102295,2.98799991607666,12},
                        new const double[3]{ 0.7599999904632568,3.1540000438690186,12}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******星命定轨
             * 
             * 凝聚粼粼的水波，倒映出虚幻星空，对大范围内的敌人施加泡影状态。
             * 
             * **泡影**
             * 以星相的气泡包裹敌人，施加潮湿状态。较弱的敌人会被禁锢在泡影中，无法行动。
             * 处于泡影影响下的敌人受到伤害时，会产生以下效果：
             * ·对敌人施加星异的伤害加成效果，并以此提高这一次造成的伤害；
             * ·解除泡影效果，并额外造成一次水元素伤害。
             * 
             * **星异**
             * 持续时间内，提高受到的伤害。
             * 
             * 泡影持续时间|{param1:F1}秒
             * 泡影破裂伤害|{param2:P}
             * 伤害加成|{param10:P}
             * 星异持续时间|{param4:F1}秒
             * 冷却时间|{param5:F1}秒
             * 元素能量|{param6:I}
            */
            void 莫娜::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[7]{ 8,4.423999786376953,-0.41999998688697815,4,15,60,0.41999998688697815},
                        new const double[7]{ 8,4.755799770355225,-0.4399999976158142,4,15,60,0.4399999976158142},
                        new const double[7]{ 8,5.087600231170654,-0.46000000834465027,4,15,60,0.46000000834465027},
                        new const double[7]{ 8,5.53000020980835,-0.47999998927116394,4.5,15,60,0.47999998927116394},
                        new const double[7]{ 8,5.861800193786621,-0.5,4.5,15,60,0.5},
                        new const double[7]{ 8,6.193600177764893,-0.5199999809265137,4.5,15,60,0.5199999809265137},
                        new const double[7]{ 8,6.636000156402588,-0.5400000214576721,5,15,60,0.5400000214576721},
                        new const double[7]{ 8,7.078400135040283,-0.5600000023841858,5,15,60,0.5600000023841858},
                        new const double[7]{ 8,7.5208001136779785,-0.5799999833106995,5,15,60,0.5799999833106995},
                        new const double[7]{ 8,7.963200092315674,-0.6000000238418579,5,15,60,0.6000000238418579},
                        new const double[7]{ 8,8.405599594116211,-0.6000000238418579,5,15,60,0.6000000238418579},
                        new const double[7]{ 8,8.847999572753906,-0.6000000238418579,5,15,60,0.6000000238418579},
                        new const double[7]{ 8,9.401000022888184,-0.6000000238418579,5,15,60,0.6000000238418579},
                        new const double[7]{ 8,9.954000473022461,-0.6000000238418579,5,15,60,0.6000000238418579},
                        new const double[7]{ 8,10.506999969482422,-0.6000000238418579,5,15,60,0.6000000238418579}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };
        /*****莫娜
        
            ***1命***
            沉没的预言            
            队伍中自己的角色攻击命中处于星异状态下的敌人后的8秒内，水元素相关反应的效果提升：·感电反应造成的伤害提升15%，蒸发反应造成的伤害提升15%，水元素扩散反应造成的伤害提升15%；·冻结反应的持续时间延长15%。
            
            ***2命***
            星月的连珠            
            普通攻击命中时，有20%的几率自动施放一次重击。该效果每5秒只能触发一次。
            
            ***3命***
            不休的天象            
            ❤星命定轨❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            灭绝的预言            
            队伍中所有角色攻击处于星异状态下的敌人时，暴击率提升15%。
            
            ***5命***
            命运的嘲弄            
            ❤水中幻愿❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            厄运的修辞            
            进入❤虚实流动❤状态后，每移动1秒，莫娜的下一次重击伤害就增加60%，通过这种方式至多可以获得180%重击伤害加成，该效果至多持续8秒。
            
        */
         
        