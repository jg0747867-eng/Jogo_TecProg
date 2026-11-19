#ifndef INIMIGO_H_
#define INIMIGO_H_

#include "Personagem.h"


namespace Tripulacao_Amaldicoada {
    namespace Entidades {
        namespace Personagens
        {
            class Jogador;
            class Inimigo : public Personagem
            {
            protected:
                int nivel_maldade;
                sf::Vector2f vel;


            public:
                Inimigo();

                ~Inimigo();

                // void salvarDataBuffer();

                int getNivelMaldade() const {return nivel_maldade;}
                virtual bool ehVoador() const {return false;}

                virtual void executar() = 0;
                virtual void danificar(Jogador* pJo) = 0;
                bool receberDano(int dano);

                //virtual void salvar() = 0;


            };
        }
    }
}

#endif