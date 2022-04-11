#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 重云 : public Advanced::Role
                {
                public:
                    ~重云();
                    重云(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        