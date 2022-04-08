﻿#pragma once
        #include "神里绫人.h"
        using namespace DB::RoleConstruct;
        //TODO:AUTO神里绫人.cpp
        const double HP =  13715.420204316499;
        const double ATK =  298.97297540130603;
        const double DEF =  768.55440212143;
        //暴击伤害
        const double OTHER = 0.8840000033378601;
        
        神里绫人::~神里绫人() {
        }
        神里绫人::神里绫人() {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Male, CharacterGroup::Tivat, ElementType::Hydro, WeaponType::Sword);
            delete baseData;
        };        

        /*
        
        ****1:神里流·清泷绕峰
        ****************
        
            ❤神里流·镜花❤具有如下效果：
            ·施放后，神里绫人会获得2层浪闪效果；
            ·水影破裂后，神里绫人将获得等同于叠加上限层数的浪闪效果。 

        ****************
        

        ****2:神里流·破月渐盈
        ****************
        
            神里绫人处于队伍后台时，若元素能量低于40点，每1秒为自己恢复2点元素能量。 

        ****************
        

        ****3:神里流·日常茶饭
        ****************
        
            完美烹饪食物时，有18%概率额外获得一个「奇怪的」品质的同种料理。 

        ****************
        
        */
        
            /*******普通攻击·神里流·转
            一段伤害|{param1:F1P}
            二段伤害|{param2:F1P}
            三段伤害|{param3:F1P}
            四段伤害|{param4:F1P}*2
            五段伤害|{param5:F1P}
            重击伤害|{param6:F1P}
            重击体力消耗|{param7:F1}点
            下坠期间伤害|{param8:F1P}
            低空/高空坠地冲击伤害|{param9:P}/{param10:P}
            */
            void 神里绫人::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[10]{ 0.4496169984340668,0.47157201170921326,0.5861240029335022,0.2944850027561188,0.756043016910553,1.2952970266342163,20,0.6393240094184875,1.2783770561218262,1.59676194190979},
                        new const double[10]{ 0.48621299862861633,0.5099560022354126,0.6338319778442383,0.3184550106525421,0.8175820112228394,1.4007279872894287,20,0.6913620233535767,1.3824310302734375,1.7267309427261353},
                        new const double[10]{ 0.5228099822998047,0.5483400225639343,0.6815400123596191,0.34242498874664307,0.8791199922561646,1.5061589479446411,20,0.743399977684021,1.4864850044250488,1.8566999435424805},
                        new const double[10]{ 0.5750910043716431,0.6031739711761475,0.7496939897537231,0.37666699290275574,0.9670320153236389,1.6567749977111816,20,0.8177400231361389,1.635133981704712,2.042370080947876},
                        new const double[10]{ 0.6116880178451538,0.6415579915046692,0.797402024269104,0.4006370007991791,1.0285700559616089,1.762205958366394,20,0.8697779774665833,1.7391870021820068,2.1723389625549316},
                        new const double[10]{ 0.6535120010375977,0.6854249835014343,0.8519250154495239,0.42803099751472473,1.0988999605178833,1.8826990127563477,20,0.9292500019073486,1.858106017112732,2.3208749294281006},
                        new const double[10]{ 0.7110220193862915,0.7457420229911804,0.9268940091133118,0.4656980037689209,1.1956030130386353,2.0483760833740234,20,1.011023998260498,2.021620035171509,2.5251119136810303},
                        new const double[10]{ 0.7685310244560242,0.8060600161552429,1.001863956451416,0.5033649802207947,1.2923059463500977,2.2140541076660156,20,1.0927979946136475,2.1851329803466797,2.72934889793396},
                        new const double[10]{ 0.8260400295257568,0.8663769960403442,1.0768330097198486,0.541031002998352,1.389009952545166,2.3797309398651123,20,1.1745719909667969,2.3486459255218506,2.9335858821868896},
                        new const double[10]{ 0.8887770175933838,0.9321780204772949,1.1586179733276367,0.5821220278739929,1.4945039749145508,2.5604701042175293,20,1.2637799978256226,2.527024984359741,3.1563899517059326},
                        new const double[10]{ 0.9515140056610107,0.9979789853096008,1.2404030561447144,0.623212993144989,1.5999979972839355,2.741209030151367,20,1.3529880046844482,2.7054030895233154,3.3791940212249756},
                        new const double[10]{ 1.0142509937286377,1.0637799501419067,1.3221880197525024,0.6643040180206299,1.7054929733276367,2.921947956085205,20,1.442196011543274,2.8837809562683105,3.6019980907440186},
                        new const double[10]{ 1.0769890546798706,1.129580020904541,1.4039720296859741,0.705394983291626,1.8109869956970215,3.1026880741119385,20,1.5314040184020996,3.0621590614318848,3.8248019218444824},
                        new const double[10]{ 1.1397260427474976,1.1953810453414917,1.4857569932937622,0.746487021446228,1.9164819717407227,3.2834270000457764,20,1.6206120252609253,3.24053692817688,4.047605991363525},
                        new const double[10]{ 1.2024630308151245,1.2611819505691528,1.5675419569015503,0.7875769734382629,2.0219759941101074,3.4641659259796143,20,1.709820032119751,3.418915033340454,4.270410060882568}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******神里流·镜花
            一段瞬水剑伤害|{param1:F1P}
            二段瞬水剑伤害|{param2:F1P}
            三段瞬水剑伤害|{param3:F1P}
            泷廻鉴花持续时间|{param4:F1}秒
            浪闪伤害值提高|{param5:F2P}生命值上限/层
            水影伤害|{param6:F1P}
            水影持续时间|{param7:I}秒
            冷却时间|{param8:F1}秒
            */
            void 神里绫人::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[8]{ 0.5289000272750854,0.5891000032424927,0.6492999792098999,6,0.005611000116914511,1.014799952507019,6,12},
                        new const double[8]{ 0.5719500184059143,0.6370499730110168,0.7021499872207642,6,0.006066999863833189,1.0973999500274658,6,12},
                        new const double[8]{ 0.6150000095367432,0.6850000023841858,0.7549999952316284,6,0.006523999851197004,1.1799999475479126,6,12},
                        new const double[8]{ 0.6765000224113464,0.7534999847412109,0.8305000066757202,6,0.0071760001592338085,1.2979999780654907,6,12},
                        new const double[8]{ 0.7195500135421753,0.8014500141143799,0.8833500146865845,6,0.007633000146597624,1.3805999755859375,6,12},
                        new const double[8]{ 0.768750011920929,0.856249988079071,0.9437500238418579,6,0.008155000396072865,1.475000023841858,6,12},
                        new const double[8]{ 0.8363999724388123,0.9315999746322632,1.0268000364303589,6,0.00887299980968237,1.6047999858856201,6,12},
                        new const double[8]{ 0.9040499925613403,1.0069500207901,1.1098500490188599,6,0.009589999914169312,1.7345999479293823,6,12},
                        new const double[8]{ 0.9717000126838684,1.0822999477386475,1.1928999423980713,6,0.01030800025910139,1.864400029182434,6,12},
                        new const double[8]{ 1.0455000400543213,1.1644999980926514,1.2834999561309814,6,0.011091000400483608,2.00600004196167,6,12},
                        new const double[8]{ 1.1193000078201294,1.2467000484466553,1.3740999698638916,6,0.011873999610543251,2.147599935531616,6,12},
                        new const double[8]{ 1.1930999755859375,1.3288999795913696,1.4646999835968018,6,0.012656999751925468,2.2892000675201416,6,12},
                        new const double[8]{ 1.2668999433517456,1.4111000299453735,1.555299997329712,6,0.013438999652862549,2.430799961090088,6,12},
                        new const double[8]{ 1.3407000303268433,1.493299961090088,1.645900011062622,6,0.014221999794244766,2.5724000930786133,6,12},
                        new const double[8]{ 1.4144999980926514,1.5755000114440918,1.7365000247955322,6,0.015004999935626984,2.7139999866485596,6,12}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******神里流·水囿
            水花剑伤害|{param1:F1P}
            普通攻击伤害提升|{param2:F1P}
            持续时间|{param3:F1}秒
            冷却时间|{param4:F1}秒
            元素能量|{param5:I}
            */
            void 神里绫人::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[5]{ 0.6645600199699402,0.10999999940395355,18,20,80},
                        new const double[5]{ 0.7144020199775696,0.11999999731779099,18,20,80},
                        new const double[5]{ 0.764244019985199,0.12999999523162842,18,20,80},
                        new const double[5]{ 0.8306999802589417,0.14000000059604645,18,20,80},
                        new const double[5]{ 0.880541980266571,0.15000000596046448,18,20,80},
                        new const double[5]{ 0.9303839802742004,0.1599999964237213,18,20,80},
                        new const double[5]{ 0.9968400001525879,0.17000000178813934,18,20,80},
                        new const double[5]{ 1.0632959604263306,0.18000000715255737,18,20,80},
                        new const double[5]{ 1.1297520399093628,0.1899999976158142,18,20,80},
                        new const double[5]{ 1.1962080001831055,0.20000000298023224,18,20,80},
                        new const double[5]{ 1.2626639604568481,0.20000000298023224,18,20,80},
                        new const double[5]{ 1.3291200399398804,0.20000000298023224,18,20,80},
                        new const double[5]{ 1.4121899604797363,0.20000000298023224,18,20,80},
                        new const double[5]{ 1.4952600002288818,0.20000000298023224,18,20,80},
                        new const double[5]{ 1.5783300399780273,0.20000000298023224,18,20,80}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };
        /*****神里绫人
        
            ***1命***
            镜华风姿            
            对于生命值低于或等于50%的敌人，❤瞬水剑❤造成的伤害提升40%。
            
            ***2命***
            世有源泉            
            ❤浪闪❤叠加上限提升至5层；神里绫人处于至少3层浪闪状态下时，将提升50%生命值上限。
            
            ***3命***
            无意弄花            
            ❤神里流·镜花❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            不厌细流            
            施放❤神里流·水囿❤后，队伍中附近的角色普通攻击的攻击速度提升15%，持续15秒。
            
            ***5命***
            万水一露            
            ❤神里流·水囿❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            滥觞无底            
            施放❤神里流·镜花❤之后，神里绫人的下一次瞬水剑攻击命中敌人时，将进行2次额外的瞬水剑攻击，各自能造成神里绫人攻击力450%的伤害。此两次瞬水剑攻击不会受到浪闪的增益。
            
        */
         
        