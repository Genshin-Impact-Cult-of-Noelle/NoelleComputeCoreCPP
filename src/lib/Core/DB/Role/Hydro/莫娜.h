#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 莫娜 : public Advanced::Role
                {
                public:
                    ~莫娜();
                    莫娜(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        