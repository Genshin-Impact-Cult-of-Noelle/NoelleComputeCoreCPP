#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 早柚 : public Advanced::Role
                {
                public:
                    ~早柚();
                    早柚(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        