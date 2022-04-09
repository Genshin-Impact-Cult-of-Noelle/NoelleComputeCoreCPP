#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 申鹤 : public Advanced::Role
                {
                public:
                    ~申鹤();
                    申鹤(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                    u32 GetFrameCur(){
                        return *_framCur;
                    };
                private:
                    u32* _framCur;
                };
            }
        }
        