
#include "Jogo.h"
#include "Ente.h"
#include <SFML/Graphics.hpp>

namespace IlhaDosPiratas {

    Jogo::Jogo() :
        pGG(new Gerenciadores::GerenciadorGrafico()),
        pMenu(new Menu()),
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
        if (faseSelecionada == 1) {
            if (pFase1 == nullptr)
                pFase1 = new Fases::FasePrimeira(quantidadeJogadores);
        }
        else if (faseSelecionada == 2) {
          // if (pFase2 == nullptr)
                //pFase2 = new Fases::FaseSegunda();
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
