#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 五郎 : public Advanced::Role
                {
                public:
                    ~五郎();
                    五郎(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        