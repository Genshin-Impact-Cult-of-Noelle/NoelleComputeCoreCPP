#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 钟离 : public Advanced::Role
                {
                public:
                    ~钟离();
                    钟离(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        