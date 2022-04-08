#pragma once
        #include "../Role.h"
        using namespace Professional;
        namespace DB {
            namespace RoleConstruct {        
                class 魈 : public Role
                {
                public:
                    ~魈();
                    魈();
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                    void SP(Role*,u32);
                private:
        
                };
            }
        }
        