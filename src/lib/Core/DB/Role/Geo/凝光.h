#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 凝光 : public Advanced::Role
                {
                public:
                    ~凝光();
                    凝光(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        