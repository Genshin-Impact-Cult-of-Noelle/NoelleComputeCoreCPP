#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 菲谢尔 : public Advanced::Role
                {
                public:
                    ~菲谢尔();
                    菲谢尔(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        