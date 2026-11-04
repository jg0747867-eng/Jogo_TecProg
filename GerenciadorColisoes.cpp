#include "GerenciadorColisoes.h"
#include "Entidade.h"
#include "Jogador.h"
#include "Obstaculo.h"
#include "Inimigo.h"

#include <iostream>

namespace Trabalhojogo {
	namespace Gerenciadores {
		GerenciadorColisoes::GerenciadorColisoes(): limiteChao(0) {}
		GerenciadorColisoes::~GerenciadorColisoes() 
		{
			LJs.clear();
			LIs.clear();
			LOs.clear();
			LPs.clear();
		}
		void GerenciadorColisoes::incluirJogador(Entidades::Personagens::Jogador* pJogador) {
			if (pJogador)
			{
				LJs.push_back(pJogador);
			}
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
			for(unsigned int i = 0; i < LJs.size(); i++)
			{
				Entidades::Personagens::Jogador* pJogador = LJs[i];

				if(pJogador == NULL)
				{
					continue;
				}

				pJogador->setNoChao(false);

				std::list<Entidades::Obstaculos::Obstaculo*>::iterator it;

				for (it = LOs.begin(); it != LOs.end(); it++)
				{
					Entidades::Obstaculos::Obstaculo* pObstaculo = *it;

					if (pObstaculo != NULL)
					{
						if (verificarColisao(pJogador, pObstaculo))
						{
							pObstaculo->obstaculizar(pJogador);
						}
					}
				}
			}

		}	
		void GerenciadorColisoes::tratarColisoesInimigosObstaculos()
		{
		
		}

		void GerenciadorColisoes::tratarColisoesJogsInimigos() 
		{
			for(unsigned int i = 0; i < LJs.size(); i++)
			{
				Entidades::Personagens::Jogador* pJogador = LJs[i];

				if (pJogador == NULL)
				{
					continue;
				}

				pJogador->setNoChao(false);

				for(unsigned int j = 0; j < LIs.size(); j++)
				{
					Entidades::Personagens::Inimigo* pInim = LIs[j];

					if(pInim == NULL)
					{
						continue;
					}

					if(verificarColisao(pJogador, pInim))
					{
						std::cout << "bati\n";
					}
					
				}
			}
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

			for (unsigned int i = 0; i < LJs.size(); i++)
			{
    			if (LJs[i] != NULL)
        		LimiteLateral(LJs[i]);
			}

			for (unsigned int i = 0; i < LIs.size(); i++)
			{
				if (LIs[i] != NULL)
					LimiteLateral(LIs[i]);
			}

			for (unsigned int i = 0; i < LJs.size(); i++)
			{
				if (LJs[i] != NULL && LJs[i]->estaAtivo())
				{
					tratarColisaoChao(LJs[i]);
				}
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



