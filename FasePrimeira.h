#pragma once

#ifndef FASE_PRIMEIRA_H_
#define FASE_PRIMEIRA_H_

#include "Fase.h"

namespace IlhaDosPiratas {
	namespace Fases {
		class FasePrimeira : public Fase
		{
		private:
			const int maxInimMedio;
			const int maxObsMedio;
		public:
			FasePrimeira(int quantidadeJogadores, Entidades::Personagens::Jogador* pJog1,
					Entidades::Personagens::Jogador* pJog2);
			~FasePrimeira();

			virtual bool jogadorVivo() const;
		protected:
			virtual void criarInimigos();
			virtual void criarObstaculos();

			void criarInimMedio();
			void criarObsMedio();

			void carregaFundo(const std::string& caminho);

			int quantidadeJogadores;
		};
	}
}
	
class FasePrimeira
{

};

#endif
