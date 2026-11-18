#ifndef MANSAO_H_
#define MANSAO_H_

#include "Fase.h"

namespace Tripulacao_Amaldicoada {
	namespace Fases {
		class Mansao : public Fase
		{
		private:
			const int maxInimMedio;
			const int maxObsMedio;
		public:
			Mansao(int quantidadeJogadores, Entidades::Personagens::Jogador* pJog1,
					Entidades::Personagens::Jogador* pJog2);
			~Mansao();

			virtual bool jogadorVivo() const;

		protected:
			virtual void criarInimigos();
			virtual void criarObstaculos();

			void criarInimMedio();
			void criarObsMedio();

			void carregaFundo(const std::string& caminho);

		};
	}
}

#endif
