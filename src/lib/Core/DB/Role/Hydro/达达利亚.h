﻿#pragma once
        #include "../Role.h"
        namespace DB {
            namespace RoleConstruct {        
                class 达达利亚 : public Advanced::Role
                {
                public:
                    ~达达利亚();
                    达达利亚(u32*);
                    void A(Role*, u32);
                    void E(Role*, u32);
                    void Q(Role*, u32);
                };
            }
        }
        