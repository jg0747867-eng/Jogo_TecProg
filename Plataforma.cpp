#include "Plataforma.h"
#include "Jogador.h"

namespace
{
	struct TexturaPlataforma
	{
		sf::Texture textura;
		bool carregada;

		TexturaPlataforma()
		{
			carregada = textura.loadFromFile("assets/plataforma.png");

			if (!carregada)
				std::cout << "Erro ao carregar assets/plataforma.png" << std::endl;
		}
	};

	TexturaPlataforma& obterTexturaPlataforma()
	{
		static TexturaPlataforma recurso;
		return recurso;
	}
}

namespace Tripulacao_Amaldicoada {
	namespace Entidades {
		namespace Obstaculos {
			namespace Personagens {
				class Jogador;
			}
			Plataforma::Plataforma() :
				Obstaculo(),
				altura(30),
				baseY(600),
				limiteY(700),
				caindo(false),
				subindo(false),
				espera(1.5f)
			{
				danoso = false;

				body.setSize(sf::Vector2f(1200.0f, 30.f));
				body.setFillColor(sf::Color::White);

				TexturaPlataforma& carregar = obterTexturaPlataforma();

				if (carregar.carregada)
				{
					body.setTexture(&carregar.textura);

					body.setTextureRect(sf::IntRect(
						0, 0,
						carregar.textura.getSize().x,
						carregar.textura.getSize().y
					));
				}
				
				setPosicao(0, baseY);
			}
			Plataforma::Plataforma(int x, int y, int largura, int altu) :
				Obstaculo(),
				altura(altu),
				baseY(y),
				limiteY(y + 100),
				caindo(false),
				subindo(false),
				espera(1.5f)
			{
				danoso = false;

				body.setSize(sf::Vector2f(static_cast<float>(largura),
					static_cast<float>(altura)));

				body.setFillColor(sf::Color::White);

				TexturaPlataforma& carregar = obterTexturaPlataforma();

				if (carregar.carregada)
				{
					body.setTexture(&carregar.textura);

					body.setTextureRect(sf::IntRect(
						0, 0,
						carregar.textura.getSize().x,
						carregar.textura.getSize().y
					));
				}
				
				setPosicao(x, baseY);
			}
			Plataforma::~Plataforma()
			{}

			void Plataforma::executar()
			{
				if (caindo)
				{
					setQuedaLenta(true);
					setNoChao(false);
					aplicarGravidade();

					if (getY() >= limiteY)
					{
						setPosicao(getX(), limiteY);
						zerarVelocidadeY();
						caindo = false;
						relogio.restart();
					}
				}
				else if (!subindo && getY() >= limiteY)
				{
					if (relogio.getElapsedTime().asSeconds() >= espera)
					{
						subindo = true;
						setNoChao(false);
					}
				}
				else if (subindo)
				{
					velocidadeY = -5;
					setPosicao(getX(), getY() + velocidadeY);

					if (getY() <= baseY)
					{
						setPosicao(getX(), baseY);
						zerarVelocidadeY();
						setNoChao(true);
						subindo = false;
					}
				}
			}
			void Plataforma::seguraPlat()
			{
				aplicarGravidade();

				int forcaSegura = getY() - baseY;

				setPosicao(getX(), getY() - forcaSegura);

				zerarVelocidadeY();
				setNoChao(true);
			}
			void Plataforma::obstaculizar(Tripulacao_Amaldicoada::Entidades::Personagens::Jogador* pJogador)
			{
				if (pJogador == NULL)
				{
					return;
				}

				sf::FloatRect corpoJogador = pJogador->getBody().getGlobalBounds();
				sf::FloatRect corpoPlataforma = body.getGlobalBounds();

				if (corpoJogador.intersects(corpoPlataforma))
				{
					float baseJogador = corpoJogador.top + corpoJogador.height;
					float topoPlataforma = corpoPlataforma.top;

					float baseAnterior = baseJogador - pJogador->getVelocidadeY();

					if (pJogador->getVelocidadeY() >= 0 &&
						baseAnterior <= topoPlataforma &&
						!subindo)
					{
						pJogador->setPosicao(
							pJogador->getX(),
							static_cast<int>(topoPlataforma - corpoJogador.height)
						);

						pJogador->zerarVelocidadeY();
						pJogador->setNoChao(true);

						if (!caindo && getY() < limiteY)
						{
							caindo = true;
						}
					}
				}
			}
			void Plataforma::salvar()
			{}
		}
	}
}