
        #pragma once
        #include "../Role.h"
        using namespace Professional;
        namespace  Electro{
        class 雷电将军 : public Role
        {
        public:
            ~雷电将军();
            雷电将军();
            void A(Role*, u8*);
            void E(Role*, u8*);
            void Q(Role*, u8*);
        private:
        
        };
        }
        