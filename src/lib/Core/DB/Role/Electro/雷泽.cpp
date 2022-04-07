﻿
        #include "雷泽.h"
        using namespace Role;
        //TODO:AUTO雷泽.cpp
        const double HP =  11962.406412468641;
        const double ATK =  233.63691357027892;
        const double DEF =  750.7736681492424;
        //物理伤害加成
        const double OTHER = 0.30000001192092896;
        
        namespace Electro{
        雷泽::~雷泽() {
        }
        雷泽::雷泽() {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Male, CharacterGroup::Tivat, ElementType::Electro, WeaponType::Claymore);
            delete baseData;
        };        

        /*
        
        ****1:觉醒
        ****************
        
            ❤利爪与苍雷❤的冷却时间减少18%。
            施放❤雷牙❤时，重置❤利爪与苍雷❤的冷却时间。 

        ****************
        

        ****2:饥饿
        ****************
        
            雷泽的元素能量在50%以下时，元素充能效率提高30%。 

        ****************
        

        ****3:奔狼
        ****************
        
            队伍中自己的角色冲刺消耗的体力降低20%。
            无法与效果完全相同的固有天赋叠加。 

        ****************
        
        */
        
            /*******普通攻击·钢脊
            一段伤害|{param1:F1P}
            二段伤害|{param2:F1P}
            三段伤害|{param3:P}
            四段伤害|{param4:P}
            重击循环伤害|{param5:F1P}
            重击终结伤害|{param6:P}
            重击体力消耗|每秒{param7:F1}点
            最大持续时间|{param8:F1}秒
            下坠期间伤害|{param9:F1P}
            低空/高空坠地冲击伤害|{param10:P}/{param11:P}
            */

            
                    const static double* Skill_1_1 = new double[15]{ 0.9592000246047974,1.0246000289916992,1.090000033378601,1.1771999597549438,1.2425999641418457,1.3188999891281128,1.4170000553131104,1.5151000022888184,1.6131999492645264,1.711300015449524,1.809399962425232,1.9075000286102295,2.0055999755859375,2.1036999225616455,2.2018001079559326 };
                    const static double* Skill_1_2 = new double[15]{ 0.8263199925422668,0.8826599717140198,0.9390000104904175,1.0141199827194214,1.0704599618911743,1.1361900568008423,1.2207000255584717,1.305209994316101,1.3897199630737305,1.4742300510406494,1.5587400197982788,1.6432499885559082,1.7277599573135376,1.8122700452804565,1.896780014038086 };
                    const static double* Skill_1_3 = new double[15]{ 1.033120036125183,1.103559970855713,1.1740000247955322,1.2679200172424316,1.3383599519729614,1.4205399751663208,1.5262000560760498,1.6318600177764893,1.7375199794769287,1.8431799411773682,1.9488400220870972,2.054500102996826,2.1601600646972656,2.265820026397705,2.3714799880981445 };
                    const static double* Skill_1_4 = new double[15]{ 1.3604799509048462,1.4532400369644165,1.5460000038146973,1.6696799993515015,1.7624399662017822,1.8706599473953247,2.0097999572753906,2.148940086364746,2.2880799770355225,2.427220106124878,2.5663599967956543,2.7054998874664307,2.844640016555786,2.9837799072265625,3.122920036315918 };
                    const static double* Skill_1_5 = new double[15]{ 0.6253920197486877,0.6762959957122803,0.7271999716758728,0.7999200224876404,0.8508239984512329,0.9089999794960022,0.9889919757843018,1.068984031677246,1.1489759683609009,1.236240029335022,1.3235039710998535,1.4107680320739746,1.4980319738388062,1.5852960348129272,1.6725599765777588 };
                    const static double* Skill_1_6 = new double[15]{ 1.1309000253677368,1.2229499816894531,1.315000057220459,1.4464999437332153,1.5385500192642212,1.6437499523162842,1.7884000539779663,1.9330500364303589,2.077699899673462,2.2355000972747803,2.3933000564575195,2.551100015640259,2.708899974822998,2.8666999340057373,3.0244998931884766 };
                    const static double* Skill_1_7 = new double[15]{ 40,40,40,40,40,40,40,40,40,40,40,40,40,40,40 };
                    const static double* Skill_1_8 = new double[15]{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 };
                    const static double* Skill_1_9 = new double[15]{ 0.8204659819602966,0.8872479796409607,0.9540299773216248,1.0494329929351807,1.1162149906158447,1.1925380229949951,1.2974809408187866,1.4024239778518677,1.5073670148849487,1.6218509674072266,1.736335039138794,1.8508180379867554,1.9653019905090332,2.079785108566284,2.1942689418792725 };
                    const static double* Skill_1_10 = new double[15]{ 1.6405839920043945,1.7741199731826782,1.907655954360962,2.098421096801758,2.231956958770752,2.3845698833465576,2.594412088394165,2.8042540550231934,3.0140960216522217,3.2430150508880615,3.471932888031006,3.7008519172668457,3.9297709465026855,4.158689975738525,4.387608051300049 };
                    const static double* Skill_1_11 = new double[15]{ 2.049177885055542,2.215970993041992,2.382765054702759,2.621042013168335,2.787834882736206,2.9784560203552246,3.2405600547790527,3.5026650428771973,3.7647690773010254,4.050701141357422,4.336631774902344,4.62256383895874,4.908495903015137,5.194427967071533,5.48036003112793 };

            /*******利爪与苍雷
            点按技能伤害|{param1:P}
            长按技能伤害|{param2:P}
            雷之印充能效率提升|每个{param3:P}
            雷之印吸收恢复能量|每个{param4:F1}点
            雷之印持续时间|{param5:F1}秒
            点按冷却时间|{param6:F1}秒
            长按冷却时间|{param7:F1}秒
            */

            
                    const static double* Skill_2_1 = new double[15]{ 1.9919999837875366,2.141400098800659,2.290800094604492,2.490000009536743,2.639400005340576,2.788800001144409,2.98799991607666,3.1872000694274902,3.386399984359741,3.585599899291992,3.7848000526428223,3.9839999675750732,4.232999801635742,4.48199987411499,4.730999946594238 };
                    const static double* Skill_2_2 = new double[15]{ 2.9519999027252197,3.1733999252319336,3.3947999477386475,3.690000057220459,3.911400079727173,4.132800102233887,4.427999973297119,4.723199844360352,5.018400192260742,5.313600063323975,5.608799934387207,5.9039998054504395,6.2729997634887695,6.642000198364258,7.011000156402588 };
                    const static double* Skill_2_3 = new double[15]{ 0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224,0.20000000298023224 };
                    const static double* Skill_2_4 = new double[15]{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 };
                    const static double* Skill_2_5 = new double[15]{ 18,18,18,18,18,18,18,18,18,18,18,18,18,18,18 };
                    const static double* Skill_2_6 = new double[15]{ 6,6,6,6,6,6,6,6,6,6,6,6,6,6,6 };
                    const static double* Skill_2_7 = new double[15]{ 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };

            /*******雷牙
            爆发伤害|{param1:P}
            狼魂伤害|{param2:F1P}普通攻击伤害
            普通攻击速度提升|{param3:P}
            雷元素抗性提升|{param4:P}
            持续时间|{param5:F1}秒
            冷却时间|{param6:F1}秒
            元素能量|{param7:I}
            */

            
                    const static double* Skill_3_1 = new double[15]{ 1.600000023841858,1.7200000286102295,1.840000033378601,2,2.119999885559082,2.240000009536743,2.4000000953674316,2.559999942779541,2.7200000286102295,2.880000114440918,3.0399999618530273,3.200000047683716,3.4000000953674316,3.5999999046325684,3.799999952316284 };
                    const static double* Skill_3_2 = new double[15]{ 0.23999999463558197,0.257999986410141,0.2759999930858612,0.30000001192092896,0.3179999887943268,0.335999995470047,0.36000001430511475,0.3840000033378601,0.40799999237060547,0.4320000112056732,0.4560000002384186,0.47999998927116394,0.5099999904632568,0.5400000214576721,0.5699999928474426 };
                    const static double* Skill_3_3 = new double[15]{ 0.25999999046325684,0.2800000011920929,0.30000001192092896,0.3199999928474426,0.3400000035762787,0.36000001430511475,0.3700000047683716,0.3799999952316284,0.38999998569488525,0.4000000059604645,0.4000000059604645,0.4000000059604645,0.4000000059604645,0.4000000059604645,0.4000000059604645 };
                    const static double* Skill_3_4 = new double[15]{ 0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929,0.800000011920929 };
                    const static double* Skill_3_5 = new double[15]{ 15,15,15,15,15,15,15,15,15,15,15,15,15,15,15 };
                    const static double* Skill_3_6 = new double[15]{ 20,20,20,20,20,20,20,20,20,20,20,20,20,20,20 };
                    const static double* Skill_3_7 = new double[15]{ 80,80,80,80,80,80,80,80,80,80,80,80,80,80,80 };
        /*****雷泽
        
            ***1命***
            狼性            
            雷泽获取元素晶球或元素微粒后的8秒内，造成的伤害提高10%。
            
            ***2命***
            压制            
            雷泽攻击生命值低于30%的敌人时，暴击率提高10%。
            
            ***3命***
            兽魂            
            ❤雷牙❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            撕咬            
            ❤利爪与苍雷❤点按时，会使命中的敌人防御力降低15%，持续7秒。
            
            ***5命***
            利爪            
            ❤利爪与苍雷❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            天狼            
            每10秒，雷泽的大剑将自动充能，使下一次普通攻击引发落雷，造成100%攻击力的雷元素伤害。不处于❤雷牙❤状态下时，若落雷击中敌人，会为雷泽积攒一个❤利爪与苍雷❤的雷之印。
            
        */
        void 雷泽::A(Role* role, u8* cmd) {
        };
        void 雷泽::Q(Role* role, u8* cmd) {        
        };
        void 雷泽::E(Role* role, u8* cmd) {        
        };    
        }
        