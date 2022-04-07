﻿
        #include "埃洛伊.h"
        using namespace Role;
        //TODO:AUTO埃洛伊.cpp
        const double HP =  10898.860644005588;
        const double ATK =  233.916461193734;
        const double DEF =  676.3278506341303;
        //冰元素伤害加成
        const double OTHER = 0.2879999876022339;
        
        namespace Cryo{
        埃洛伊::~埃洛伊() {
        }
        埃洛伊::埃洛伊() {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Cryo, WeaponType::Bow);
            delete baseData;
        };        

        /*
        
        ****1:战斗覆盖
        ****************
        
            埃洛伊获得❤冰尘雪野❤的线圈效果时，埃洛伊的攻击力提升16%，队伍中附近的其他角色的攻击力提升8%，持续10秒。 

        ****************
        

        ****2:强力攻击
        ****************
        
            埃洛伊处于❤冰尘雪野❤的冰驰状态下时，每1秒提升3.5%冰元素伤害加成，通过这种方式至多获得35%冰元素伤害加成。 

        ****************
        

        ****3:荒野猎手
        ****************
        
            埃洛伊在队伍中时，队伍中自己的角色接近产出禽肉、兽肉与冷鲜肉的小动物时，不会轻易惊动它们。 

        ****************
        
        */
        
            /*******普通攻击·快速射击
            一段伤害|{param1:F1P}+{param2:F1P}
            二段伤害|{param3:F1P}
            三段伤害|{param4:F1P}
            四段伤害|{param5:F1P}
            瞄准射击|{param6:F1P}
            满蓄力瞄准射击|{param7:P}
            下坠期间伤害|{param8:F1P}
            低空/高空坠地冲击伤害|{param9:P}/{param10:P}
            */

            
                    const static double* Skill_1_1 = new double[15]{ 0.21119999885559082,0.225600004196167,0.23999999463558197,0.25920000672340393,0.2736000120639801,0.2903999984264374,0.31200000643730164,0.3336000144481659,0.35519999265670776,0.376800000667572,0.3984000086784363,0.41999998688697815,0.4415999948978424,0.46320000290870667,0.4848000109195709 };
                    const static double* Skill_1_2 = new double[15]{ 0.23759999871253967,0.25380000472068787,0.27000001072883606,0.29159998893737793,0.3077999949455261,0.32670000195503235,0.35100001096725464,0.37529999017715454,0.39959999918937683,0.4239000082015991,0.448199987411499,0.4724999964237213,0.4968000054359436,0.5210999846458435,0.5454000234603882 };
                    const static double* Skill_1_3 = new double[15]{ 0.4311999976634979,0.46059998869895935,0.49000000953674316,0.52920001745224,0.5586000084877014,0.5928999781608582,0.6370000243186951,0.6811000108718872,0.7251999974250793,0.7692999839782715,0.8133999705314636,0.8575000166893005,0.9016000032424927,0.9456999897956848,0.989799976348877 };
                    const static double* Skill_1_4 = new double[15]{ 0.527999997138977,0.5640000104904175,0.6000000238418579,0.6480000019073486,0.6840000152587891,0.7260000109672546,0.7799999713897705,0.8339999914169312,0.8880000114440918,0.9419999718666077,0.9959999918937683,1.0499999523162842,1.1039999723434448,1.1579999923706055,1.2120000123977661 };
                    const static double* Skill_1_5 = new double[15]{ 0.6564800143241882,0.7012400031089783,0.7459999918937683,0.805679976940155,0.8504400253295898,0.9026600122451782,0.9697999954223633,1.0369399785995483,1.1040799617767334,1.1712199449539185,1.238360047340393,1.3055000305175781,1.3726400136947632,1.4397799968719482,1.5069199800491333 };
                    const static double* Skill_1_6 = new double[15]{ 0.43860000371932983,0.47429999709129333,0.5099999904632568,0.5609999895095825,0.5967000126838684,0.637499988079071,0.6935999989509583,0.7497000098228455,0.8058000206947327,0.8669999837875366,0.9282000064849854,0.9894000291824341,1.0506000518798828,1.111799955368042,1.1729999780654907 };
                    const static double* Skill_1_7 = new double[15]{ 1.2400000095367432,1.3329999446868896,1.4259999990463257,1.5499999523162842,1.6430000066757202,1.7359999418258667,1.8600000143051147,1.9839999675750732,2.1080000400543213,2.2320001125335693,2.3559999465942383,2.4800000190734863,2.634999990463257,2.7899999618530273,2.944999933242798 };
                    const static double* Skill_1_8 = new double[15]{ 0.5682880282402039,0.6145439743995667,0.6607999801635742,0.7268800139427185,0.7731360197067261,0.8259999752044678,0.898688018321991,0.9713760018348694,1.0440640449523926,1.12336003780365,1.2026560306549072,1.2819520235061646,1.3612480163574219,1.4405440092086792,1.5198400020599365 };
                    const static double* Skill_1_9 = new double[15]{ 1.136335015296936,1.228827953338623,1.3213200569152832,1.4534519910812378,1.5459439754486084,1.6516499519348145,1.7969950437545776,1.9423400163650513,2.087686061859131,2.246243953704834,2.404802083969116,2.5633609294891357,2.721919059753418,2.8804779052734375,3.0390360355377197 };
                    const static double* Skill_1_10 = new double[15]{ 1.4193439483642578,1.534872055053711,1.6504000425338745,1.815440058708191,1.9309680461883545,2.062999963760376,2.24454402923584,2.4260880947113037,2.6076319217681885,2.8056800365448,3.003727912902832,3.2017760276794434,3.3998239040374756,3.597872018814087,3.795919895172119 };

            /*******冰尘雪野
            冰尘弹伤害|{param1:P}
            冷冻炸弹伤害|{param2:F1P}
            攻击力降低|{param3:P}
            攻击力降低持续时间|{param4:F1}秒
            线圈普通攻击伤害提升|{param5:F1P}/{param6:F1P}/{param7:F1P}
            冰驰普通攻击伤害提升|{param8:F1P}
            冰驰持续时间|{param9:F1}秒
            冷却时间|{param10:F1}秒
            */

            
                    const static double* Skill_2_1 = new double[15]{ 1.7760000228881836,1.9091999530792236,2.0423998832702637,2.2200000286102295,2.3531999588012695,2.4863998889923096,2.6640000343322754,2.841599941253662,3.019200086593628,3.1967999935150146,3.3743999004364014,3.552000045776367,3.7739999294281006,3.996000051498413,4.2179999351501465 };
                    const static double* Skill_2_2 = new double[15]{ 0.4000000059604645,0.4300000071525574,0.46000000834465027,0.5,0.5299999713897705,0.5600000023841858,0.6000000238418579,0.6399999856948853,0.6800000071525574,0.7200000286102295,0.7599999904632568,0.800000011920929,0.8500000238418579,0.8999999761581421,0.949999988079071 };
                    const static double* Skill_2_3 = new double[15]{ 0.11999999731779099,0.11999999731779099,0.11999999731779099,0.12999999523162842,0.12999999523162842,0.12999999523162842,0.14000000059604645,0.14000000059604645,0.14000000059604645,0.15000000596046448,0.15000000596046448,0.15000000596046448,0.15000000596046448,0.15000000596046448,0.15000000596046448 };
                    const static double* Skill_2_4 = new double[15]{ 6,6,6,6,6,6,6,6,6,6,6,6,6,6,6 };
                    const static double* Skill_2_5 = new double[15]{ 0.05844999849796295,0.06194999814033508,0.06544999778270721,0.07000000029802322,0.07349999994039536,0.07699999958276749,0.0815500020980835,0.08609999716281891,0.09064999967813492,0.09520000219345093,0.09974999725818634,0.10429999977350235,0.10885000228881836,0.11339999735355377,0.11794999986886978 };
                    const static double* Skill_2_6 = new double[15]{ 0.1168999969959259,0.12389999628067017,0.13089999556541443,0.14000000059604645,0.1469999998807907,0.15399999916553497,0.163100004196167,0.17219999432563782,0.18129999935626984,0.19040000438690186,0.19949999451637268,0.2085999995470047,0.21770000457763672,0.22679999470710754,0.23589999973773956 };
                    const static double* Skill_2_7 = new double[15]{ 0.17534999549388885,0.18584999442100525,0.19634999334812164,0.20999999344348907,0.22050000727176666,0.23100000619888306,0.2446500062942505,0.2583000063896179,0.27195000648498535,0.2856000065803528,0.2992500066757202,0.31290000677108765,0.3265500068664551,0.3402000069618225,0.35385000705718994 };
                    const static double* Skill_2_8 = new double[15]{ 0.29225000739097595,0.3097499907016754,0.32725000381469727,0.3499999940395355,0.3675000071525574,0.38499999046325684,0.4077500104904175,0.43050000071525574,0.453249990940094,0.47600001096725464,0.4987500011920929,0.5214999914169312,0.5442500114440918,0.5669999718666077,0.5897499918937683 };
                    const static double* Skill_2_9 = new double[15]{ 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
                    const static double* Skill_2_10 = new double[15]{ 20,20,20,20,20,20,20,20,20,20,20,20,20,20,20 };

            /*******曙光预言
            技能伤害|{param1:P}
            冷却时间|{param2:F1}秒
            元素能量|{param3:I}
            */

            
                    const static double* Skill_3_1 = new double[15]{ 3.5920000076293945,3.8613998889923096,4.130799770355225,4.489999771118164,4.759399890899658,5.028800010681152,5.388000011444092,5.747200012207031,6.106400012969971,6.46560001373291,6.82480001449585,7.184000015258789,7.632999897003174,8.081999778747559,8.531000137329102 };
                    const static double* Skill_3_2 = new double[15]{ 12,12,12,12,12,12,12,12,12,12,12,12,12,12,12 };
                    const static double* Skill_3_3 = new double[15]{ 40,40,40,40,40,40,40,40,40,40,40,40,40,40,40 };
        /*****埃洛伊
        
            ***1命***
            异界之星            
            点亮此人一方星空之刻尚未到来。
            
            ***2命***
            异界之星            
            点亮此人一方星空之刻尚未到来。
            
            ***3命***
            异界之星            
            点亮此人一方星空之刻尚未到来。
            
            ***4命***
            异界之星            
            点亮此人一方星空之刻尚未到来。
            
            ***5命***
            异界之星            
            点亮此人一方星空之刻尚未到来。
            
            ***6命***
            异界之星            
            点亮此人一方星空之刻尚未到来。
            
        */
        void 埃洛伊::A(Role* role, u8* cmd) {
        };
        void 埃洛伊::Q(Role* role, u8* cmd) {        
        };
        void 埃洛伊::E(Role* role, u8* cmd) {        
        };    
        }
        