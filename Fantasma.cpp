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

			Fantasma::Fantasma(Jogador* pJogador): Inimigo(), jogador(pJogador), relogio(), moveAleatorio(rand()%4)
            {
                body.setFillColor(sf::Color::White);
                inicializa();
            }

            Fantasma::~Fantasma()
            {

            }

            void Fantasma::inicializa()
            {
                vel = sf::Vector2f(VELOCIDADE_INIMIGOFACIL_X,  VELOCIDADE_INIMIGOFACIL_Y);

                carregarTextura("/home/carlos/pqp/Jogo_TecProg/assets/fantasma.png");
                nivel_maldade = 1;
            }

            void Fantasma::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
            {
                int novoX = getX();
                int novoY = getY();
                float dx = posJogador.x - posInimigo.x;
                float dy = posJogador.y - posInimigo.y;

                if (dx > vel.x)
                {
                    novoX += vel.x;
                }       
                else if (dx < -vel.x) 
                {
                    novoX -= vel.x;
                }
                if (dy > vel.y) 
                {
                    novoY += vel.y;
                }
                else if (dy < -vel.y) 
                {
                    novoY -= vel.y;
                }
                setPosicao(novoX, novoY);
            }
            
            void Fantasma::executar()
            {
                //aplicarGravidade();
                mover();
                aplicarEmpuxo();

            }

            void Fantasma::voar()
            {
                sf::Vector2f posAtual = body.getPosition();
                float novoX = posAtual.x;
                float novoY = posAtual.y;

                if(moveAleatorio == 0)
                {
                   novoX += vel.x;
                }
                else if(moveAleatorio == 1)
                {
                    novoX -= vel.x;
                }
                else if(moveAleatorio == 2)
                {
                    novoY += vel.y;
                }
                else
                {
                    novoY -= vel.y;
                }

                setPosicao(novoX, novoY);

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
                    voar();
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
                
                int xAntes = getX();
                int yAntes = getY();

                aplicarGravidade();

                setPosicao(xAntes, yAntes); 
                zerarVelocidadeY();                      
            }
    }   }
}   