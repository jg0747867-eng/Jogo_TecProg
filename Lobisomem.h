#ifndef INIM_MEDIO_H_
#define INIM_MEDIO_H_

#include "Inimigo.h"


namespace IlhaDosPiratas
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Lobisomem : public Inimigo
            {
                private:
                    IlhaDosPiratas::Entidades::Personagens::Jogador* jogador;
                    sf::Clock relogioPatrulha;
                    sf::Clock relogioPulo;
                    float intervaloPulo;
                    short direcaoPatrulha;
                    void inicializa();
                    void patrulhar();
                    void pulosAleatorios();
                public:
                    Lobisomem(Jogador* pJogador);

                    ~Lobisomem();

                    bool ehVoador() const {return false;}

                    void danificar(Jogador* pJogador);
                    void salvar();
                    void executar();
                    void mover();
                    void pular() override;
            };  
        }      
    }
}


#endif
