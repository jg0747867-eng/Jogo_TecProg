#include "Jogador.h"
#include "Obstaculo.h"

using namespace Trabalhojogo;
using namespace Entidades;
using namespace Personagens;

namespace Trabalhojogo {
    namespace Entidades {
        namespace Personagens {
            Jogador::Jogador(int id) : Personagem(), id(id),
                //vel(sf::Vector2(0.0f, 0.0f)), 
                pontos(0),
                direcao(1)
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
            }

            void Jogador::inicializa()
            {
                pontos = 0;
                body.setSize(sf::Vector2f(150.0f, 150.0f));
                body.setFillColor(sf::Color::White);
                
                if (!carregarTextura("assets/jogador1.png")) {
                    body.setFillColor(sf::Color::Red);
                }
                //vel = sf::Vector2f(8.0f, 8.0f);
                //setPosicao(50, 200);

            }


            void Jogador::mover()
            {
                const int velocidadeX = 5;

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
                //inicializa();
                mover();
                aplicarGravidade();
            }


            void Jogador::salvar()
            {

            }
            void Jogador::pular() 
            {
                if (noChao)
                {
                    velocidadeY = -25;
                    noChao = false;
                }
            }
        }
    }
}


