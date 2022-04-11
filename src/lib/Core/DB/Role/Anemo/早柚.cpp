﻿#pragma once
        #include "早柚.h"
        using namespace DB::RoleConstruct;
        using namespace Atom;
        using namespace Atom::Enum;
        using namespace Advanced;
        using namespace Professional;
        //TODO:AUTO早柚.cpp
        const double HP =  11853.657119952724;
        const double ATK =  244.256775675296;
        const double DEF =  744.6309889846998;
        //元素精通
        const double OTHER = 96;
        
        早柚::~早柚() {
        }
        早柚::早柚(u32* frameCur):Role(frameCur) {
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
             * 
             * **普通攻击**
             * 进行至多四段的连续挥砍。
             * 
             * **重击**
             * 持续消耗体力，旋转大剑攻击周围的敌人。
             * 停止旋转时，会进行一次格外有力的挥砍。
             * 
             * **下落攻击**
             * 从空中下坠冲击地面，攻击下落路径上的敌人，并在落地时造成范围伤害。
             * 
             * 一段伤害|{param1:F1P}
             * 二段伤害|{param2:F1P}
             * 三段伤害|{param3:F1P}+{param4:F1P}
             * 四段伤害|{param5:F1P}
             * 重击循环伤害|{param6:F1P}
             * 重击终结伤害|{param7:P}
             * 重击体力消耗|每秒{param8:F1}点
             * 最大持续时间|{param9:F1}秒
             * 下坠期间伤害|{param10:F1P}
             * 低空/高空坠地冲击伤害|{param11:P}/{param12:P}
            */
            void 早柚::A(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[12]{ 0.7224000096321106,0.7138000130653381,0.4343000054359436,0.4343000054359436,0.9812600016593933,0.6254550218582153,1.1309000253677368,40,5,0.7458779811859131,1.4914400577545166,1.862889051437378},
                        new const double[12]{ 0.7811999917030334,0.7718999981880188,0.469650000333786,0.469650000333786,1.0611300468444824,0.676364004611969,1.2229499816894531,40,5,0.8065890073776245,1.6128360033035278,2.0145199298858643},
                        new const double[12]{ 0.8399999737739563,0.8299999833106995,0.5049999952316284,0.5049999952316284,1.1410000324249268,0.7272729873657227,1.315000057220459,40,5,0.8672999739646912,1.734233021736145,2.1661500930786133},
                        new const double[12]{ 0.9240000247955322,0.9129999876022339,0.5554999709129333,0.5554999709129333,1.2551000118255615,0.800000011920929,1.4464999437332153,40,5,0.9540299773216248,1.907655954360962,2.382765054702759},
                        new const double[12]{ 0.9828000068664551,0.9710999727249146,0.5908499956130981,0.5908499956130981,1.3349699974060059,0.8509089946746826,1.5385500192642212,40,5,1.0147409439086914,2.0290520191192627,2.534395933151245},
                        new const double[12]{ 1.0499999523162842,1.037500023841858,0.6312500238418579,0.6312500238418579,1.4262499809265137,0.9090909957885742,1.6437499523162842,40,5,1.08412504196167,2.1677908897399902,2.707688093185425},
                        new const double[12]{ 1.1424000263214111,1.1288000345230103,0.6868000030517578,0.6868000030517578,1.551759958267212,0.9890909790992737,1.7884000539779663,40,5,1.179527997970581,2.358556032180786,2.9459640979766846},
                        new const double[12]{ 1.2347999811172485,1.2201000452041626,0.7423499822616577,0.7423499822616577,1.6772700548171997,1.0690909624099731,1.9330500364303589,40,5,1.2749309539794922,2.5493218898773193,3.1842410564422607},
                        new const double[12]{ 1.3272000551223755,1.311400055885315,0.7979000210762024,0.7979000210762024,1.802780032157898,1.1490910053253174,2.077699899673462,40,5,1.3703340291976929,2.7400870323181152,3.4225170612335205},
                        new const double[12]{ 1.4279999732971191,1.4110000133514404,0.8585000038146973,0.8585000038146973,1.9397000074386597,1.2363640069961548,2.2355000972747803,40,5,1.474410057067871,2.948194980621338,3.682455062866211},
                        new const double[12]{ 1.5434999465942383,1.5251250267028809,0.9279369711875916,0.9279369711875916,2.096587896347046,1.3363640308380127,2.4163129329681396,40,5,1.5784859657287598,3.1563029289245605,3.9423930644989014},
                        new const double[12]{ 1.6793279647827148,1.659335970878601,1.0095959901809692,1.0095959901809692,2.2810869216918945,1.4539639949798584,2.6289479732513428,40,5,1.682561993598938,3.3644111156463623,4.202331066131592},
                        new const double[12]{ 1.8151559829711914,1.7935470342636108,1.0912549495697021,1.0912549495697021,2.4655869007110596,1.571563959121704,2.8415839672088623,40,5,1.7866380214691162,3.572519063949585,4.462268829345703},
                        new const double[12]{ 1.950984001159668,1.927757978439331,1.1729129552841187,1.1729129552841187,2.6500871181488037,1.6891640424728394,3.0542190074920654,40,5,1.8907140493392944,3.7806270122528076,4.722207069396973},
                        new const double[12]{ 2.0991599559783936,2.0741701126098633,1.2619949579238892,1.2619949579238892,2.8513588905334473,1.8174550533294678,3.2861850261688232,40,5,1.994789958000183,3.9887349605560303,4.982144832611084}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******呜呼流·风隐急进
             * 
             * 忍法·呜呼流的独创奥义！以风驰电掣之势席卷战场的绝技！
             * 蜷缩成高速滚动的风风轮，冲撞触及的敌人造成风元素伤害，并在结束时使出风风轮舞踢，造成风元素范围伤害。
             * 
             * **点按**
             * 进入风风轮状态，向前滚动一小段距离，并使出风风轮舞踢。
             * 
             * **长按**
             * 以风风轮之姿持续滚动，并在该状态下提高早柚的抗打断能力。
             * 期间，早柚可以控制滚动的方向，并能通过再次施放技能，提前结束状态使出相比点按更为强大的风风轮舞踢。
             * 该技能通过长按施放时，能发生元素转化。
             * 
             * 持续至多10秒。效果结束时，技能将进入冷却。在风风轮状态下持续的时间越长，冷却时间越长。
             * 
             * **元素转化**
             * 若早柚在风风轮状态下，接触了水元素/火元素/冰元素/雷元素，则会获得对应元素属性，使风风轮与风风轮舞踢额外造成该元素的附加伤害。
             * 元素转化在技能持续期间仅会发生一次。
             * 
             * 风风轮伤害|{param1:F1P}
             * 风风轮舞踢点按伤害|{param3:F1P}
             * 风风轮舞踢长按伤害|{param4:F1P}
             * 风风轮附带元素伤害|{param2:F1P}
             * 风风轮舞踢长按附带元素伤害|{param5:F1P}
             * 长按最大持续时间|{param6:F1}秒
             * 冷却时间|{param7:F1}到{param8:F1}秒
            */
            void 早柚::E(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[8]{ 0.36000001430511475,0.1679999977350235,1.5839999914169312,2.1760001182556152,0.7616000175476074,10,6,11},
                        new const double[8]{ 0.3869999945163727,0.18060000240802765,1.7028000354766846,2.339200019836426,0.8187199831008911,10,6,11},
                        new const double[8]{ 0.414000004529953,0.1932000070810318,1.8215999603271484,2.5023999214172363,0.8758400082588196,10,6,11},
                        new const double[8]{ 0.44999998807907104,0.20999999344348907,1.9800000190734863,2.7200000286102295,0.9520000219345093,10,6,11},
                        new const double[8]{ 0.47699999809265137,0.22259999811649323,2.09879994392395,2.88319993019104,1.009119987487793,10,6,11},
                        new const double[8]{ 0.5040000081062317,0.23520000278949738,2.217600107192993,3.0464000701904297,1.0662399530410767,10,6,11},
                        new const double[8]{ 0.5400000214576721,0.25200000405311584,2.375999927520752,3.2639999389648438,1.1424000263214111,10,6,11},
                        new const double[8]{ 0.5759999752044678,0.2687999904155731,2.53439998626709,3.481600046157837,1.218559980392456,10,6,11},
                        new const double[8]{ 0.6119999885559082,0.2856000065803528,2.6928000450134277,3.699199914932251,1.2947200536727905,10,6,11},
                        new const double[8]{ 0.6480000019073486,0.30239999294281006,2.8512001037597656,3.916800022125244,1.3708800077438354,10,6,11},
                        new const double[8]{ 0.6840000152587891,0.3192000091075897,3.0095999240875244,4.134399890899658,1.4470399618148804,10,6,11},
                        new const double[8]{ 0.7200000286102295,0.335999995470047,3.1679999828338623,4.3520002365112305,1.5232000350952148,10,6,11},
                        new const double[8]{ 0.7649999856948853,0.3569999933242798,3.365999937057495,4.624000072479248,1.618399977684021,10,6,11},
                        new const double[8]{ 0.8100000023841858,0.3779999911785126,3.563999891281128,4.895999908447266,1.7136000394821167,10,6,11},
                        new const double[8]{ 0.8550000190734863,0.39899998903274536,3.76200008392334,5.168000221252441,1.8087999820709229,10,6,11}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };


            /*******呜呼流·影貉缭乱
             * 
             * 忍法·呜呼流的另一个独创奥义！能创造出替早柚干活的帮手！
             * 对身边的敌人造成风元素伤害，为队伍中附近的所有角色恢复生命值，回复量受益于早柚的攻击力，并召唤出「不倒貉貉」。
             * 
             * **不倒貉貉**
             * 周期性地根据附近的状况，采取其中一种行动：
             * ·附近的角色如果生命值均高于70%，不倒貉貉会攻击附近的一名敌人，造成风元素伤害；
             * ·附近场上如果存在生命值低于或等于70%的角色，会为附近场上生命值百分比最低的角色恢复生命值，回复量受益于早柚的攻击力。若附近不存在敌人，即使角色的生命值均高于70%，也会为角色恢复生命值。
             * 
             * 技能发动伤害|{param1:P}
             * 技能发动治疗量|{param3:F1P}攻击力+{param2:I}
             * 不倒貉貉伤害|{param4:P}
             * 不倒貉貉治疗量|{param6:F1P}攻击力+{param5:I}
             * 持续时间|{param7:F1}秒
             * 冷却时间|{param8:F1}秒
             * 元素能量|{param9:I}
            */
            void 早柚::Q(Role* role, u32 cmd) {
                const static double** SkillPrama = new const double* [15]{
                        new const double[9]{ 1.1679999828338623,577.3388061523438,0.9215999841690063,0.5199999809265137,500.36029052734375,0.7987200021743774,12,20,80},
                        new const double[9]{ 1.2555999755859375,635.0806884765625,0.9907199740409851,0.5590000152587891,550.4032592773438,0.8586239814758301,12,20,80},
                        new const double[9]{ 1.3431999683380127,697.6344604492188,1.0598399639129639,0.5979999899864197,604.6165161132812,0.9185280203819275,12,20,80},
                        new const double[9]{ 1.4600000381469727,765,1.1519999504089355,0.6499999761581421,663,0.9983999729156494,12,20,80},
                        new const double[9]{ 1.5476000308990479,837.1773681640625,1.221119999885559,0.6890000104904175,725.5537109375,1.058303952217102,12,20,80},
                        new const double[9]{ 1.635200023651123,914.1665649414062,1.2902400493621826,0.7279999852180481,792.2777099609375,1.1182080507278442,12,20,80},
                        new const double[9]{ 1.7519999742507935,995.9676513671875,1.3824000358581543,0.7799999713897705,863.1719360351562,1.1980799436569214,12,20,80},
                        new const double[9]{ 1.8688000440597534,1082.5804443359375,1.474560022354126,0.8320000171661377,938.2363891601562,1.277951955795288,12,20,80},
                        new const double[9]{ 1.9855999946594238,1174.005126953125,1.5667200088500977,0.8840000033378601,1017.4711303710938,1.3578239679336548,12,20,80},
                        new const double[9]{ 2.102400064468384,1270.24169921875,1.6588799953460693,0.9359999895095825,1100.8760986328125,1.4376959800720215,12,20,80},
                        new const double[9]{ 2.2191998958587646,1371.2900390625,1.751039981842041,0.9879999756813049,1188.4512939453125,1.5175679922103882,12,20,80},
                        new const double[9]{ 2.3359999656677246,1477.150146484375,1.8431999683380127,1.0399999618530273,1280.19677734375,1.5974400043487549,12,20,80},
                        new const double[9]{ 2.4820001125335693,1587.8221435546875,1.958400011062622,1.1050000190734863,1376.112548828125,1.6972800493240356,12,20,80},
                        new const double[9]{ 2.628000020980835,1703.305908203125,2.0736000537872314,1.1699999570846558,1476.198486328125,1.7971199750900269,12,20,80},
                        new const double[9]{ 2.7739999294281006,1823.6015625,2.188800096511841,1.2350000143051147,1580.4547119140625,1.8969600200653076,12,20,80}                    
                };  
                const double* curData = SkillPrama[cmd && 0xFF];
                ////////下面是技能实现   
            };
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
         
        