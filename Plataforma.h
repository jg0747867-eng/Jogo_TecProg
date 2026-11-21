#pragma once

#ifndef PLATAFORMA_H_
#define PLATAFORMA_H_

#include "Obstaculo.h"

namespace Tripulacao_Amaldicoada {
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
				int limiteY;

				bool caindo;
				bool subindo;

				float espera;
				sf::Clock relogio;

			public:
				Plataforma();
				Plataforma(int x, int y, int largura, int altura);
				~Plataforma();

				void executar();
				void obstaculizar(Tripulacao_Amaldicoada::Entidades::Personagens::Jogador* pJogador);

				virtual void seguraPlat();

				virtual void salvar();
			};
		}
	}
}


#endif
