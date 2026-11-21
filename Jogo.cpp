
#include "Jogo.h"
#include "Jogador.h"
#include "Ente.h"
#include <SFML/Graphics.hpp>

namespace Tripulacao_Amaldicoada {

    Jogo::Jogo() :
        pGG(new Gerenciadores::GerenciadorGrafico()),
        pJog1(NULL),
        pJog2(NULL),
        pFase1(NULL),
        pFase2(NULL),
        pMenu(new Menu()),
        jogando(false),
        pausado(false),
        faseSelecionada(0),
        quantidadeJogadores(1)
    {
        Ente::setGG(pGG);
    }

    Jogo::~Jogo()
    {
        terminarPartida();

        delete pMenu;
        pMenu = NULL;

        delete pGG;
        pGG = NULL;
    }

    void Jogo::iniciarPartida()
    {
        if (pJog1 == NULL)
            pJog1 = new Entidades::Personagens::Jogador(0);

        if (quantidadeJogadores == 2 && pJog2 == NULL)
            pJog2 = new Entidades::Personagens::Jogador(1);

        if (quantidadeJogadores == 1 && pJog2 != NULL) {
            delete pJog2;
            pJog2 = NULL;
        }

        if (faseSelecionada == 1) {

            pFase1 = new Fases::Mansao(
                quantidadeJogadores,
                pJog1,
                pJog2
            );
        }
        else if (faseSelecionada == 2) {

            pFase2 = new Fases::FaseSegunda(
                quantidadeJogadores,
                pJog1,
                pJog2
            );
        }

        jogando = true;
        pausado = false;
    }

    void Jogo::reiniciarFase()
    {
        if (faseSelecionada == 1) {

            delete pFase1;
            pFase1 = NULL;

            pFase1 = new Fases::Mansao(
                quantidadeJogadores,
                pJog1,
                pJog2
            );
        }
        else if (faseSelecionada == 2) {

            delete pFase2;
            pFase2 = NULL;

            pFase2 = new Fases::FaseSegunda(
                quantidadeJogadores,
                pJog1,
                pJog2
            );
        }

        pausado = false;
    }

    void Jogo::avancarFase()
    {
        if (faseSelecionada != 1)
            return;

        delete pFase1;
        pFase1 = NULL;

        faseSelecionada = 2;

        pFase2 = new Fases::FaseSegunda(
            quantidadeJogadores,
            pJog1,
            pJog2
        );

        if (pJog1 != NULL)
        {
            pJog1->setPosicao(100, 750);
            pJog1->zerarVelocidadeY();
            pJog1->setNoChao(false);
        }

        if (pJog2 != NULL)
        {
            pJog2->setPosicao(250, 700);
            pJog2->zerarVelocidadeY();
            pJog2->setNoChao(false);
        }
    }

    void Jogo::executar()
    {
        if (pGG == NULL || pMenu == NULL)
            return;

        sf::RenderWindow& janela = pGG->getJanela();

        while (janela.isOpen()) {

            sf::Event evento;

            while (janela.pollEvent(evento)) {

                if (evento.type == sf::Event::Closed) {
                    janela.close();
                }

                // ESC para pausar
                if (jogando &&
                    !pausado &&
                    evento.type == sf::Event::KeyPressed &&
                    evento.key.code == sf::Keyboard::Escape) {

                    pausado = true;
                    pMenu->abrirPausa();
                }

                if (!jogando || pausado) {

                    Menu::Resultado resultado = pMenu->tratarEventos(evento, janela);

                    if (resultado == Menu::INICIAR_PARTIDA) {

                        faseSelecionada =
                            pMenu->getFaseSelecionada();

                        quantidadeJogadores =
                            pMenu->getQuantidadeJogadores();

                        iniciarPartida();
                    }

                    else if (resultado == Menu::RETOMAR_PARTIDA) {
                        pausado = false;
                    }

                    else if (resultado == Menu::REINICIAR_FASE) {
                        reiniciarFase();
                    }

                    else if (resultado == Menu::VOLTAR_MENU_PRINCIPAL) {

                        terminarPartida();
                        pMenu->abrirMenuPrincipal();
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

                if (!pausado) {

                    if (faseSelecionada == 1 && pFase1 != NULL) {

                        pFase1->executar();

                        if (!pFase1->jogadorVivo())
                        {
                            int pontos = 0;

                            if (pJog1 != NULL)
                                pontos = pJog1->getPontos();

                            pMenu->registrarResultado(pontos);

                            terminarPartida();
                            pMenu->abrirResultado();
                        }
                    }

                    else if (faseSelecionada == 2 && pFase2 != NULL) {

                        pFase2->executar();

                        if (!pFase2->jogadorVivo() || pFase2->acabou())
                        {
                            int pontos = 0;

                            if (pJog1 != NULL)
                                pontos = pJog1->getPontos();

                            pMenu->registrarResultado(pontos);

                            terminarPartida();
                            pMenu->abrirResultado();
                        }
                    }
                }

                if (!pausado)
                {
                    if (pJog1 != NULL)
                        pJog1->desenharPontos(janela, 30.f, 20.f);

                    if (pJog2 != NULL)
                        pJog2->desenharPontos(janela, 1650.f, 20.f);
                }

                if (pausado) {
                    pMenu->desenharPausa(janela);
                }
            }
            else {
                pMenu->desenhar(janela);
            }

            pGG->mostrar();
        }
    }

    void Jogo::terminarPartida()
    {
        delete pFase1;
        pFase1 = NULL;

        delete pFase2;
        pFase2 = NULL;

        delete pJog1;
        pJog1 = NULL;

        delete pJog2;
        pJog2 = NULL;

        jogando = false;
        pausado = false;
        faseSelecionada = 0;
    }
}
