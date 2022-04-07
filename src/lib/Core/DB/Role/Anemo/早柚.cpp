﻿
        #include "早柚.h"
        using namespace Role;
        //TODO:AUTO早柚.cpp
        const double HP =  11853.657119952724;
        const double ATK =  244.256775675296;
        const double DEF =  744.6309889846998;
        //元素精通
        const double OTHER = 96;
        
        namespace Anemo{
        早柚::~早柚() {
        }
        早柚::早柚() {
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
            this->rawCharacter = new Character(baseData, CharacterGender::Female, CharacterGroup::Tivat, ElementType::Anemo, WeaponType::Claymore);
            delete baseData;
        };        

        /*
        
        ****1:更加合适的人选
        ****************
        
            早柚在场上触发扩散反应时，为队伍中自己的角色以及附近的友方角色恢复300点生命值。除此之外，早柚的每点元素精通将额外恢复1.2点生命值。
            该效果每2秒只能触发一次。 

        ****************
        

        ****2:早柚不用工作啦
        ****************
        
            ❤呜呼流·影貉缭乱❤的不倒貉貉获得如下效果：
            ·为角色恢复生命值时，将为该角色身边的其他场上角色恢复相当于回复量20%的生命值；
            ·攻击敌人时，扩大造成伤害的范围。 

        ****************
        

        ****3:呜呼流·屏息秘传
        ****************
        
            早柚在队伍中时，队伍中自己的角色接近晶蝶等部分生物时，不会惊动它们。
            有效对象可参考图鉴中「生物志 / 野生动物」的「其他」分类。 

        ****************
        
        */
        
            /*******普通攻击·忍刀·终末番
            一段伤害|{param1:F1P}
            二段伤害|{param2:F1P}
            三段伤害|{param3:F1P}+{param4:F1P}
            四段伤害|{param5:F1P}
            重击循环伤害|{param6:F1P}
            重击终结伤害|{param7:P}
            重击体力消耗|每秒{param8:F1}点
            最大持续时间|{param9:F1}秒
            下坠期间伤害|{param10:F1P}
            低空/高空坠地冲击伤害|{param11:P}/{param12:P}
            */

            
                    const static double* Skill_1_1 = new double[15]{ 0.7224000096321106,0.7811999917030334,0.8399999737739563,0.9240000247955322,0.9828000068664551,1.0499999523162842,1.1424000263214111,1.2347999811172485,1.3272000551223755,1.4279999732971191,1.5434999465942383,1.6793279647827148,1.8151559829711914,1.950984001159668,2.0991599559783936 };
                    const static double* Skill_1_2 = new double[15]{ 0.7138000130653381,0.7718999981880188,0.8299999833106995,0.9129999876022339,0.9710999727249146,1.037500023841858,1.1288000345230103,1.2201000452041626,1.311400055885315,1.4110000133514404,1.5251250267028809,1.659335970878601,1.7935470342636108,1.927757978439331,2.0741701126098633 };
                    const static double* Skill_1_3 = new double[15]{ 0.4343000054359436,0.469650000333786,0.5049999952316284,0.5554999709129333,0.5908499956130981,0.6312500238418579,0.6868000030517578,0.7423499822616577,0.7979000210762024,0.8585000038146973,0.9279369711875916,1.0095959901809692,1.0912549495697021,1.1729129552841187,1.2619949579238892 };
                    const static double* Skill_1_4 = new double[15]{ 0.4343000054359436,0.469650000333786,0.5049999952316284,0.5554999709129333,0.5908499956130981,0.6312500238418579,0.6868000030517578,0.7423499822616577,0.7979000210762024,0.8585000038146973,0.9279369711875916,1.0095959901809692,1.0912549495697021,1.1729129552841187,1.2619949579238892 };
                    const static double* Skill_1_5 = new double[15]{ 0.9812600016593933,1.0611300468444824,1.1410000324249268,1.2551000118255615,1.3349699974060059,1.4262499809265137,1.551759958267212,1.6772700548171997,1.802780032157898,1.9397000074386597,2.096587896347046,2.2810869216918945,2.4655869007110596,2.6500871181488037,2.8513588905334473 };
                    const static double* Skill_1_6 = new double[15]{ 0.6254550218582153,0.676364004611969,0.7272729873657227,0.800000011920929,0.8509089946746826,0.9090909957885742,0.9890909790992737,1.0690909624099731,1.1490910053253174,1.2363640069961548,1.3363640308380127,1.4539639949798584,1.571563959121704,1.6891640424728394,1.8174550533294678 };
                    const static double* Skill_1_7 = new double[15]{ 1.1309000253677368,1.2229499816894531,1.315000057220459,1.4464999437332153,1.5385500192642212,1.6437499523162842,1.7884000539779663,1.9330500364303589,2.077699899673462,2.2355000972747803,2.4163129329681396,2.6289479732513428,2.8415839672088623,3.0542190074920654,3.2861850261688232 };
                    const static double* Skill_1_8 = new double[15]{ 40,40,40,40,40,40,40,40,40,40,40,40,40,40,40 };
                    const static double* Skill_1_9 = new double[15]{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 };
                    const static double* Skill_1_10 = new double[15]{ 0.7458779811859131,0.8065890073776245,0.8672999739646912,0.9540299773216248,1.0147409439086914,1.08412504196167,1.179527997970581,1.2749309539794922,1.3703340291976929,1.474410057067871,1.5784859657287598,1.682561993598938,1.7866380214691162,1.8907140493392944,1.994789958000183 };
                    const static double* Skill_1_11 = new double[15]{ 1.4914400577545166,1.6128360033035278,1.734233021736145,1.907655954360962,2.0290520191192627,2.1677908897399902,2.358556032180786,2.5493218898773193,2.7400870323181152,2.948194980621338,3.1563029289245605,3.3644111156463623,3.572519063949585,3.7806270122528076,3.9887349605560303 };
                    const static double* Skill_1_12 = new double[15]{ 1.862889051437378,2.0145199298858643,2.1661500930786133,2.382765054702759,2.534395933151245,2.707688093185425,2.9459640979766846,3.1842410564422607,3.4225170612335205,3.682455062866211,3.9423930644989014,4.202331066131592,4.462268829345703,4.722207069396973,4.982144832611084 };

            /*******呜呼流·风隐急进
            风风轮伤害|{param1:F1P}
            风风轮舞踢点按伤害|{param3:F1P}
            风风轮舞踢长按伤害|{param4:F1P}
            风风轮附带元素伤害|{param2:F1P}
            风风轮舞踢长按附带元素伤害|{param5:F1P}
            长按最大持续时间|{param6:F1}秒
            冷却时间|{param7:F1}到{param8:F1}秒
            */

            
                    const static double* Skill_2_1 = new double[15]{ 0.36000001430511475,0.3869999945163727,0.414000004529953,0.44999998807907104,0.47699999809265137,0.5040000081062317,0.5400000214576721,0.5759999752044678,0.6119999885559082,0.6480000019073486,0.6840000152587891,0.7200000286102295,0.7649999856948853,0.8100000023841858,0.8550000190734863 };
                    const static double* Skill_2_2 = new double[15]{ 0.1679999977350235,0.18060000240802765,0.1932000070810318,0.20999999344348907,0.22259999811649323,0.23520000278949738,0.25200000405311584,0.2687999904155731,0.2856000065803528,0.30239999294281006,0.3192000091075897,0.335999995470047,0.3569999933242798,0.3779999911785126,0.39899998903274536 };
                    const static double* Skill_2_3 = new double[15]{ 1.5839999914169312,1.7028000354766846,1.8215999603271484,1.9800000190734863,2.09879994392395,2.217600107192993,2.375999927520752,2.53439998626709,2.6928000450134277,2.8512001037597656,3.0095999240875244,3.1679999828338623,3.365999937057495,3.563999891281128,3.76200008392334 };
                    const static double* Skill_2_4 = new double[15]{ 2.1760001182556152,2.339200019836426,2.5023999214172363,2.7200000286102295,2.88319993019104,3.0464000701904297,3.2639999389648438,3.481600046157837,3.699199914932251,3.916800022125244,4.134399890899658,4.3520002365112305,4.624000072479248,4.895999908447266,5.168000221252441 };
                    const static double* Skill_2_5 = new double[15]{ 0.7616000175476074,0.8187199831008911,0.8758400082588196,0.9520000219345093,1.009119987487793,1.0662399530410767,1.1424000263214111,1.218559980392456,1.2947200536727905,1.3708800077438354,1.4470399618148804,1.5232000350952148,1.618399977684021,1.7136000394821167,1.8087999820709229 };
                    const static double* Skill_2_6 = new double[15]{ 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
                    const static double* Skill_2_7 = new double[15]{ 6,6,6,6,6,6,6,6,6,6,6,6,6,6,6 };
                    const static double* Skill_2_8 = new double[15]{ 11,11,11,11,11,11,11,11,11,11,11,11,11,11,11 };

            /*******呜呼流·影貉缭乱
            技能发动伤害|{param1:P}
            技能发动治疗量|{param3:F1P}攻击力+{param2:I}
            不倒貉貉伤害|{param4:P}
            不倒貉貉治疗量|{param6:F1P}攻击力+{param5:I}
            持续时间|{param7:F1}秒
            冷却时间|{param8:F1}秒
            元素能量|{param9:I}
            */

            
                    const static double* Skill_3_1 = new double[15]{ 1.1679999828338623,1.2555999755859375,1.3431999683380127,1.4600000381469727,1.5476000308990479,1.635200023651123,1.7519999742507935,1.8688000440597534,1.9855999946594238,2.102400064468384,2.2191998958587646,2.3359999656677246,2.4820001125335693,2.628000020980835,2.7739999294281006 };
                    const static double* Skill_3_2 = new double[15]{ 577.3388061523438,635.0806884765625,697.6344604492188,765,837.1773681640625,914.1665649414062,995.9676513671875,1082.5804443359375,1174.005126953125,1270.24169921875,1371.2900390625,1477.150146484375,1587.8221435546875,1703.305908203125,1823.6015625 };
                    const static double* Skill_3_3 = new double[15]{ 0.9215999841690063,0.9907199740409851,1.0598399639129639,1.1519999504089355,1.221119999885559,1.2902400493621826,1.3824000358581543,1.474560022354126,1.5667200088500977,1.6588799953460693,1.751039981842041,1.8431999683380127,1.958400011062622,2.0736000537872314,2.188800096511841 };
                    const static double* Skill_3_4 = new double[15]{ 0.5199999809265137,0.5590000152587891,0.5979999899864197,0.6499999761581421,0.6890000104904175,0.7279999852180481,0.7799999713897705,0.8320000171661377,0.8840000033378601,0.9359999895095825,0.9879999756813049,1.0399999618530273,1.1050000190734863,1.1699999570846558,1.2350000143051147 };
                    const static double* Skill_3_5 = new double[15]{ 500.36029052734375,550.4032592773438,604.6165161132812,663,725.5537109375,792.2777099609375,863.1719360351562,938.2363891601562,1017.4711303710938,1100.8760986328125,1188.4512939453125,1280.19677734375,1376.112548828125,1476.198486328125,1580.4547119140625 };
                    const static double* Skill_3_6 = new double[15]{ 0.7987200021743774,0.8586239814758301,0.9185280203819275,0.9983999729156494,1.058303952217102,1.1182080507278442,1.1980799436569214,1.277951955795288,1.3578239679336548,1.4376959800720215,1.5175679922103882,1.5974400043487549,1.6972800493240356,1.7971199750900269,1.8969600200653076 };
                    const static double* Skill_3_7 = new double[15]{ 12,12,12,12,12,12,12,12,12,12,12,12,12,12,12 };
                    const static double* Skill_3_8 = new double[15]{ 20,20,20,20,20,20,20,20,20,20,20,20,20,20,20 };
                    const static double* Skill_3_9 = new double[15]{ 80,80,80,80,80,80,80,80,80,80,80,80,80,80,80 };
        /*****早柚
        
            ***1命***
            一心二用之术            
            ❤呜呼流·影貉缭乱❤的不倒貉貉的行动将忽视生命值限制，能同时攻击附近的敌人并为角色恢复生命值。
            
            ***2命***
            理清逃跑路线            
            ❤呜呼流·风隐急进❤获得如下效果：·点按施放时，风风轮舞踢造成的伤害提高3.3%；·处于长按施放后的风风轮状态下时，每0.5秒，就会使这次施展的风风轮舞踢造成的伤害提高3.3%。通过这种方式，风风轮舞踢造成的伤害至多可以提高66%。
            
            ***3命***
            都交给分身吧            
            ❤呜呼流·影貉缭乱❤的技能等级提高3级。至多提升至15级。
            
            ***4命***
            偷懒的新方法            
            早柚在场上触发扩散反应时，将恢复1.2点元素能量。该效果每2秒只能触发一次。
            
            ***5命***
            快是第一奥义            
            ❤呜呼流·风隐急进❤的技能等级提高3级。至多提升至15级。
            
            ***6命***
            呼呼大睡时间            
            早柚自己通过❤呜呼流·影貉缭乱❤召唤的不倒貉貉的攻击与回复量，受益于早柚的元素精通。早柚的每点元素精通，能产生如下效果：·使不倒貉貉的攻击额外造成0.2%攻击力的伤害。通过这种方式至多额外造成400%攻击力的伤害；·使不倒貉貉的回复量提高3点。通过这种方式，至多提高6000点回复量。
            
        */
        void 早柚::A(Role* role, u8* cmd) {
        };
        void 早柚::Q(Role* role, u8* cmd) {        
        };
        void 早柚::E(Role* role, u8* cmd) {        
        };    
        }
        