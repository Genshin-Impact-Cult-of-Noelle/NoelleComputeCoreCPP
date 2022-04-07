
        #pragma once
        #include "../Role.h"
        using namespace Professional;
        namespace  Electro{
        class 刻晴 : public Role
        {
        public:
            ~刻晴();
            刻晴();
            void A(Role*, u8*);
            void E(Role*, u8*);
            void Q(Role*, u8*);
        private:
        
        };
        }
        