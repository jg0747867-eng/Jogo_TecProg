#ifndef JOGADOR_H_
#define JOGADOR_H_
#include "Personagem.h"

namespace Tripulacao_Amaldicoada {
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

                sf::Font fontePontos;
                sf::Text textoPontos;
                sf::Text textoVida;

            public:
                Jogador(int id);

                ~Jogador();

                int getID() const {return id;}

                int getPontos() const {return pontos;}

                // void colidir (Inimigo* pIn);

                void operator--();
                
                void operator++(int nivel_maldade);

                const int getVida() const {return num_vidas;}

                void executar();
                void mover();
                void inicializa();
                void salvar();
                
                void setLento(bool estado) { lento = estado; }

                bool receberDano(int dano);
                void aplicarVeneno();
                void atualizarVeneno();
                void desenharPontos(sf::RenderWindow& janela, float x, float y);

            };
        }
    }
}


#endif
