#pragma once

#ifndef PLATAFORMA_H_
#define PLATAFORMA_H_

#include "Obstaculo.h"

namespace Trabalhojogo {
	namespace Entidades {
		namespace Personagens {
			class Jogador;
		}
		namespace Obstaculos {

			class Plataforma : public Obstaculo
			{
			private:
				int altura;
				int baseY;

			public:
				Plataforma();
				Plataforma(int x, int y, int largura, int altura);
				~Plataforma();

				void executar();
				void obstaculizar(Trabalhojogo::Entidades::Personagens::Jogador* pJogador);

				virtual void seguraPlat();

				virtual void salvar();
			};
		}
	}
}


#endif
