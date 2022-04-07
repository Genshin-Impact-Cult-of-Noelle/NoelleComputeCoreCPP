﻿
        #include "凯亚.h"
        using namespace Role;
        //TODO:AUTO凯亚.cpp
        const double HP =  11636.159044503409;
        const double ATK =  223.01705909465636;
        const double DEF =  791.7249344700394;
        //元素充能效率
        const double OTHER = 0.26669999957084656;
        
        namespace Cryo{
        凯亚::~凯亚() {
        }
        凯亚::凯亚() {
            BaseObject* baseData = new BaseObject();
            static Attr
			* HelathAttr = new Attr(HP, 0., 0.),
			* AtkAttr = new Attr(ATK, 0., 0.),
			* DefAttr = new Attr(DEF, 0., 0.),
			* CritRateAttr = new Attr(0.05, 0., 0.),
			* CritDamageAttr = new Attr(0.5, 0., 0.);
            baseData->SetAttr((u32)AttrType::Helath, HelathAttr);
		    baseData->SetAttr((u32)AttrType::Atk, DefAttr);
		    baseData->SetAttr((u32)AttrType::Def, AtkAttr);
		    baseData->SetAttr((u32)AttrType::CritRate, CritRateAttr);
		    baseData->SetAttr((u32)AttrType::CritDamage, CritDamageAttr);
            this->rawCharacter = new Character(baseData, CharacterGender::Male, CharacterGroup::Tivat, ElementType::Cryo, WeaponType::Sword);
            delete baseData;
        };        

        /*
        
        ****1:冷血之剑
        ****************
        
            ❤霜袭❤每击中一个单位，便为凯亚恢复等同于攻击力15%的生命值。 

        ****************
        

        ****2:冰渊之心
        ****************
        
            ❤霜袭❤使敌人冻结时，被冻结的敌人会掉落额外的元素微粒。
            一次霜袭至多因此产生2个额外元素微粒。 

        ****************
        

        ****3:隐藏的实力
        ****************
        
            队伍中自己的角色冲刺消耗的体力降低20%。
            无法与效果完全相同的固有天赋叠加。 

        ****************
        
        */
        
            /*******普通攻击·仪典剑术
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

            
                    const static double* Skill_1_1 = new double[15]{ 0.5375000238418579,0.581250011920929,0.625,0.6875,0.731249988079071,0.78125,0.8500000238418579,0.918749988079071,0.987500011920929,1.0625,1.1484379768371582,1.249500036239624,1.3505619764328003,1.4516249895095825,1.5618749856948853 };
                    const static double* Skill_1_2 = new double[15]{ 0.5168600082397461,0.558929979801178,0.6010000109672546,0.6610999703407288,0.7031700015068054,0.7512500286102295,0.817359983921051,0.8834699988365173,0.9495800137519836,1.0217000246047974,1.1043369770050049,1.2015190124511719,1.2987010478973389,1.3958829641342163,1.501899003982544 };
                    const static double* Skill_1_3 = new double[15]{ 0.6527400016784668,0.7058699727058411,0.7590000033378601,0.8349000215530396,0.8880299925804138,0.9487500190734863,1.0322400331497192,1.1157300472259521,1.1992199420928955,1.2903000116348267,1.3946620225906372,1.5173929929733276,1.6401230096817017,1.7628530263900757,1.8967410326004028 };
                    const static double* Skill_1_4 = new double[15]{ 0.7086399793624878,0.766319990158081,0.8240000009536743,0.9064000248908997,0.9640799760818481,1.0299999713897705,1.1206400394439697,1.2112799882888794,1.3019200563430786,1.4007999897003174,1.5140999555587769,1.647341012954712,1.7805819511413574,1.913822054862976,2.059175968170166 };
                    const static double* Skill_1_5 = new double[15]{ 0.8823599815368652,0.9541800022125244,1.0260000228881836,1.128600001335144,1.2004200220108032,1.2825000286102295,1.395359992980957,1.5082199573516846,1.6210800409317017,1.7441999912261963,1.8852750062942505,2.0511789321899414,2.217082977294922,2.3829879760742188,2.563973903656006 };
                    const static double* Skill_1_6 = new double[15]{ 0.5504000186920166,0.5952000021934509,0.6399999856948853,0.7039999961853027,0.7487999796867371,0.800000011920929,0.8704000115394592,0.9408000111579895,1.011199951171875,1.0880000591278076,1.1759999990463257,1.27948796749115,1.3829760551452637,1.486464023590088,1.5993599891662598 };
                    const static double* Skill_1_7 = new double[15]{ 0.7310000061988831,0.7904999852180481,0.8500000238418579,0.9350000023841858,0.9944999814033508,1.0625,1.156000018119812,1.249500036239624,1.343000054359436,1.4450000524520874,1.5618749856948853,1.6993199586868286,1.8367650508880615,1.9742100238800049,2.124150037765503 };
                    const static double* Skill_1_8 = new double[15]{ 20,20,20,20,20,20,20,20,20,20,20,20,20,20,20 };
                    const static double* Skill_1_9 = new double[15]{ 0.6393240094184875,0.6913620233535767,0.743399977684021,0.8177400231361389,0.8697779774665833,0.9292500019073486,1.011023998260498,1.0927979946136475,1.1745719909667969,1.2637799978256226,1.3529880046844482,1.442196011543274,1.5314040184020996,1.6206120252609253,1.709820032119751 };
                    const static double* Skill_1_10 = new double[15]{ 1.2783770561218262,1.3824310302734375,1.4864850044250488,1.635133981704712,1.7391870021820068,1.858106017112732,2.021620035171509,2.1851329803466797,2.3486459255218506,2.527024984359741,2.7054030895233154,2.8837809562683105,3.0621590614318848,3.24053692817688,3.418915033340454 };
                    const static double* Skill_1_11 = new double[15]{ 1.59676194190979,1.7267309427261353,1.8566999435424805,2.042370080947876,2.1723389625549316,2.3208749294281006,2.5251119136810303,2.72934889793396,2.9335858821868896,3.1563899517059326,3.3791940212249756,3.6019980907440186,3.8248019218444824,4.047605991363525,4.270410060882568 };

            /*******霜袭
            技能伤害|{param1:P}
            冷却时间|{param2:F1}秒
            */

            
                    const static double* Skill_2_1 = new double[15]{ 1.9119999408721924,2.0553998947143555,2.1988000869750977,2.390000104904175,2.533400058746338,2.676800012588501,2.868000030517578,3.0592000484466553,3.2504000663757324,3.4416000843048096,3.6328001022338867,3.8239998817443848,4.063000202178955,4.302000045776367,4.540999889373779 };
                    const static double* Skill_2_2 = new double[15]{ 6,6,6,6,6,6,6,6,6,6,6,6,6,6,6 };

            /*******凛冽轮舞
            技能伤害|{param1:F1P}
            冷却时间|{param2:F1}秒
            持续时间|{param3:F1}秒
            元素能量|{param4:I}
            */

            
                    const static double* Skill_3_1 = new double[15]{ 0.7760000228881836,0.8342000246047974,0.8924000263214111,0.9700000286102295,1.0282000303268433,1.086400032043457,1.1640000343322754,1.2416000366210938,1.319200038909912,1.3968000411987305,1.4744000434875488,1.5520000457763672,1.6490000486373901,1.746000051498413,1.843000054359436 };
                    const static double* Skill_3_2 = new double[15]{ 15,15,15,15,15,15,15,15,15,15,15,15,15,15,15 };
                    const static double* Skill_3_3 = new double[15]{ 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8 };
                    const static double* Skill_3_4 = new double[15]{ 60,60,60,60,60,60,60,60,60,60,60,60,60,60,60 };
        /*****凯亚
        
            ***1命***
            卓越的血脉            
            对受到冰元素影响的敌人，凯亚的普通攻击与重击暴击率提升15%。
            
            ***2命***
            无尽的霜舞            
            在❤凛冽轮舞❤的持续时间内击败敌人时，持续时间延长2.5秒，最多不会超过15秒。
            
            ***3命***
            凛冽的冰戏            
            ❤霜袭❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            极寒的轻吻            
            凯亚的生命值低于20%时自动触发：生成一个伤害吸收量等于生命值上限30%的护盾，持续20秒。该护盾对冰元素伤害有250%的吸收效果。该效果每60秒只能触发一次。
            
            ***5命***
            至冷的拥抱            
            ❤凛冽轮舞❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            轮旋的冰凌            
            ❤凛冽轮舞❤会产生一个额外的寒冰之棱，并在施放时返还15点元素能量。
            
        */
        void 凯亚::A(Role* role, u8* cmd) {
        };
        void 凯亚::Q(Role* role, u8* cmd) {        
        };
        void 凯亚::E(Role* role, u8* cmd) {        
        };    
        }
        