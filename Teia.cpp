#include "Teia.h"
#include "Jogador.h"


namespace
{
    struct TexturaTeia
    {
        sf::Texture textura;
        bool carregada;

        TexturaTeia()
        {
            carregada = textura.loadFromFile("assets/teia.png");

            if (!carregada)
                std::cout << "Erro ao carregar assets/teia.png" << std::endl;
        }
    };

    TexturaTeia& obterTexturaTeia()
    {
        static TexturaTeia recurso;
        return recurso;
    }
}


namespace Tripulacao_Amaldicoada {
	namespace Entidades {
		namespace Obstaculos {

			Teia::Teia() : 
                Obstaculo(),
                baseY(0),
                baseDefinida(false),
                empuxo(0.0f)
			{
                danoso = false;

				body.setSize(sf::Vector2f(110.0f, 110.0f));
                body.setFillColor(sf::Color::White);

                TexturaTeia& carregar = obterTexturaTeia();

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

            Teia::~Teia()
            {
            }

            void Teia::executar()
            {
               if (!baseDefinida)
               {
                   baseY = getY();
                   baseDefinida = true;
               }

               aplicarEmpuxo();
            }

            void Teia::salvar()
            {
            }

            void Teia::obstaculizar(Tripulacao_Amaldicoada::Entidades::Personagens::Jogador* pJogador)
            {
                if (pJogador != NULL)
                {
                    pJogador->setLento(true);
                    pJogador->setQuedaLenta(true);
                }
            }
            void Teia::aplicarEmpuxo() 
            {
                aplicarGravidade();

                int forcaEmpuxo = getY() - baseY;

                setPosicao(getX(), getY() - forcaEmpuxo);

                zerarVelocidadeY();
                setNoChao(true);;
            }

		}
	}
}