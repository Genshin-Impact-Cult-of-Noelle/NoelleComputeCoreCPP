#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 辛焱 : public Advanced::Role
                {
                public:
                    ~辛焱();
                    辛焱(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        