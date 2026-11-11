#include "Fase.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Fantasma.h"
#include "GerenciadorGrafico.h"
#include <iostream>

namespace IlhaDosPiratas {
	namespace Fases {
		Fase::Fase(int quantidadeJogadores,
				Entidades::Personagens::Jogador* pJog1,
				Entidades::Personagens::Jogador* pJog2): Ente(),
			pGC(new Gerenciadores::GerenciadorColisoes()),
			pJog1(pJog1),
			pJog2(pJog2),
			limiteChao(900),
			maxFantasmas(10),
			maxPlataformas(10),
			inimigosVivos(0),
			faseConcluida(false)
		{
			if (pGC != NULL)
			{
				pGC->setLimiteChao(limiteChao);
			}
			this->quantidadeJogadores = quantidadeJogadores;
		}
		Fase::~Fase() {
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

			if (!jogadorVivo())
			{
				pGG->fecharJanela();
			}
		}
		void Fase::criarFantasmas()
		{
			int quantidade = gerarQuantidadeAleatoria(maxFantasmas);

			int posicoes[10][2] = {
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
			}
		}
		void Fase::criarPlataformas()
		{
			int quantidade = gerarQuantidadeAleatoria(maxPlataformas);

			int posicoes[10][4] = { //X, Y, Largura, Altura
			{200,   800, 150, 35},
			{440,  700, 300, 35},
			{820,  560, 300, 35},
			{1200, 720, 300, 35},
			{1540, 580, 300, 35},
			{250,  430, 280, 35},
			{650,  300, 280, 35},
			{1050, 390, 280, 35},
			{1420, 260, 280, 35},
			{1580, 850, 260, 35} };

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

			criarFantasmas();
			criarObstaculos();
			criarPlataformas();
			criarInimigos();
		}

		int Fase::gerarQuantidadeAleatoria(const int maximo) const {
			const int minimo = 3;

			if (maximo < minimo) {
				return minimo;
			}

			return minimo + rand() % (maximo - minimo + 1);
		}
		bool Fase::acabou() const {
			return faseConcluida;
		}
	}
}