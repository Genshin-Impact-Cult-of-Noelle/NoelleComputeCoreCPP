#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 烟绯 : public Advanced::Role
                {
                public:
                    ~烟绯();
                    烟绯(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        