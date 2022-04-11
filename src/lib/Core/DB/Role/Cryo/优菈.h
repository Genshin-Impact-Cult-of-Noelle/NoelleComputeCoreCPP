#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 优菈 : public Advanced::Role
                {
                public:
                    ~优菈();
                    优菈(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        