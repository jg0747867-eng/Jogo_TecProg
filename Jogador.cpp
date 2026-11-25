#include "Jogador.h"
#include "Obstaculo.h"

#define TEMPO_INVULNERAVEL 1.5f

using namespace Tripulacao_Amaldicoada;
using namespace Entidades;
using namespace Personagens;

namespace Tripulacao_Amaldicoada {
    namespace Entidades {
        namespace Personagens {
            Jogador::Jogador(int id): 
                Personagem(),   
                pontos(0),
                direcao(1),
                id(id),
                lento(false),
                invulneravel(false),
                envenenado(false),
                vermelho(false)
            {
                inicializa();

                fontePontos.loadFromFile("assets/fonte.ttf");

                textoPontos.setFont(fontePontos);
                textoPontos.setCharacterSize(25);
                textoPontos.setFillColor(sf::Color::White);

                textoVida.setFont(fontePontos);
                textoVida.setCharacterSize(25);
                textoVida.setFillColor(sf::Color::Red);

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
                try
                {
                    num_vidas = 200;
                    pontos = 0;

                    body.setSize(sf::Vector2f(100.0f, 100.0f));
                    body.setFillColor(sf::Color::White);

                    if (!carregarTextura("assets/jogador1.png"))
                    {
                        throw std::runtime_error("Erro ao carregar a textura do jogador!");
                    }
                }
                catch (const std::runtime_error& erro)
                {
                    std::cout << erro.what() << std::endl;
                    body.setFillColor(sf::Color::Red);
                }
            }

            void Jogador::operator--()
            {
                receberDano(1);
            }


            void Jogador::operator++(int nivel_maldade)
            {
                if(nivel_maldade == 1)
                {
                    pontos += 2;
                }
                else if(nivel_maldade == 2)
                {
                    pontos += 4;
                }
                else
                {
                    pontos += 5;
                }

                std::cout << "\n" << pontos;
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


            bool Jogador::receberDano(int dano)
            {
                if (invulneravel || !estaAtivo())
                    return false;

                num_vidas -= dano;

                invulneravel = true;
                relogioInvulneravel.restart();

               
                vermelho = true;
                relogioVermelho.restart();
                body.setFillColor(sf::Color::Red);

                if (num_vidas <= 0)
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
                    num_vidas--;

                    vermelho = true;
                    relogioVermelho.restart();
                    body.setFillColor(sf::Color::Red);

                    relogioDanoVeneno.restart();

                    if (num_vidas <= 0)
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

            void Jogador::desenharPontos(sf::RenderWindow& janela, float x, float y)
            {
                textoPontos.setString("Pontos: " + std::to_string(pontos));
                textoPontos.setPosition(x, y);
                textoVida.setString("Vida: " + std::to_string(num_vidas));
                textoVida.setPosition(x, y + 35.f);
                janela.draw(textoPontos);
                janela.draw(textoVida);
            }

        }
    }
}

