#ifndef Osso_H_
#define Osso_H_

#include "Entidade.h"



namespace IlhaDosPiratas
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Jogador;
        }

        class Osso: public Entidade
        {
            private:
                float posX;
                float posY;
                float velX;
                float velY;
                float gravidade;
                int dano;
                void inicializa();
                void calcularTrajetoria(float alvoX, float alvoY, float v0);

            public:
                Osso(int dano = 3);

                ~Osso();

                void mover();
                void disparar(float origemX, float origemY, float alvoX, float alvoY);
                void executar();
                void salvar();
                void danificar(Personagens::Jogador* pJogador);
        };
    }
}
#endif
