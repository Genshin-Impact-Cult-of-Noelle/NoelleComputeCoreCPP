#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 温迪 : public Advanced::Role
                {
                public:
                    ~温迪();
                    温迪(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        