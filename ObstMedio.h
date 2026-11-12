#pragma once

#ifndef OBST_MEDIO_H_
#define OBST_MEDIO_H_

#include "Obstaculo.h"


namespace IlhaDosPiratas {
	namespace Entidades {
		namespace Obstaculos {

			class ObstMedio : public Obstaculo
			{
			private:

				bool baseDefinida;

				int baseY;
				int empuxo;

			public:
				ObstMedio();
				~ObstMedio();

				void executar();
				void salvar();

				void obstaculizar(IlhaDosPiratas::Entidades::Personagens::Jogador* pJogador);

				virtual void aplicarEmpuxo();
			};
		}
	}
}

#endif
