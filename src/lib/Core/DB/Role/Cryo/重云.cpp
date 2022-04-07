﻿
        #include "重云.h"
        using namespace Role;
        //TODO:AUTO重云.cpp
        const double HP =  10983.664287271677;
        const double ATK =  223.01705909465636;
        const double DEF =  648.3954482758236;
        //攻击力
        const double OTHER = 0.23999999463558197;
        
        namespace Cryo{
        重云::~重云() {
        }
        重云::重云() {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Male, CharacterGroup::Tivat, ElementType::Cryo, WeaponType::Claymore);
            delete baseData;
        };        

        /*
        
        ****1:吐纳真定
        ****************
        
            处在❤灵刃·重华叠霜❤领域内的单手剑、双手剑、长柄武器角色，普通攻击的攻击速度提升8%。 

        ****************
        

        ****2:追冰剑诀
        ****************
        
            ❤灵刃·重华叠霜❤领域消失时，会唤出一柄灵刃自动攻击附近的敌人，造成相当于灵刃·重华叠霜技能伤害100%的冰元素范围伤害。被击中的敌人冰元素抗性降低10%，持续8秒。 

        ****************
        

        ****3:云游山海
        ****************
        
            在璃月执行探索派遣任务时，消耗的时间缩短25%。 

        ****************
        
        */
        
            /*******普通攻击·灭邪四式
            一段伤害|{param1:F1P}
            二段伤害|{param2:F1P}
            三段伤害|{param3:F1P}
            四段伤害|{param4:P}
            重击循环伤害|{param5:F1P}
            重击终结伤害|{param6:P}
            重击体力消耗|每秒{param7:F1}点
            最大持续时间|{param8:F1}秒
            下坠期间伤害|{param9:F1P}
            低空/高空坠地冲击伤害|{param10:P}/{param11:P}
            */

            
                    const static double* Skill_1_1 = new double[15]{ 0.7000399827957153,0.7570199966430664,0.8140000104904175,0.8953999876976013,0.9523800015449524,1.0175000429153442,1.1070400476455688,1.1965800523757935,1.286120057106018,1.3838000297546387,1.4814800024032593,1.5791599750518799,1.6768399477005005,1.7745200395584106,1.8722000122070312 };
                    const static double* Skill_1_2 = new double[15]{ 0.6312400102615356,0.6826199889183044,0.734000027179718,0.8073999881744385,0.858780026435852,0.9175000190734863,0.9982399940490723,1.0789799690246582,1.1597199440002441,1.2477999925613403,1.3358800411224365,1.4239599704742432,1.5120400190353394,1.600119948387146,1.6881999969482422 };
                    const static double* Skill_1_3 = new double[15]{ 0.8032400012016296,0.868619978427887,0.9340000152587891,1.027400016784668,1.0927799940109253,1.1675000190734863,1.2702399492263794,1.372979998588562,1.4757200479507446,1.5878000259399414,1.6998800039291382,1.811959981918335,1.9240399599075317,2.0361199378967285,2.148200035095215 };
                    const static double* Skill_1_4 = new double[15]{ 1.012220025062561,1.0946099758148193,1.1770000457763672,1.294700026512146,1.3770899772644043,1.471250057220459,1.6007200479507446,1.7301900386810303,1.859660029411316,2.0009000301361084,2.1421399116516113,2.2833800315856934,2.4246199131011963,2.5658600330352783,2.7070999145507812 };
                    const static double* Skill_1_5 = new double[15]{ 0.5628529787063599,0.6086660027503967,0.65447998046875,0.7199280261993408,0.7657420039176941,0.8180999755859375,0.8900930285453796,0.962086021900177,1.0340780019760132,1.112615942955017,1.1911540031433105,1.269690990447998,1.3482290506362915,1.426766037940979,1.505303978919983 };
                    const static double* Skill_1_6 = new double[15]{ 1.0178099870681763,1.10065495967865,1.183500051498413,1.3018499612808228,1.384695053100586,1.4793750047683716,1.6095600128173828,1.739745020866394,1.8699300289154053,2.0119500160217285,2.1539700031280518,2.295989990234375,2.4380099773406982,2.5800299644470215,2.7220499515533447 };
                    const static double* Skill_1_7 = new double[15]{ 40,40,40,40,40,40,40,40,40,40,40,40,40,40,40 };
                    const static double* Skill_1_8 = new double[15]{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 };
                    const static double* Skill_1_9 = new double[15]{ 0.7458779811859131,0.8065890073776245,0.8672999739646912,0.9540299773216248,1.0147409439086914,1.08412504196167,1.179527997970581,1.2749309539794922,1.3703340291976929,1.474410057067871,1.5784859657287598,1.682561993598938,1.7866380214691162,1.8907140493392944,1.994789958000183 };
                    const static double* Skill_1_10 = new double[15]{ 1.4914400577545166,1.6128360033035278,1.734233021736145,1.907655954360962,2.0290520191192627,2.1677908897399902,2.358556032180786,2.5493218898773193,2.7400870323181152,2.948194980621338,3.1563029289245605,3.3644111156463623,3.572519063949585,3.7806270122528076,3.9887349605560303 };
                    const static double* Skill_1_11 = new double[15]{ 1.862889051437378,2.0145199298858643,2.1661500930786133,2.382765054702759,2.534395933151245,2.707688093185425,2.9459640979766846,3.1842410564422607,3.4225170612335205,3.682455062866211,3.9423930644989014,4.202331066131592,4.462268829345703,4.722207069396973,4.982144832611084 };

            /*******灵刃·重华叠霜
            技能伤害|{param1:P}
            附魔持续时间|{param2:F1}秒
            领域持续时间|{param4:F1}秒
            冷却时间|{param3:F1}秒
            */

            
                    const static double* Skill_2_1 = new double[15]{ 1.7203999757766724,1.849429965019226,1.9784599542617798,2.1505000591278076,2.2795300483703613,2.408560037612915,2.5806000232696533,2.7526400089263916,2.92467999458313,3.096719980239868,3.2687599658966064,3.4407999515533447,3.6558499336242676,3.8708999156951904,4.085949897766113 };
                    const static double* Skill_2_2 = new double[15]{ 2,2.0999999046325684,2.200000047683716,2.299999952316284,2.4000000953674316,2.5,2.5999999046325684,2.700000047683716,2.799999952316284,2.9000000953674316,3,3,3,3,3 };
                    const static double* Skill_2_3 = new double[15]{ 15,15,15,15,15,15,15,15,15,15,15,15,15,15,15 };
                    const static double* Skill_2_4 = new double[15]{ 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };

            /*******灵刃·云开星落
            技能伤害|{param1:P}
            冷却时间|{param2:F1}秒
            元素能量|{param3:I}
            */

            
                    const static double* Skill_3_1 = new double[15]{ 1.4240000247955322,1.5307999849319458,1.6375999450683594,1.7799999713897705,1.8868000507354736,1.9936000108718872,2.135999917984009,2.27839994430542,2.420799970626831,2.563199996948242,2.7056000232696533,2.8480000495910645,3.0260000228881836,3.2039999961853027,3.381999969482422 };
                    const static double* Skill_3_2 = new double[15]{ 12,12,12,12,12,12,12,12,12,12,12,12,12,12,12 };
                    const static double* Skill_3_3 = new double[15]{ 40,40,40,40,40,40,40,40,40,40,40,40,40,40,40 };
        /*****重云
        
            ***1命***
            释凌咏冰            
            普通攻击的最后一击会向前方释放三道冰之刃，每道冰之刃对沿途的敌人造成重云50%攻击力的冰元素伤害。
            
            ***2命***
            周天运转            
            在❤灵刃·重华叠霜❤领域内施放的元素战技与元素爆发的冷却时间减少15%。
            
            ***3命***
            云尽光生            
            ❤灵刃·云开星落❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            浮云霜天            
            重云的所有攻击命中受到冰元素影响的敌人时，自身将恢复1点元素能量。该效果每2秒最多触发一次。
            
            ***5命***
            真道正理            
            ❤灵刃·重华叠霜❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            四灵捧圣            
            ❤灵刃·云开星落❤对生命值百分比低于重云的敌人造成伤害时，伤害提升15%；此外，施放时，会召唤一柄额外的灵刃。
            
        */
        void 重云::A(Role* role, u8* cmd) {
        };
        void 重云::Q(Role* role, u8* cmd) {        
        };
        void 重云::E(Role* role, u8* cmd) {        
        };    
        }
        