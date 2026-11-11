
#include "Jogo.h"
#include "Jogador.h"
#include "Ente.h"
#include <SFML/Graphics.hpp>

namespace IlhaDosPiratas {

    Jogo::Jogo() :
        pGG(new Gerenciadores::GerenciadorGrafico()),
        pMenu(new Menu()),
        pJog1(NULL),
        pJog2(NULL),
        pFase1(nullptr),
        //pFase2(nullptr),
        jogando(false),
        faseSelecionada(0),
        quantidadeJogadores(1)
    {
        Ente::setGG(pGG);
    }

    Jogo::~Jogo()
    {
        delete pFase1;
        pFase1 = nullptr;

       // delete pFase2;
        //pFase2 = nullptr;

        delete pMenu;
        pMenu = nullptr;

        delete pGG;
        pGG = nullptr;
    }

    void Jogo::iniciarPartida()
    {
        if(pJog1 ==  NULL)
        {
            pJog1 = new Entidades::Personagens::Jogador(0);

            if(quantidadeJogadores == 2)
            {
                pJog2 = new Entidades::Personagens::Jogador(1);
            }
        }

        if(faseSelecionada == 1)
        {
            if(pFase1 == NULL)
            {
                pFase1 = new Fases::FasePrimeira(quantidadeJogadores, pJog1, pJog2);
            }
            else if(faseSelecionada == 2)
            {
                //pFase2 = new Fases::faseSegunda(quantidadeJogadores, pJog1, pJog2);
            }
        }

        jogando = true;
    }

    void Jogo::executar()
    {
        if (pGG == nullptr || pMenu == nullptr)
            return;

        sf::RenderWindow& janela = pGG->getJanela();

        while (janela.isOpen()) {

            sf::Event evento;

            while (janela.pollEvent(evento)) {

                if (evento.type == sf::Event::Closed) {
                    janela.close();
                }

                if (!jogando) {

                    Menu::Resultado resultado =
                        pMenu->tratarEventos(evento, janela);

                    if (resultado == Menu::INICIAR_PARTIDA) {

                        faseSelecionada =
                            pMenu->getFaseSelecionada();

                        quantidadeJogadores =
                            pMenu->getQuantidadeJogadores();

                        iniciarPartida();
                    }

                    else if (resultado == Menu::SAIR_DO_JOGO) {
                        janela.close();
                    }
                }
            }

            if (!janela.isOpen())
                break;

            janela.clear(sf::Color::Black);

            if (jogando) {

                if (faseSelecionada == 1 && pFase1 != nullptr) {
                    pFase1->executar();
                }
                else if (faseSelecionada == 2/* && pFase2 != nullptr*/) {
                   // pFase2->executar();
                }
            }
            else {
                pMenu->desenhar(janela);
            }

            pGG->mostrar();
        }
    }
}
