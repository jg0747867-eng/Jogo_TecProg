#ifndef JOGADOR_H_
#define JOGADOR_H_
#include "Personagem.h"

namespace Tripulação_Maldita {
    namespace Entidades {
        namespace Personagens{

            class Jogador: public Personagem
            {
            protected:
                int pontos;
                int direcao;

            private:
                sf::Vector2f vel;
                sf::Clock relogioInvulneravel;
                int id;
                int vida;
                bool lento;
                bool invulneravel;
                sf::Keyboard::Key teclaEsq;
                sf::Keyboard::Key teclaDir; 
                sf::Keyboard::Key teclaPulo; 

                bool envenenado;
                sf::Clock relogioVeneno;
                sf::Clock relogioDanoVeneno;

                sf::Clock relogioVermelho;
                bool vermelho;

            public:
                Jogador(int id);

                ~Jogador();

                int getID() const {return id;}

                // void colidir (Inimigo* pIn);

                void operator--();
                
                void operator++(){pontos++;}

                const int getVida() const {return vida;}

                void executar();
                void mover();
                void inicializa();
                void salvar();
                
                void setLento(bool estado) { lento = estado; }

                bool receberDano(int dano);
                void aplicarVeneno();
                void atualizarVeneno();

            };
        }
    }
}


#endif

