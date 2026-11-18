#ifndef TEIA_H_
#define TEIA_H_

#include "Obstaculo.h"


namespace Tripulacao_Amaldicoada {
	namespace Entidades {
		namespace Obstaculos {

			class Teia : public Obstaculo
			{
			private:

				bool baseDefinida;

				int baseY;
				int empuxo;

			public:
				Teia();
				~Teia();

				void executar();
				void salvar();

				void obstaculizar(Tripulacao_Amaldicoada::Entidades::Personagens::Jogador* pJogador);

				virtual void aplicarEmpuxo();
			};
		}
	}
}

#endif
