#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 凯亚 : public Advanced::Role
                {
                public:
                    ~凯亚();
                    凯亚(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        