
#pragma once

#ifndef JOGO_H_
#define JOGO_H_

#include "GerenciadorGrafico.h"
#include "FasePrimeira.h"

namespace Trabalhojogo {

    class Jogo {
    private:
        Gerenciadores::GerenciadorGrafico* pGG;
        Fases::FasePrimeira* pFase;

    public:
        Jogo();
        ~Jogo();

        void executar();
    };
}

#endif
