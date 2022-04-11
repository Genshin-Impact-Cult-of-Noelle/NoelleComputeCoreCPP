#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 迪奥娜 : public Advanced::Role
                {
                public:
                    ~迪奥娜();
                    迪奥娜(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        