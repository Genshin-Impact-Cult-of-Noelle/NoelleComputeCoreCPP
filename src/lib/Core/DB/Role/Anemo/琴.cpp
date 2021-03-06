#pragma once
        #include "琴.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO琴.cpp
        const double HP =  14695.093513910891;
        const double ATK =  239.17839184791592;
        const double DEF =  768.55440212143;
        //治疗加成
        const double OTHER = 0.2214999943971634;
        
        琴::~琴() {
        }
        琴::琴(u32* frameCur):Role(frameCur) {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Anemo, WeaponType::Sword);
            delete baseData;
        };        

        /*
        
        ****1:顺风而行
        ****************
        
            琴的普通攻击命中时，有50%的几率为队伍中所有角色恢复等同于琴攻击力15%的生命值。 

        ****************
        

        ****2:听凭风引
        ****************
        
            使用❤蒲公英之风❤后，恢复20%元素能量。 

        ****************
        

        ****3:引领之风
        ****************
        
            完美烹饪恢复类食物时，有12%概率获得2倍产出。 

        ****************
        
        */
        
            /*******普通攻击·西风剑术
             * 
             * **普通攻击**
             * 进行至多五段的连续剑击。
             * 
             * **重击**
             * 消耗一定体力，进行饱含风之力的挑击。
             * 被挑飞的敌人，在短时间内会缓慢坠落。
             * 
             * **下落攻击**
             * 从空中下坠冲击地面，攻击下落路径上的敌人，并在落地时造成范围伤害。
             * 
             * 一段伤害|{param1:F1P}
             * 二段伤害|{param2:F1P}
             * 三段伤害|{param3:F1P}
             * 四段伤害|{param4:F1P}
             * 五段伤害|{param5:F1P}
             * 重击伤害|{param6:P}
             * 重击体力消耗|{param7:F1}点
             * 下坠期间伤害|{param8:F1P}
             * 低空/高空坠地冲击伤害|{param9:P}/{param10:P}
            */
            void 琴::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[10]{ 0.4833199977874756,0.45579999685287476,0.6028599739074707,0.6587600111961365,0.7920600175857544,1.6202399730682373,20,0.6393240094184875,1.2783770561218262,1.59676194190979},
                        new const double[10]{ 0.5226600170135498,0.492900013923645,0.6519299745559692,0.7123799920082092,0.8565300107002258,1.752120018005371,20,0.6913620233535767,1.3824310302734375,1.7267309427261353},
                        new const double[10]{ 0.5619999766349792,0.5299999713897705,0.7009999752044678,0.765999972820282,0.9210000038146973,1.8839999437332153,20,0.743399977684021,1.4864850044250488,1.8566999435424805},
                        new const double[10]{ 0.6182000041007996,0.5830000042915344,0.7710999846458435,0.8425999879837036,1.013100028038025,2.0724000930786133,20,0.8177400231361389,1.635133981704712,2.042370080947876},
                        new const double[10]{ 0.6575400233268738,0.6201000213623047,0.820169985294342,0.8962200284004211,1.0775699615478516,2.204279899597168,20,0.8697779774665833,1.7391870021820068,2.1723389625549316},
                        new const double[10]{ 0.7024999856948853,0.6625000238418579,0.8762500286102295,0.9574999809265137,1.1512500047683716,2.3550000190734863,20,0.9292500019073486,1.858106017112732,2.3208749294281006},
                        new const double[10]{ 0.7643200159072876,0.72079998254776,0.9533600211143494,1.041759967803955,1.252560019493103,2.5622398853302,20,1.011023998260498,2.021620035171509,2.5251119136810303},
                        new const double[10]{ 0.8261399865150452,0.7791000008583069,1.0304700136184692,1.1260199546813965,1.3538700342178345,2.769479990005493,20,1.0927979946136475,2.1851329803466797,2.72934889793396},
                        new const double[10]{ 0.8879600167274475,0.8374000191688538,1.1075799465179443,1.210279941558838,1.455180048942566,2.976720094680786,20,1.1745719909667969,2.3486459255218506,2.9335858821868896},
                        new const double[10]{ 0.9553999900817871,0.9010000228881836,1.1916999816894531,1.3021999597549438,1.5657000541687012,3.2028000354766846,20,1.2637799978256226,2.527024984359741,3.1563899517059326},
                        new const double[10]{ 1.03267502784729,0.9738749861717224,1.2880879640579224,1.4075249433517456,1.692337989807129,3.4618499279022217,20,1.3529880046844482,2.7054030895233154,3.3791940212249756},
                        new const double[10]{ 1.1235500574111938,1.0595760345458984,1.4014389514923096,1.5313869714736938,1.8412630558013916,3.766493082046509,20,1.442196011543274,2.8837809562683105,3.6019980907440186},
                        new const double[10]{ 1.214426040649414,1.1452770233154297,1.5147910118103027,1.655248999595642,1.9901889562606812,4.071135997772217,20,1.5314040184020996,3.0621590614318848,3.8248019218444824},
                        new const double[10]{ 1.3053009510040283,1.230978012084961,1.6281429529190063,1.7791119813919067,2.13911509513855,4.3757781982421875,20,1.6206120252609253,3.24053692817688,4.047605991363525},
                        new const double[10]{ 1.4044380187988281,1.324470043182373,1.7517989873886108,1.9142340421676636,2.301578998565674,4.708116054534912,20,1.709820032119751,3.418915033340454,4.270410060882568}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******风压剑
             * 
             * 将无形的风之力汇聚在剑上，释放微型的风暴，将敌人向瞄准的方向击飞，造成大量风元素伤害。
             * 
             * **长按**
             * 以持续消耗体力为代价，令旋风将周围的敌人与物体牵引至面前。
             * 可以调整方向。
             * 期间无法移动。
             * 
             * 技能伤害|{param1:P}
             * 体力消耗|每秒{param2:F1}点
             * 最大持续时间|{param3:F1}秒
             * 冷却时间|{param4:F1}秒
            */
            void 琴::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[4]{ 2.9200000762939453,20,5,6},
                        new const double[4]{ 3.1389999389648438,20,5,6},
                        new const double[4]{ 3.3580000400543213,20,5,6},
                        new const double[4]{ 3.6500000953674316,20,5,6},
                        new const double[4]{ 3.86899995803833,20,5,6},
                        new const double[4]{ 4.0879998207092285,20,5,6},
                        new const double[4]{ 4.380000114440918,20,5,6},
                        new const double[4]{ 4.671999931335449,20,5,6},
                        new const double[4]{ 4.964000225067139,20,5,6},
                        new const double[4]{ 5.25600004196167,20,5,6},
                        new const double[4]{ 5.547999858856201,20,5,6},
                        new const double[4]{ 5.840000152587891,20,5,6},
                        new const double[4]{ 6.204999923706055,20,5,6},
                        new const double[4]{ 6.570000171661377,20,5,6},
                        new const double[4]{ 6.934999942779541,20,5,6}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******蒲公英之风
             * 
             * 呼唤风的护佑，创造千风涌动的蒲公英领域，击退周围的敌人并造成风元素伤害。
             * 同时，为队伍中的所有角色瞬间恢复大量生命值，回复量受益于琴的攻击力。
             * 
             * **蒲公英领域**
             * ·为其中的角色持续恢复生命值；
             * ·令其中的角色持续受到风元素影响；
             * ·对出入领域的敌人造成风元素伤害。
             * 
             * 爆发伤害|{param1:P}
             * 出入领域伤害|{param2:F1P}
             * 领域发动治疗量|{param3:P}攻击力+{param4:I}
             * 持续治疗|每秒{param5:F2P}攻击力+{param6:I}
             * 冷却时间|{param7:F1}秒
             * 元素能量|{param8:I}
            */
            void 琴::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[8]{ 4.248000144958496,0.7839999794960022,2.51200008392334,1540.3248291015625,0.25119999051094055,154.03248596191406,20,80},
                        new const double[8]{ 4.5665998458862305,0.8428000211715698,2.7004001140594482,1694.3787841796875,0.27004000544548035,169.43788146972656,20,80},
                        new const double[8]{ 4.885200023651123,0.9016000032424927,2.8887999057769775,1861.2705078125,0.28887999057769775,186.12704467773438,20,80},
                        new const double[8]{ 5.309999942779541,0.9800000190734863,3.140000104904175,2041,0.3140000104904175,204.10000610351562,20,80},
                        new const double[8]{ 5.628600120544434,1.0388000011444092,3.328399896621704,2233.5673828125,0.3328399956226349,223.3567352294922,20,80},
                        new const double[8]{ 5.947199821472168,1.097599983215332,3.5167999267578125,2438.97265625,0.3516800105571747,243.8972625732422,20,80},
                        new const double[8]{ 6.372000217437744,1.1759999990463257,3.7679998874664307,2657.215576171875,0.376800000667572,265.7215576171875,20,80},
                        new const double[8]{ 6.796800136566162,1.2544000148773193,4.019199848175049,2888.29638671875,0.40191999077796936,288.82965087890625,20,80},
                        new const double[8]{ 7.22160005569458,1.332800030708313,4.270400047302246,3132.215087890625,0.4270400106906891,313.22149658203125,20,80},
                        new const double[8]{ 7.646399974822998,1.4112000465393066,4.521599769592285,3388.9716796875,0.4521600008010864,338.89715576171875,20,80},
                        new const double[8]{ 8.071200370788574,1.4895999431610107,4.772799968719482,3658.56591796875,0.47727999091148376,365.8565979003906,20,80},
                        new const double[8]{ 8.496000289916992,1.5679999589920044,5.02400016784668,3940.998046875,0.5023999810218811,394.09979248046875,20,80},
                        new const double[8]{ 9.027000427246094,1.6660000085830688,5.3379998207092285,4236.26806640625,0.5338000059127808,423.6268005371094,20,80},
                        new const double[8]{ 9.557999610900879,1.7640000581741333,5.6519999504089355,4544.3759765625,0.5651999711990356,454.4375915527344,20,80},
                        new const double[8]{ 10.08899974822998,1.8619999885559082,5.966000080108643,4865.3212890625,0.5965999960899353,486.5321350097656,20,80}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };
        /*****琴
        
            ***1命***
            流转剑脊的暴风            
            ❤风压剑❤长按超过1秒后，提升牵引速度，并使造成的伤害提升40%。
            
            ***2命***
            守护众人的坚盾            
            琴获得元素晶球或元素微粒时，队伍中所有角色获得15%攻击速度和15%移动速度提升，持续15秒。
            
            ***3命***
            西风吹拂之时            
            ❤蒲公英之风❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            蒲公英的国土            
            在❤蒲公英之风❤的领域内，所有敌人的风元素抗性下降40%。
            
            ***5命***
            须臾一瞬的烈风            
            ❤风压剑❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            恩眷万民的狮牙            
            在❤蒲公英之风❤的领域内，角色受到的伤害降低35%。离开领域后，这个效果会在承受3次攻击或10秒后消失。
            
        */
         
        