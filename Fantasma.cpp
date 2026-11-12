#include "Fantasma.h"
#include "Jogador.h"
#include "GerenciadorColisoes.h"
#include "cmath"
#define VELOCIDADE_INIMIGOFACIL_X 1.0f
#define VELOCIDADE_INIMIGOFACIL_Y 1.0f

using namespace IlhaDosPiratas;
using namespace Entidades;
using namespace Personagens;

namespace IlhaDosPiratas {
	namespace Entidades {
		namespace Personagens {

			Fantasma::Fantasma(Jogador* pJogador): Inimigo(), jogador(pJogador), relogio(), baseY(0), baseDefinida(false)
            {
                body.setFillColor(sf::Color::White);
                inicializa();
                srand(time(NULL));
                moveAleatorio = rand()%4;
            }

            Fantasma::~Fantasma()
            {

            }

            void Fantasma::inicializa()
            {
                vel = sf::Vector2f(VELOCIDADE_INIMIGOFACIL_X,  VELOCIDADE_INIMIGOFACIL_Y);

                carregarTextura("assets/fantasma.png");
                nivel_maldade = 1;
            }

            void Fantasma::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
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

            void Fantasma::executar()
            {
                //aplicarGravidade();
                mover();
                aplicarEmpuxo();

            }

            void Fantasma::movimentoAleatorio()
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

            void Fantasma::mover()
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
            void Fantasma::salvar()
            {

            }

            void Fantasma::danificar(Jogador* pJogador)
            {
                if (pJogador)
                {
                    pJogador->operator--();
                }
            }
            void Fantasma::aplicarEmpuxo()
            {
                if (!baseDefinida)
                {
                    baseY = getY();
                    baseDefinida = true;
                }
                aplicarGravidade();

                int forcaEmpuxo = getY() - baseY;

                if (forcaEmpuxo > 0)
                {
                    setPosicao(getX(), baseY);
                    zerarVelocidadeY();
                    setNoChao(true);
                }
            }
    }   }
}   