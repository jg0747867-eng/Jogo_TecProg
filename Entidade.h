#ifndef ENTIDADE_H_
#define ENTIDADE_H_

#include "Ente.h"
using namespace Trabalhojogo;

namespace Entidades
{
    class Entidade: public Ente
    {
    protected:
        int x;
        int y;
        // ostream buffer (como a gente conversou n�o sei direito o que �)

    public:
        Entidade();
        virtual ~Entidade();
        virtual void executar() = 0;
        virtual void salvar() = 0;

        //protected:
            // void salvarDataBuffer();
    };
}

#endif