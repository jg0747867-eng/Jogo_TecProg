#pragma once

#ifndef FASE_PRIMEIRA_H_
#define FASE_PRIMEIRA_H_

#include "Fase.h"

namespace Trabalhojogo {
	namespace Fases {
		class FasePrimeira : public Fase
		{
		private:
			const int maxInimMedio;
			const int maxObsMedio;
		public:
			FasePrimeira();
			~FasePrimeira();

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
	
class FasePrimeira
{

};

#endif
