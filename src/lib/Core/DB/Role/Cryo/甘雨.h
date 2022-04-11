#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 甘雨 : public Advanced::Role
                {
                public:
                    ~甘雨();
                    甘雨(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        