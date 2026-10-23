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