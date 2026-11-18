#ifndef ESPINHO_H_
#define ESPINHO_H_

#include "Obstaculo.h"

namespace Tripulacao_Amaldicoada {
    namespace Entidades {
        namespace Obstaculos {

            class Espinho : public Obstaculo
            {
            private:
                short int danosidade;
                bool baseDefinida;

                int empuxo;
                int baseY;

                float chanceVeneno;

            public:
                Espinho();
                ~Espinho();

                void salvarDataBuffer();
                void salvar();
                void executar();

                void obstaculizar(Tripulacao_Amaldicoada::Entidades::Personagens::Jogador* pJogador);

                virtual void aplicarEmpuxo();
            };
        }
    }

}

#endif