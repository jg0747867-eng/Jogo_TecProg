#include "Personagem.h"
namespace Tripulação_Amaldiçoada {
    namespace Entidades {
        namespace Personagens {
            Personagem::Personagem() : Entidade(), num_vidas(1)
            {
            }

            Personagem::~Personagem()
            {
                num_vidas = 0;
            }

            /*
            void Personagem::salvarDataBuffer()
            {
            }
            */
        }
    }
}


