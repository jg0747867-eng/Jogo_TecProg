#include "Inimigo.h"

namespace Tripulacao_Amaldicoada {
	namespace Entidades {
		namespace Personagens {

			Inimigo::Inimigo() : 
				Personagem(), 
				nivel_maldade(0),
				vel(0.0f, 0.0f)
			{
				num_vidas = 1;
			}

			Inimigo::~Inimigo()
			{

			}

			/*
			void Inimigo::salvarDataBuffer();
			*/

			bool Inimigo::receberDano(int dano)
			{
				if (!estaAtivo() || dano <= 0)
					return false;

				num_vidas -= dano;

				if (num_vidas <= 0)
				{
					desativar();
				}

				return true;
			}
		}
	}
}



