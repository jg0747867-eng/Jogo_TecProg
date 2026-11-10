#ifndef FASE_H_
#define FASE_H_

#include "Ente.h"
#include "ListaEntidade.h"
#include "GerenciadorColisoes.h"

namespace IlhaDosPiratas {
		namespace Entidades {
			namespace Personagesn {
				class Jogador;
			}
		}
		namespace Gerenciadores 
		{
			class GerenciadorColisoes;
			class GerenciadorGrafico;
		}
		namespace Fases {
			class Fase : public Ente
			{
			protected:
				Listas::ListaEntidades listaEnts;
				Gerenciadores::GerenciadorColisoes* pGC;
				Entidades::Personagens::Jogador* pJog1;
				Entidades::Personagens::Jogador* pJog2;

				sf::Texture texturaFundo;
				sf::Sprite fundo;

				int limiteChao;

				const int maxFantasmas;
				const int maxPlataformas;

			public:
				Fase(int quantidadeJogadores);
				~Fase();

				virtual void executar();
				virtual bool jogadorVivo() const = 0;
				bool acabou() const;
			protected:
				void criarFantasmas();
				void criarPlataformas();
				void criarCenario();

				int inimigosVivos;
				bool faseConcluida;
				int quantidadeJogadores;
				virtual void criarInimigos() = 0;
				virtual void criarObstaculos() = 0;

				int gerarQuantidadeAleatoria(const int maximo) const;
			};
		}
}

#endif
