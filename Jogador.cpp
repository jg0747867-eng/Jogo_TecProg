#include "Jogador.h"
#include "Obstaculo.h"

#define TEMPO_INVULNERAVEL 1.5f

using namespace IlhaDosPiratas;
using namespace Entidades;
using namespace Personagens;

namespace IlhaDosPiratas {
    namespace Entidades {
        namespace Personagens {
            Jogador::Jogador(int id) : 
                Personagem(),   
                pontos(0),
                direcao(1),
                id(id),
                vida(10),
                lento(false),
                invulneravel(false),
                envenenado(false),
                vermelho(false)
            {
                inicializa();
                if (id == 1) 
                {
                    teclaEsq  = sf::Keyboard::Left;
                    teclaDir  = sf::Keyboard::Right;
                    teclaPulo = sf::Keyboard::Up;
                } 
                else 
                {
                    teclaEsq  = sf::Keyboard::A;
                    teclaDir  = sf::Keyboard::D;
                    teclaPulo = sf::Keyboard::W;
                }
            }

            Jogador::~Jogador()
            {
                vida = 0;
            }

            void Jogador::inicializa()
            {
                pontos = 0;
                body.setSize(sf::Vector2f(120.0f, 120.0f));
                body.setFillColor(sf::Color::White);
                
                if (!carregarTextura("assets/jogador1.png")) {
                    body.setFillColor(sf::Color::Red);
                }

            }

            void Jogador::operator--()
            {
                receberDano();
            }



            void Jogador::mover()
            {
                const int velocidadeX = lento ? 1 : 5;

                int novoX = getX();
                int antigoX = getX();

                if (sf::Keyboard::isKeyPressed(teclaEsq))
                    novoX -= velocidadeX;

                if (sf::Keyboard::isKeyPressed(teclaDir))
                    novoX += velocidadeX;

                if (novoX < antigoX)
                    direcao = -1;
                else if (novoX > antigoX)
                    direcao = 1;

                if (sf::Keyboard::isKeyPressed(teclaPulo))
                    pular();

                setPosicao(novoX, getY());
            }



            void Jogador::executar()
            {
                if (!estaAtivo())
                    return;

                if (invulneravel &&
                    relogioInvulneravel.getElapsedTime().asSeconds() >= TEMPO_INVULNERAVEL)
                {
                    invulneravel = false;
                }
    
                if (vermelho && relogioVermelho.getElapsedTime().asSeconds() >= 0.2f)
                {
                    vermelho = false;
                    body.setFillColor(sf::Color::White);
                }

                mover();
                aplicarGravidade();
                atualizarVeneno();
            }


            void Jogador::salvar()
            {

            }


            bool Jogador::receberDano()
            {
                if (invulneravel || !estaAtivo())
                    return false;

                vida--;

                invulneravel = true;
                relogioInvulneravel.restart();

               
                vermelho = true;
                relogioVermelho.restart();
                body.setFillColor(sf::Color::Red);

                if (vida <= 0)
                    desativar();

                return true;
            }

            void Jogador::aplicarVeneno()
            {
                if (!envenenado && estaAtivo())
                {
                    envenenado = true;
                    relogioVeneno.restart();
                    relogioDanoVeneno.restart();
                }
            }

            void Jogador::atualizarVeneno()
            {
                if (!envenenado || !estaAtivo())
                    return;

                if (relogioDanoVeneno.getElapsedTime().asSeconds() >= 1.0f)
                {
                    vida--;

                    vermelho = true;
                    relogioVermelho.restart();
                    body.setFillColor(sf::Color::Red);

                    relogioDanoVeneno.restart();

                    if (vida <= 0)
                    {
                        desativar();
                        envenenado = false;
                        return;
                    }
                }

                if (relogioVeneno.getElapsedTime().asSeconds() >= 5.0f)
                {
                    envenenado = false;
                }
            }

        }
    }
}

