
#pragma once

#ifndef JOGO_H_
#define JOGO_H_

#include "GerenciadorGrafico.h"
#include "FasePrimeira.h"
#include "Menu.h"

namespace IlhaDosPiratas {

    class Jogo {
    private:
        Gerenciadores::GerenciadorGrafico* pGG;
        Fases::FasePrimeira* pFase1;
        //Fases::FaseSegunda* pFase2;
        Menu* pMenu;

        bool jogando;
        int faseSelecionada;
        int quantidadeJogadores;

        void iniciarPartida();

    public:
        Jogo();
        ~Jogo();

        void executar();
    };
}

#endif
