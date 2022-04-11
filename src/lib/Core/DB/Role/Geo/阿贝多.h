#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 阿贝多 : public Advanced::Role
                {
                public:
                    ~阿贝多();
                    阿贝多(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        