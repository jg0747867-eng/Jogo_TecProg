#ifndef OBSTACULO_H_
#define OBSTACULO_H_

#include "Entidade.h"
namespace Trabalhojogo {
    namespace Entidades {
        namespace Obstaculos
        {
            class Jogador;
            class Obstaculo : public Entidade
            {
            protected:
                bool danoso;

            public:
                Obstaculo();

                ~Obstaculo();

                // void salvarDataBuffer();

                virtual void executar() = 0;
                virtual void salvar() = 0;
                virtual void obstaculizar(Jogador* pJogador) = 0;
            };
        }
    }
 }
 




#endif
