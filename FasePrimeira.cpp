#include "FasePrimeira.h"
#include "InimMedio.h"
#include "ObstMedio.h"
#include "Jogador.h"
#include <iostream>
#include "GerenciadorGrafico.h"

namespace IlhaDosPiratas{
	namespace Fases {
		FasePrimeira::FasePrimeira(int quantidadeJogadores, 
			Entidades::Personagens::Jogador* pJog1,
			Entidades::Personagens::Jogador* pJog2):
			Fase(quantidadeJogadores, pJog1, pJog2),
			maxInimMedio(10),
			maxObsMedio(10)
		{
			carregaFundo("assets/cenario1.jpg");
			criarCenario();
		}
		FasePrimeira::~FasePrimeira() {}

		void FasePrimeira::criarInimigos()
		{
			criarInimMedio();
		}
		void FasePrimeira::criarObstaculos()
		{
			criarObsMedio();
		}

		void FasePrimeira::carregaFundo(const std::string& caminho)
		{
			if (!texturaFundo.loadFromFile(caminho)) {
				std::cout << "Erro ao carregar fundo: " << caminho << std::endl;
				return;
			}

			fundo.setTexture(texturaFundo);

			sf::Vector2u tamTextura = texturaFundo.getSize();
			sf::Vector2u tamJanela = pGG->getJanela().getSize();

			fundo.setScale(
				static_cast<float>(tamJanela.x) / tamTextura.x,
				static_cast<float>(tamJanela.y) / tamTextura.y
			);
		}
		void FasePrimeira::criarInimMedio()
		{

		}
		void FasePrimeira::criarObsMedio()
		{

		}
		bool FasePrimeira::jogadorVivo() const {
			return (pJog1 != NULL && pJog1->estaAtivo()) ||
				   (pJog2 != NULL && pJog2->estaAtivo());
		}
	}
}