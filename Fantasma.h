
#ifndef INIM_FACIL_H_
#define INIM_FACIL_H_
#include "Inimigo.h"


#define RAIO_PERSEGUIR_X 200.0f

#define RAIO_PERSEGUIR_Y 200.0f

class Jogador;

namespace IlhaDosPiratas {
    namespace Entidades {
        namespace Personagens
        {
            class Fantasma : public Inimigo
            {
                private:
                    IlhaDosPiratas::Entidades::Personagens::Jogador* jogador;
                    sf::Clock relogio;
                    short moveAleatorio;
                    void inicializa();
                    void movimentoAleatorio();
                public:
                    Fantasma(Jogador* pJogador);

                    ~Fantasma();

                    bool ehVoador() const {return true;}


                    void danificar(Jogador* pJogador);
                    void salvar();
                    void executar();
                    void mover();
                    void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                    void aplicarEmpuxo();
                    
            };
        }
    }
}

#endif

