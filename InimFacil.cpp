#include "InimFacil.h"
#include "Jogador.h"
#include "cmath"
#define VELOCIDADE_INIMIGOFACIL_X 1.0f
#define VELOCIDADE_INIMIGOFACIL_Y 1.0f

using namespace Trabalhojogo;
using namespace Entidades;
using namespace Personagens;

namespace Trabalhojogo {
	namespace Entidades {
		namespace Personagens {

			InimFacil::InimFacil(Jogador* pJogador): Inimigo(), jogador(pJogador), relogio()
            {
                body.setFillColor(sf::Color::White);
                inicializa();
                srand(time(NULL));
                moveAleatorio = rand()%4;
            }

            InimFacil::~InimFacil()
            {

            }

            void InimFacil::inicializa()
            {
                vel = sf::Vector2f(VELOCIDADE_INIMIGOFACIL_X,  VELOCIDADE_INIMIGOFACIL_Y);

                carregarTextura("assets/polvo1.png");
            }

            void InimFacil::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
            {
                if(posJogador.x - posInimigo.x > 0.0f)
                {
                    body.move(vel.x, 0.0f);
                }
                else
                {
                    body.move(-vel.x, 0.0f);
                }
                if (posJogador.y - posInimigo.y > 0.0f)
                {
                    body.move(0.0f, vel.y);
                }
                else
                {
                    body.move(0.0f, -vel.y);
                }
            }

            void InimFacil::executar()
            {
                mover();
                //movimentoAleatorio();

            }

            void InimFacil::movimentoAleatorio()
            {
                if(moveAleatorio == 0)
                {
                    body.move(vel.x, 0.0f);
                }
                else if(moveAleatorio == 1)
                {
                    body.move(-vel.x, 0.0f);
                }
                else if(moveAleatorio == 2)
                {
                    body.move(0.0f, vel.y);
                }
                else
                {
                    body.move(0.0f, -vel.y);
                }

                float dt = relogio.getElapsedTime().asSeconds();
                if (dt >= 1.0f)
                {
                    moveAleatorio = rand()%4;
                    relogio.restart();
                }
            }

            void InimFacil::mover()
            {
                sf::Vector2f posJogador = jogador->getBody().getPosition();
                sf::Vector2f posInimigo = body.getPosition();

                if(fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && 
                    fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y)
                    persegueJogador(posJogador, posInimigo);
                else
                {
                    movimentoAleatorio();
                }
            }
            void InimFacil::salvar()
            {}



		}
	}
}   