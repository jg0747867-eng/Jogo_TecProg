#include "Fase.h"
#include "Inimigo.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Fantasma.h"
#include "GerenciadorGrafico.h"
#include <iostream>

namespace Tripulacao_Amaldicoada {
	namespace Fases {
		Fase::Fase(int quantidadeJogadores,
				Entidades::Personagens::Jogador* pJog1,
				Entidades::Personagens::Jogador* pJog2): Ente(),
			pGC(new Gerenciadores::GerenciadorColisoes()),
			pJog1(pJog1),
			pJog2(pJog2),
			limiteChao(1000),
			maxFantasmas(5),
			maxPlataformas(5),
			inimigosVivos(0),
			faseConcluida(false)
		{
			if (pGC != NULL)
			{
				pGC->setLimiteChao(limiteChao);
			}
			this->quantidadeJogadores = quantidadeJogadores;
		}
		Fase::~Fase()
		{
			for (int i = 0; i < (int)listaEnts.getTamanho(); i++)
			{
				Entidades::Entidade* pE = listaEnts[i];

				if (pE != NULL && pE != pJog1 && pE != pJog2)
					delete pE;
			}
			listaEnts.limpaLista();

			delete pGC;
			pGC = NULL;
			pJog1 = NULL;
			pJog2 = NULL;
		}
		void Fase::executar() 
		{
			pGG->getJanela().draw(fundo);

			listaEnts.percorrer();
			if (pGC != NULL)
			{
				pGC->executar();
			}
			listaEnts.desenhar();

		}
		void Fase::criarFantasmas()
		{
			int quantidade = gerarQuantidadeAleatoria(maxFantasmas);

			int posicoes[10][2] = { //X, Y
				{340, 800},
				{540, 700},
				{820, 560},
				{1200, 720},
				{1540, 580},
				{250, 430},
				{650, 300},
				{1050, 390},
				{1420, 260},
				{1580, 850}
			};

			for (int i = 0; i < quantidade; i++)
			{
				Entidades::Personagens::Fantasma* pInim =
					new Entidades::Personagens::Fantasma(pJog1);

				pInim->setPosicao(posicoes[i][0], posicoes[i][1]);

				listaEnts.incluir(pInim);

				if (pGC != NULL)
				{
					pGC->incluirInimigo(pInim);
				}
				inimigosVivos++;
			}
		}
		void Fase::criarPlataformas()
		{
			int quantidade = gerarQuantidadeAleatoria(maxPlataformas);

			int posicoes[10][4] = { //X, Y, Largura, Altura
			{200,   800, 190, 35},
			{440,  700, 300, 35},
			{820,  560, 300, 35},
			{1200, 720, 300, 35},
			{1540, 580, 300, 35} };

			for (int i = 0; i < quantidade; i++)
			{
				Entidades::Obstaculos::Plataforma* pPlat =
					new Entidades::Obstaculos::Plataforma(
						posicoes[i][0], //x
						posicoes[i][1], //y
						posicoes[i][2], //Largura
						posicoes[i][3] //Altura
						);
				listaEnts.incluir(pPlat);

				if (pGC != NULL)
				{
					pGC->incluirObstaculo(pPlat);
				}
			}
		}
		void Fase::criarCenario()
		{
			if(pJog1 != NULL)
			{
				listaEnts.incluir(pJog1);

				if(pGC != NULL)
				{
					pGC->incluirJogador(pJog1);
				}
			}

			if(pJog2 != NULL)
			{
				listaEnts.incluir(pJog2);
				
				if(pGC != NULL)
				{
					pGC->incluirJogador(pJog2);
				}
			}

			criarObstaculos();
			criarInimigos();
		}

		int Fase::gerarQuantidadeAleatoria(const int maximo) const {
			const int minimo = 3;
			if (maximo < minimo) {
				return minimo;
			}

			return minimo + rand() % (maximo - minimo + 1);
		}
		bool Fase::acabou() const
		{
			return faseConcluida || contarInimigosVivos() == 0;
		}
		void Fase::concluirFase()
		{
			faseConcluida = true;
		}

		int Fase::contarInimigosVivos() const
		{
			int quantidade = 0;

			for (int i = 0; i < (int)listaEnts.getTamanho(); i++)
			{
				Entidades::Entidade* pEntidade = listaEnts[i];

				if (pEntidade != NULL && pEntidade->estaAtivo() && dynamic_cast<Entidades::Personagens::Inimigo*>(pEntidade) != NULL)
				{
					quantidade++;
				}
			}

			return quantidade;
		}

		bool Fase::todosInimigosMorreram() const
		{
			for (int i = 0; i < (int)listaEnts.getTamanho(); i++)
			{
				Entidades::Entidade* pEntidade = listaEnts[i];

				Entidades::Personagens::Inimigo* pInimigo =
					dynamic_cast<Entidades::Personagens::Inimigo*>(pEntidade);

				if (pInimigo != NULL && pInimigo->estaAtivo())
					return false;
			}

			return true;
		}
	}
}