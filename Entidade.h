#ifndef ENTIDADE_H_
#define ENTIDADE_H_

#include "Ente.h"

namespace Trabalhojogo {
    namespace Entidades
    {
        class Entidade : public Ente
        {
        protected:
            int x;
            int y;

            int velocidadeY;
            bool noChao;

            bool ativo;
            // ostream buffer (como a gente conversou n�o sei direito o que �)

        public:
            Entidade();
            virtual ~Entidade();
            virtual void executar() = 0;
            virtual void salvar() = 0;

            void setPosicao(int x, int y);
            int getX() const;
            int getY() const;

            virtual void aplicarGravidade();

            int getVelocidadeY() const;
            void zerarVelocidadeY();

            void setNoChao(bool estado);

            void ativar();
            void desativar();
            bool estaAtivo() const;

            //protected:
                // void salvarDataBuffer();
        };
    }
}


#endif