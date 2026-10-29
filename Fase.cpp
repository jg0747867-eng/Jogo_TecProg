#include "Fase.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "InimFacil.h"
#include "GerenciadorGrafico.h"
#include <iostream>

namespace Trabalhojogo {
	namespace Fases {
		Fase::Fase() : Ente(),
			pGC(new Gerenciadores::GerenciadorColisoes()),
			pJog1(NULL),
			limiteChao(900),
			maxInimFacil(10),
			maxPlataformas(10),
			inimigosVivos(0),
			faseConcluida(false)
		{
			if (pGC != NULL)
			{
				pGC->setLimiteChao(limiteChao);
			}
		}
		Fase::~Fase() {
			delete pGC;
			pGC = NULL;
			pJog1 = NULL;
		}
		void Fase::executar() {

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
		void Fase::criarInimFacil()
		{

		}
		void Fase::criarPlataformas()
		{
			int quantidade = gerarQuantidadeAleatoria(maxPlataformas);

			int posicoes[10][4] = { //X, Y, Largura, Altura
			{80,   800, 300, 45},
			{440,  700, 300, 45},
			{820,  560, 300, 45},
			{1200, 720, 300, 45},
			{1540, 580, 300, 45},
			{250,  430, 280, 45},
			{650,  300, 280, 45},
			{1050, 390, 280, 45},
			{1420, 260, 280, 45},
			{1580, 850, 260, 45} };

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
			pJog1 = new Entidades::Personagens::Jogador();

			listaEnts.incluir(pJog1);

			if (pGC != NULL)
			{
				pGC->setJogador(pJog1);
			}
			criarInimFacil();
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