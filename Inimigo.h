#ifndef INIMIGO_H_
#define INIMIGO_H_

#include "Personagem.h"


class Jogador;
namespace Personagens
{
    class Inimigo: public Personagem
    {
        protected:
            int nivel_maldade;


        public:
            Inimigo();

            ~Inimigo();

            // void salvarDataBuffer();

            virtual void executar() = 0;
            virtual void danificar(Jogador* pJo) = 0;

            virtual void salvar() = 0; 


    };
}

#endif
