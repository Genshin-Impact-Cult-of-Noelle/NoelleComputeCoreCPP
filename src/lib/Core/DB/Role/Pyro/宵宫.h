#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 宵宫 : public Advanced::Role
                {
                public:
                    ~宵宫();
                    宵宫(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        