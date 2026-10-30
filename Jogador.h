#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "Personagem.h"
namespace Trabalhojogo {
    namespace Entidades {
        namespace Personagens{

            class Jogador : public Personagem
            {
            protected:
                int pontos;
                int direcao;

            private:
                sf::Vector2f vel;
                int id;
                sf::Keyboard::Key teclaEsq;
                sf::Keyboard::Key teclaDir; 
                sf::Keyboard::Key teclaPulo; 

            public:
                Jogador(int id);

                ~Jogador();

                int getID() const {return id;}

                // void colidir (Inimigo* pIn);

                void executar();
                void mover();
                void inicializa();
                void salvar();
                void pular();

            };
        }
    }
}


#endif
