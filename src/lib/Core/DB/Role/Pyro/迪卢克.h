#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 迪卢克 : public Advanced::Role
                {
                public:
                    ~迪卢克();
                    迪卢克(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        