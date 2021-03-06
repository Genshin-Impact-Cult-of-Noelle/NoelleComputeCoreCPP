#pragma once
        #include "迪奥娜.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO迪奥娜.cpp
        const double HP =  9569.92523615167;
        const double ATK =  212.39719698963927;
        const double DEF =  600.6189477914886;
        //冰元素伤害加成
        const double OTHER = 0.23999999463558197;
        
        迪奥娜::~迪奥娜() {
        }
        迪奥娜::迪奥娜(u32* frameCur):Role(frameCur) {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Cryo, WeaponType::Bow);
            delete baseData;
        };        

        /*
        
        ****1:猫尾隐藏菜单
        ****************
        
            处于❤猫爪冻冻❤的护盾保护下的角色，移动速度提升10%，体力消耗降低10%。 

        ****************
        

        ****2:滑稽百出的醉相
        ****************
        
            敌人进入❤最烈特调❤的领域后的15秒内，攻击力降低10%。 

        ****************
        

        ****3:附赠的下酒菜
        ****************
        
            完美烹饪恢复类食物时，有12%概率获得2倍产出。 

        ****************
        
        */
        
            /*******普通攻击·猎人射术
             * 
             * **普通攻击**
             * 进行至多五段的连续弓箭射击。
             * 
             * **重击**
             * 进行伤害更高、更为精准的**瞄准射击**。
             * 瞄准时，冰霜散发的寒气会凭附在箭矢上。聚满了寒气的箭矢会造成冰元素伤害。
             * 
             * **下落攻击**
             * 从空中射出箭雨，并迅速下坠冲击地面，在落地时造成范围伤害。
             * 
             * 一段伤害|{param1:F1P}
             * 二段伤害|{param2:F1P}
             * 三段伤害|{param3:F1P}
             * 四段伤害|{param4:F1P}
             * 五段伤害|{param5:F1P}
             * 瞄准射击|{param7:F1P}
             * 满蓄力瞄准射击|{param8:P}
             * 下坠期间伤害|{param9:F1P}
             * 低空/高空坠地冲击伤害|{param10:P}/{param11:P}
            */
            void 迪奥娜::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[10]{ 0.3612000048160553,0.3353999853134155,0.45579999685287476,0.4300000071525574,0.5375000238418579,0.43860000371932983,1.2400000095367432,0.5682880282402039,1.136335015296936,1.4193439483642578},
                        new const double[10]{ 0.3905999958515167,0.3626999855041504,0.492900013923645,0.4650000035762787,0.581250011920929,0.47429999709129333,1.3329999446868896,0.6145439743995667,1.228827953338623,1.534872055053711},
                        new const double[10]{ 0.41999998688697815,0.38999998569488525,0.5299999713897705,0.5,0.625,0.5099999904632568,1.4259999990463257,0.6607999801635742,1.3213200569152832,1.6504000425338745},
                        new const double[10]{ 0.4620000123977661,0.42899999022483826,0.5830000042915344,0.550000011920929,0.6875,0.5609999895095825,1.5499999523162842,0.7268800139427185,1.4534519910812378,1.815440058708191},
                        new const double[10]{ 0.49140000343322754,0.4562999904155731,0.6201000213623047,0.5849999785423279,0.731249988079071,0.5967000126838684,1.6430000066757202,0.7731360197067261,1.5459439754486084,1.9309680461883545},
                        new const double[10]{ 0.5249999761581421,0.48750001192092896,0.6625000238418579,0.625,0.78125,0.637499988079071,1.7359999418258667,0.8259999752044678,1.6516499519348145,2.062999963760376},
                        new const double[10]{ 0.5712000131607056,0.5303999781608582,0.72079998254776,0.6800000071525574,0.8500000238418579,0.6935999989509583,1.8600000143051147,0.898688018321991,1.7969950437545776,2.24454402923584},
                        new const double[10]{ 0.6173999905586243,0.5733000040054321,0.7791000008583069,0.7350000143051147,0.918749988079071,0.7497000098228455,1.9839999675750732,0.9713760018348694,1.9423400163650513,2.4260880947113037},
                        new const double[10]{ 0.6636000275611877,0.6161999702453613,0.8374000191688538,0.7900000214576721,0.987500011920929,0.8058000206947327,2.1080000400543213,1.0440640449523926,2.087686061859131,2.6076319217681885},
                        new const double[10]{ 0.7139999866485596,0.6629999876022339,0.9010000228881836,0.8500000238418579,1.0625,0.8669999837875366,2.2320001125335693,1.12336003780365,2.246243953704834,2.8056800365448},
                        new const double[10]{ 0.7717499732971191,0.7166249752044678,0.9738749861717224,0.918749988079071,1.1484379768371582,0.937125027179718,2.360960006713867,1.2026560306549072,2.404802083969116,3.003727912902832},
                        new const double[10]{ 0.8396639823913574,0.7796880006790161,1.0595760345458984,0.9995999932289124,1.249500036239624,1.019592046737671,2.529599905014038,1.2819520235061646,2.5633609294891357,3.2017760276794434},
                        new const double[10]{ 0.9075779914855957,0.8427510261535645,1.1452770233154297,1.0804500579833984,1.3505619764328003,1.102059006690979,2.698240041732788,1.3612480163574219,2.721919059753418,3.3998239040374756},
                        new const double[10]{ 0.975492000579834,0.905813992023468,1.230978012084961,1.1612999439239502,1.4516249895095825,1.184525966644287,2.866879940032959,1.4405440092086792,2.8804779052734375,3.597872018814087},
                        new const double[10]{ 1.0495799779891968,0.9746099710464478,1.324470043182373,1.249500036239624,1.5618749856948853,1.2744899988174438,3.035520076751709,1.5198400020599365,3.0390360355377197,3.795919895172119}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******猫爪冻冻
             * 
             * 发射冻冻猫猫爪，对敌人造成冰元素伤害，并在命中时形成护盾。
             * 护盾的伤害吸收量受益于迪奥娜的生命值上限，持续时间基于命中的冻冻猫猫爪数目。
             * 
             * **点按**
             * 快速发射二枚冻冻猫猫爪。
             * 
             * **长按**
             * 迅速后撤，并发射五枚冻冻猫猫爪。
             * 通过长按产生的护盾获得75%伤害吸收量加成。
             * 
             * 护盾对冰元素伤害有250%的吸收效果，并会在形成时，为当前角色施加短暂的冰元素附着。
             * 
             * 猫爪伤害|每个{param1:F1P}
             * 护盾基础吸收量|{param2:F1P}最大生命值+{param3:I}
             * 持续时间|每个猫爪{param6:F1}秒
             * 点按冷却时间|{param4:F1}秒
             * 长按冷却时间|{param5:F1}秒
            */
            void 迪奥娜::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[6]{ 0.41920000314712524,0.07199999690055847,692.8065795898438,6,15,1.7999999523162842},
                        new const double[6]{ 0.4506399929523468,0.07739999890327454,762.0968627929688,6,15,1.899999976158142},
                        new const double[6]{ 0.48208001255989075,0.0828000009059906,837.1613159179688,6,15,2},
                        new const double[6]{ 0.5239999890327454,0.09000000357627869,918,6,15,2.0999999046325684},
                        new const double[6]{ 0.5554400086402893,0.09539999812841415,1004.6128540039062,6,15,2.200000047683716},
                        new const double[6]{ 0.5868800282478333,0.10080000013113022,1096.9998779296875,6,15,2.299999952316284},
                        new const double[6]{ 0.6287999749183655,0.1080000028014183,1195.1611328125,6,15,2.4000000953674316},
                        new const double[6]{ 0.6707199811935425,0.1151999980211258,1299.0965576171875,6,15,2.4000000953674316},
                        new const double[6]{ 0.7126399874687195,0.12240000069141388,1408.80615234375,6,15,2.4000000953674316},
                        new const double[6]{ 0.7545599937438965,0.12960000336170197,1524.2900390625,6,15,2.4000000953674316},
                        new const double[6]{ 0.7964800000190735,0.13680000603199005,1645.5479736328125,6,15,2.4000000953674316},
                        new const double[6]{ 0.8384000062942505,0.14399999380111694,1772.5802001953125,6,15,2.4000000953674316},
                        new const double[6]{ 0.8907999992370605,0.15299999713897705,1905.3865966796875,6,15,2.4000000953674316},
                        new const double[6]{ 0.9431999921798706,0.16200000047683716,2043.9671630859375,6,15,2.4000000953674316},
                        new const double[6]{ 0.9955999851226807,0.17100000381469727,2188.322021484375,6,15,2.4000000953674316}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };


            /*******最烈特调
             * 
             * 抛出特别调制的冰酿烈调，造成冰元素范围伤害，并产生冰气酒雾领域。
             * 
             * **冰气酒雾领域**
             * ·对其中的敌人持续造成冰元素伤害；
             * ·为其中的角色持续恢复生命值。
             * 
             * 技能伤害|{param1:P}
             * 领域持续伤害|{param2:F1P}
             * 持续治疗量|{param3:F2P}生命值上限+{param4:I}
             * 持续时间|{param7:F1}秒
             * 冷却时间|{param5:F1}秒
             * 元素能量|{param6:I}
            */
            void 迪奥娜::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[7]{ 0.800000011920929,0.5264000296592712,0.053360000252723694,513.1900634765625,20,80,12},
                        new const double[7]{ 0.8600000143051147,0.5658800005912781,0.05736200138926506,564.5161743164062,20,80,12},
                        new const double[7]{ 0.9200000166893005,0.6053599715232849,0.06136399880051613,620.1195068359375,20,80,12},
                        new const double[7]{ 1,0.6579999923706055,0.06669999659061432,680,20,80,12},
                        new const double[7]{ 1.059999942779541,0.6974800229072571,0.07070200145244598,744.1576538085938,20,80,12},
                        new const double[7]{ 1.1200000047683716,0.7369599938392639,0.07470399886369705,812.592529296875,20,80,12},
                        new const double[7]{ 1.2000000476837158,0.7896000146865845,0.08004000037908554,885.3045654296875,20,80,12},
                        new const double[7]{ 1.2799999713897705,0.8422399759292603,0.08537600189447403,962.2937622070312,20,80,12},
                        new const double[7]{ 1.3600000143051147,0.8948799967765808,0.09071200340986252,1043.5601806640625,20,80,12},
                        new const double[7]{ 1.440000057220459,0.9475200176239014,0.09604799747467041,1129.103759765625,20,80,12},
                        new const double[7]{ 1.5199999809265137,1.0001599788665771,0.1013839989900589,1218.9244384765625,20,80,12},
                        new const double[7]{ 1.600000023841858,1.0528000593185425,0.10672000050544739,1313.0223388671875,20,80,12},
                        new const double[7]{ 1.7000000476837158,1.1186000108718872,0.1133899986743927,1411.3974609375,20,80,12},
                        new const double[7]{ 1.7999999523162842,1.184399962425232,0.12005999684333801,1514.0498046875,20,80,12},
                        new const double[7]{ 1.899999976158142,1.2502000331878662,0.12672999501228333,1620.979248046875,20,80,12}                    
                };  
                const double* curData = SkillPrama[cmd & 0xFF];
                ////////下面是技能实现   
            };
        /*****迪奥娜
        
            ***1命***
            特调的余韵            
            ❤最烈特调❤的效果结束时，为迪奥娜恢复15点元素能量。
            
            ***2命***
            猫爪冰摇            
            ❤猫爪冻冻❤造成的伤害提高15%，护盾的伤害吸收量提高15%；此外，命中时，将为附近的当前其他场上角色生成一个伤害吸收量为❤猫爪冻冻❤50%的护盾，持续5秒。
            
            ***3命***
            还、还要续杯？            
            ❤最烈特调❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            「酒业杀手」            
            在❤最烈特调❤的领域内，迪奥娜的瞄准射击的所需的蓄力时间减少60%。
            
            ***5命***
            双份加冰            
            ❤猫爪冻冻❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            猫尾打烊之时            
            处在❤最烈特调❤领域内的角色，依据生命值获得如下效果：·生命值低于或等于50%时，受治疗加成提升30%；·生命值高于50%时，元素精通提升200。
            
        */
         
        