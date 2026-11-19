#include "Esqueleto.h"
#include "Jogador.h"
#include "Osso.h"
#define VELOCIDADE_ESQUELETO_X 2.0f
#define INTERVALO_TIRO 2.0f

namespace
{
    struct TexturaEsqueleto
    {
        sf::Texture textura;
        bool carregada;

        TexturaEsqueleto()
        {
            carregada = textura.loadFromFile("assets/esqueleto.png");

            if (!carregada)
                std::cout << "Erro ao carregar assets/esqueleto.png" << std::endl;
        }
    };

    TexturaEsqueleto& obterTexturaEsqueleto()
    {
        static TexturaEsqueleto recurso;
        return recurso;
    }
}

namespace Tripulacao_Amaldicoada
{
    namespace Entidades
    {
        namespace Personagens
        {
            Esqueleto::Esqueleto(Jogador* pJogador, Osso* pO): Inimigo(), jogador(pJogador),
                    pOsso(pO), lancarProjetil(), relogioPulo(), 
                    intervaloPulo(2.0f), pulando(false)
            {
                num_vidas = 3;
                body.setFillColor(sf::Color::White);
                inicializa();

                TexturaEsqueleto& carregar = obterTexturaEsqueleto();

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

            Esqueleto::~Esqueleto()
            {
                pOsso = NULL;
            }

            void Esqueleto::inicializa()
            {
                vel = sf::Vector2f(VELOCIDADE_ESQUELETO_X, 0.0f);
                nivel_maldade = 3;
            }

            void Esqueleto::pular()
            {
                if(noChao)
                {
                    velocidadeY = - 25;
                    noChao = false;
                    pulando = true;
                }
            }

            void Esqueleto::pulosAleatorios()
            {
                if(relogioPulo.getElapsedTime().asSeconds() >= intervaloPulo)
                {
                    pular();
                    intervaloPulo = 2.0f + (rand() % 35) / 10.0f;
                    relogioPulo.restart();
                }
            }

            void Esqueleto::mover()
            {
                pulosAleatorios();

                if(pulando)
                {
                    if(noChao)
                    {
                        pulando = false;
                    }
                    else
                    {
                        setPosicao(getX() - static_cast<int>(vel.x), getY());                    
                    }
                }
            }

            void Esqueleto::executar()
            {
                mover();
                danificar(jogador);
                aplicarGravidade();
            }

            void Esqueleto::salvar()
            {

            }

            void Esqueleto::danificar(Jogador* pJogador)
            {
                if (pJogador == NULL || !pJogador->estaAtivo() || pOsso == NULL)
                {
                    return;
                }

                if (!pOsso->estaAtivo() && lancarProjetil.getElapsedTime().asSeconds() >= INTERVALO_TIRO)
                {
                    float origemX = getX() + body.getSize().x * 0.5f;
                    float origemY = getY() + body.getSize().y * 0.4f;

                    float alvoX = pJogador->getX() + pJogador->getBody().getSize().x * 0.5f;
                    float alvoY = pJogador->getY() + pJogador->getBody().getSize().y * 0.5f;

                    pOsso->disparar(origemX, origemY, alvoX, alvoY);
                    lancarProjetil.restart();
                }
            }

        }
    }
}