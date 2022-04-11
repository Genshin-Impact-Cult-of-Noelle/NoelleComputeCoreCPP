#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 埃洛伊 : public Advanced::Role
                {
                public:
                    ~埃洛伊();
                    埃洛伊(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        