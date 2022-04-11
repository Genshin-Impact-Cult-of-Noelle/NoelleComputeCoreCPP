#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 罗莎莉亚 : public Advanced::Role
                {
                public:
                    ~罗莎莉亚();
                    罗莎莉亚(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        