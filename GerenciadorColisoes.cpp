#include "GerenciadorColisoes.h"
#include "Entidade.h"
#include "Jogador.h"
#include "Obstaculo.h"
#include "Inimigo.h"

#include <iostream>

namespace Trabalhojogo {
	namespace Gerenciadores {
		GerenciadorColisoes::GerenciadorColisoes() : pJog1(NULL), limiteChao(0) {}
		GerenciadorColisoes::~GerenciadorColisoes() 
		{
			LIs.clear();
			LOs.clear();
			LPs.clear();
			pJog1 = NULL;
		}
		void GerenciadorColisoes::setJogador(Entidades::Personagens::Jogador* pJogador) {
			pJog1 = pJogador;
		}
		/*bool const GerenciadorColisoes::verificarColisao(
			Entidades::Entidade* pE1,
			Entidades::Entidade* pE2) const
		{
			
		}*/
		void GerenciadorColisoes::incluirInimigo(Entidades::Personagens::Inimigo* pI) 
		{}
		
		void GerenciadorColisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO) 
		{}

		void GerenciadorColisoes::incluirProjetil(Entidades::Projetil* pP) 
		{}

		void GerenciadorColisoes::tratarColisoesJogsObstaculos() 
		{}

		void GerenciadorColisoes::tratarColisoesInimigosObstaculos() 
		{}

		void GerenciadorColisoes::tratarColisoesJogsInimigos() 
		{}

		void GerenciadorColisoes::tratarColisoesJogsProjeteis()
		{}

		void GerenciadorColisoes::executar() 
		{}

		void GerenciadorColisoes::setLimiteChao(int limite)
		{
			limiteChao = limite;
		}

		void GerenciadorColisoes::tratarColisaoChao(Entidades::Entidade* pEntidade)
		{
			if (pEntidade == NULL)
			{
				return;
			}

			sf::FloatRect corpo = pEntidade->getBody().getGlobalBounds();

			float base = corpo.top + corpo.height;

			if (base >= limiteChao)
			{
				int novoY = limiteChao - static_cast<int>(corpo.height);

				pEntidade->setPosicao(pEntidade->getX(), novoY);
				pEntidade->zerarVelocidadeY();
				pEntidade->setNoChao(true);
			}
		}

		void GerenciadorColisoes::tratarColisaoEntidadeObstaculo(Entidades::Entidade* pEntidade, Entidades::Obstaculos::Obstaculo* pObstaculo) 
		{}

	}
}



