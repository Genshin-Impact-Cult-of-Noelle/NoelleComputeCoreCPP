#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 胡桃 : public Advanced::Role
                {
                public:
                    ~胡桃();
                    胡桃(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        