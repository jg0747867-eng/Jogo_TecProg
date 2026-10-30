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
		bool const GerenciadorColisoes::verificarColisao(
			Entidades::Entidade* pE1,
			Entidades::Entidade* pE2) const
		{
			if (pE1 == NULL || pE2 == NULL) {
				return false;
			}

			if (!pE1->estaAtivo() || !pE2->estaAtivo()) {
				return false;
			}

			return pE1->getBody().getGlobalBounds().intersects(pE2->getBody().getGlobalBounds());
		}
		void GerenciadorColisoes::incluirInimigo(Entidades::Personagens::Inimigo* pI) 
		{
			if (pI != NULL) {
				LIs.push_back(pI);
			}
		}
		
		void GerenciadorColisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO) 
		{
			if (pO != NULL) {
				LOs.push_back(pO);
			}
		}

		void GerenciadorColisoes::incluirProjetil(Entidades::Projetil* pP) 
		{
			if (pP != NULL) {
				LPs.insert(pP);
			}
		}

		void GerenciadorColisoes::tratarColisoesJogsObstaculos() 
		{
			if (pJog1 == NULL) {
				return;
			}

			pJog1->setNoChao(false);

			std::list<Entidades::Obstaculos::Obstaculo*>::iterator it;

			for (it = LOs.begin(); it != LOs.end(); it++)
			{
				Entidades::Obstaculos::Obstaculo* pObstaculo = *it;

				if (pObstaculo != NULL)
				{
					if (verificarColisao(pJog1, pObstaculo))
					{
						pObstaculo->obstaculizar(pJog1);
					}
				}
			}
		}

		void GerenciadorColisoes::tratarColisoesInimigosObstaculos() 
		{
		
		}

		void GerenciadorColisoes::tratarColisoesJogsInimigos() 
		{
		
		}

		void GerenciadorColisoes::tratarColisoesJogsProjeteis()
		{
		
		}

		void GerenciadorColisoes::tratarColisoesObsDificil()
		{
		
		}

		void GerenciadorColisoes::executar() 
		{
			//tratarColisoesObsDificil();

			tratarColisoesJogsObstaculos();
			tratarColisoesInimigosObstaculos();

			if (pJog1 != NULL)
				LimiteLateral(pJog1);

			for (unsigned int i = 0; i < LIs.size(); i++)
			{
				if (LIs[i] != NULL)
					LimiteLateral(LIs[i]);
			}

			if (pJog1 != NULL && pJog1->estaAtivo())
			{
				tratarColisaoChao(pJog1);
			}

			for (unsigned int i = 0; i < LIs.size(); i++) {
				if (LIs[i] != NULL && LIs[i]->estaAtivo()) {
					tratarColisaoChao(LIs[i]);
				}
			}

			tratarColisoesJogsInimigos();
			tratarColisoesJogsProjeteis();
		}

		void GerenciadorColisoes::setLimiteChao(int limite)
		{
			limiteChao = limite;
		}

		void GerenciadorColisoes::tratarColisaoChao(
			Entidades::Entidade* pEntidade)
		{
			if (pEntidade == NULL || !pEntidade->estaAtivo())
				return;

			sf::FloatRect corpo = pEntidade->getBody().getGlobalBounds();

			float base = corpo.top + corpo.height;

			if (base >= limiteChao)
			{
				pEntidade->setPosicao(
					pEntidade->getX(),
					static_cast<int>(pEntidade->getY() - (base - limiteChao))
				);

				pEntidade->zerarVelocidadeY();
				pEntidade->setNoChao(true);
			}
		}

		void GerenciadorColisoes::tratarColisaoEntidadeObstaculo(Entidades::Entidade* pEntidade, Entidades::Obstaculos::Obstaculo* pObstaculo)
		{
		
		}

		void GerenciadorColisoes::LimiteLateral(Entidades::Entidade* pEnti)
		{
			if (pEnti == NULL || !pEnti->estaAtivo())
				return;

			const int limiteEsquerdo = 0;
			const int limiteDireito = 1900;

			int x = pEnti->getX();
			int largura = static_cast<int>(pEnti->getBody().getSize().x);

			if (x < limiteEsquerdo)
				pEnti->setPosicao(limiteEsquerdo, pEnti->getY());

			if (x + largura > limiteDireito)
				pEnti->setPosicao(limiteDireito - largura, pEnti->getY());

		}

	}
}



