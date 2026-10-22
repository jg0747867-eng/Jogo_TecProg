#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "Personagem.h"
namespace Trabalhojogo {
    namespace Entidades {
        namespace Personagens
        {
            class Jogador : public Personagem
            {
            protected:
                int pontos;

            private:
                sf::Vector2f vel;

            public:
                Jogador();

                ~Jogador();

                // void colidir (Inimigo* pIn);

                void executar();
                void mover();
                void inicializa();
                void salvar();

            };
        }
    }
}


#endif
