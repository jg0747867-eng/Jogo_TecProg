
#include "Espinho.h"
#include "Jogador.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

namespace
{
    struct TexturaEspinho
    {
        sf::Texture textura;
        bool carregada;

        TexturaEspinho()
        {
            carregada = textura.loadFromFile("assets/espinho.png");

            if (!carregada)
                std::cout << "Erro ao carregar assets/espinho.png" << std::endl;
        }
    };

    TexturaEspinho& obterTexturaEspinho()
    {
        static TexturaEspinho recurso;
        return recurso;
    }
}

namespace Tripulacao_Amaldicoada {
    namespace Entidades {
        namespace Obstaculos {

            Espinho::Espinho() :
                Obstaculo(),
                danosidade(1),
                baseDefinida(false),
                empuxo(0),
                baseY(0),
                chanceVeneno(25.0f)
            {
                danoso = true;

                body.setSize(sf::Vector2f(90.0f, 80.0f));
                body.setFillColor(sf::Color::White);

                TexturaEspinho& carregar = obterTexturaEspinho();

                if (carregar.carregada)
                {
                    body.setTexture(&carregar.textura);

                    body.setTextureRect(sf::IntRect(
                        0, 0,
                        carregar.textura.getSize().x,
                        carregar.textura.getSize().y
                    ));
                }
            }

            Espinho::~Espinho()
            {
            }

            void Espinho::executar()
            {
                if (!baseDefinida)
                {
                    baseY = getY();
                    baseDefinida = true;
                }

                aplicarEmpuxo();
            }

            void Espinho::salvar()
            {
            }

            void Espinho::obstaculizar(Tripulacao_Amaldicoada::Entidades::Personagens::Jogador* pJogador)
            {
                if (pJogador == NULL || !danoso)
                    return;

                if (pJogador->receberDano(1))
                {
                    for (int i = 1; i < danosidade; i++)
                        pJogador->receberDano(1);

                    int sorteio = rand() % 100;

                    if (sorteio < chanceVeneno)
                    {
                        pJogador->aplicarVeneno();
                    }
                }
            }

            void Espinho::aplicarEmpuxo()
            {
                aplicarGravidade();
                setPosicao(getX(), baseY);
            }

        }
    }
}
