#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 香菱 : public Advanced::Role
                {
                public:
                    ~香菱();
                    香菱(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        