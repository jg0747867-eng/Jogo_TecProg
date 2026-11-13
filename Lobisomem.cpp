#include "Lobisomem.h"
#include "Jogador.h"

#define VELOCIDADE_LOBISOMEM_X 2.0f

namespace IlhaDosPiratas
{
    namespace Entidades
    {
        namespace Personagens
        {
            Lobisomem::Lobisomem(Jogador* pJogador): Inimigo(), jogador(pJogador), 
                    relogioPatrulha(), direcaoPatrulha(rand()%2),
                    relogioPulo(), intervaloPulo(2.0f)
            {
                body.setFillColor(sf::Color::Green);
                inicializa();
            }

            Lobisomem::~Lobisomem()
            {

            }

            void Lobisomem::inicializa()
            {
                vel = sf::Vector2f(VELOCIDADE_LOBISOMEM_X, 0.0f);
            }

            void Lobisomem::patrulhar()
            {
                sf::Vector2f posAtual = body.getPosition();
                float novoX =  posAtual.x;

                if(direcaoPatrulha == 0)
                {
                    novoX += vel.x;
                }
                else if (direcaoPatrulha == 1)
                {
                    novoX -= vel.x;
                }

                setPosicao(novoX, getY());

                if(relogioPatrulha.getElapsedTime().asSeconds() >= 2.0f)
                {
                    direcaoPatrulha = rand() % 2;
                    relogioPatrulha.restart();
                }
            }

            void Lobisomem::pular()
            {
                if(noChao)
                {
                    velocidadeY = -15;
                    noChao = false;
                }
            }

            void Lobisomem::pulosAleatorios()
            {
                if(relogioPulo.getElapsedTime().asSeconds() >= intervaloPulo)
                {
                    pular();
                    intervaloPulo = 1.5f + (rand() % 30) / 10.0f;
                    relogioPulo.restart();
                }
            }

            void Lobisomem::executar()
            {
                mover();
                pulosAleatorios();
                aplicarGravidade();
            }

            void Lobisomem::mover()
            {
                int largura = static_cast<int>(body.getSize().x);

                if(getX() <= 0)
                {
                    direcaoPatrulha = 0;
                    pular();
                }
                else if(getX() + largura >= 1900)
                {
                    direcaoPatrulha = 1;
                    pular();
                }
                
                patrulhar();
            }

            void Lobisomem::salvar()
            {

            }

            void Lobisomem::danificar(Jogador* pJogador)
            {

            }
        }
    }
}