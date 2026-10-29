#include "Plataforma.h"
#include "Jogador.h"

namespace Trabalhojogo {
	namespace Entidades {
		namespace Obstaculos {
			namespace Personagens {
				class Jogador;
			}
			Plataforma::Plataforma() :
				Obstaculo(),
				altura(30),
				baseY(600)
			{
				danoso = false;

				body.setSize(sf::Vector2f(1200.0f, 30.f));
				body.setFillColor(sf::Color::Yellow);

				/*if (!carregarTextura("assets/"))
				{
					body.setFillColor(sf::Color::Red);
				}
				*/
				setPosicao(0, baseY);
			}
			Plataforma::Plataforma(int x, int y, int largura, int altu) :
				Obstaculo(),
				altura(altu),
				baseY(y)
			{
				danoso = false;

				body.setSize(sf::Vector2f(static_cast<float>(largura),
					static_cast<float>(altura)));

				body.setFillColor(sf::Color::Yellow);

				/*if (!carregarTextura("assets/"))
				{
					body.setFillColor(sf::Color::Red);
				}
				*/
				setPosicao(x, baseY);
			}
			Plataforma::~Plataforma()
			{}

			void Plataforma::executar()
			{
				aplicarGravidade();
				seguraPlat();
			}
			void Plataforma::seguraPlat()
			{
				aplicarGravidade();

				int forcaSegura = getY() - baseY;

				setPosicao(getX(), getY() - forcaSegura);

				zerarVelocidadeY();
				setNoChao(true);
			}
			void Plataforma::obstaculizar(Trabalhojogo::Entidades::Personagens::Jogador* pJogador)
			{
				if (pJogador == 0)
				{
					return;
				}

				sf::FloatRect corpoJogador = pJogador->getBody().getGlobalBounds();
				sf::FloatRect corpoPlataforma = body.getGlobalBounds();

				if (corpoJogador.intersects(corpoPlataforma)) {
					float baseJogador = corpoJogador.top + corpoJogador.height;
					float topoPlataforma = corpoPlataforma.top;
					float baseAnterior = baseJogador - pJogador->getVelocidadeY();

					if (pJogador->getVelocidadeY() >= 0 && baseAnterior <= topoPlataforma) {
						pJogador->setPosicao(pJogador->getX(), static_cast<int>(topoPlataforma - corpoJogador.height));
					}

					pJogador->zerarVelocidadeY();
					pJogador->setNoChao(true);
				}

			}
			void Plataforma::salvar()
			{}
		}
	}
}