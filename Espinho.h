#pragma once

#ifndef OBST_DIFICIL_H_
#define OBST_DIFICIL_H_

#include "Obstaculo.h"

namespace IlhaDosPiratas {
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

                void obstaculizar(IlhaDosPiratas::Entidades::Personagens::Jogador* pJogador);

                virtual void aplicarEmpuxo();
            };
        }
    }

}

#endif