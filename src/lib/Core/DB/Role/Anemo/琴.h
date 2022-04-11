#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 琴 : public Advanced::Role
                {
                public:
                    ~琴();
                    琴(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        