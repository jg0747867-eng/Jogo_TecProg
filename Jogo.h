
#ifndef JOGO_H_
#define JOGO_H_

#include "GerenciadorGrafico.h"
#include "Mansao.h"
#include "FaseSegunda.h"
#include "Menu.h"

namespace Tripulacao_Amaldicoada {

    class Jogo {
    private:
        Gerenciadores::GerenciadorGrafico* pGG;
        Entidades::Personagens::Jogador* pJog1;
        Entidades::Personagens::Jogador* pJog2;

        Fases::Mansao* pFase1;
        Fases::FaseSegunda* pFase2;

        Menu* pMenu;

        bool jogando;
        bool pausado;

        int faseSelecionada;
        int quantidadeJogadores;

        void iniciarPartida();
        void terminarPartida();
        void reiniciarFase();
        void avancarFase();

    public:
        Jogo();
        ~Jogo();

        void executar();
    };
}

#endif
