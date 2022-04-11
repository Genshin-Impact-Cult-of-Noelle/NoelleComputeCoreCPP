#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 可莉 : public Advanced::Role
                {
                public:
                    ~可莉();
                    可莉(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        