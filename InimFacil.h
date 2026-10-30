
#ifndef INIM_FACIL_H_
#define INIM_FACIL_H_
#include "Inimigo.h"


#define RAIO_PERSEGUIR_X 200.0f

#define RAIO_PERSEGUIR_Y 200.0f

class Jogador;

namespace Trabalhojogo {
    namespace Entidades {
        namespace Personagens
        {
            class InimFacil : public Inimigo
            {
                private:
                    Trabalhojogo::Entidades::Personagens::Jogador* jogador;
                    sf::Clock relogio;
                    short moveAleatorio;
                    void inicializa();
                public:
                    InimFacil(Jogador* pJogador);

                    ~InimFacil();

                    void executar();

                    void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                    void movimentoAleatorio();
                    void move();
            };
        }
    }
}

#endif
