#include "Entidade.h"

namespace Trabalhojogo {
    namespace Entidades {
        Entidade::Entidade() :
            x(0),
            y(0),
            velocidadeY(0),
            noChao(false),
            ativo(true) {}// nao sei se a gente inicia o x e o y em 0, qualquer coisa alteramos depois

        Entidade::~Entidade() {}

        void Entidade::setPosicao(int x, int y) {
            this->x = x;
            this->y = y;

            body.setPosition(static_cast<float>(this->x), static_cast<float>(this->y));
        }
        int Entidade::getX() const {
            return x;
        }
        int Entidade::getY() const {
            return y;
        }
        int Entidade::getVelocidadeY() const {
            return velocidadeY;
        }
        void Entidade::zerarVelocidadeY() {
            velocidadeY = 0;
        }
        void Entidade::setNoChao(bool estado) {
            noChao = estado;
        }
        void Entidade::aplicarGravidade()
        {
            if (noChao && velocidadeY >= 0)
            {
                velocidadeY = 0;
                return;
            }

            const int gravidade = 1;
            const int velocidadeMaxima = 20;

            velocidadeY += gravidade;

            if (velocidadeY > velocidadeMaxima)
            {
                velocidadeY = velocidadeMaxima;
            }

            setPosicao(getX(), getY() + velocidadeY);
        }
        void Entidade::ativar() {
            ativo = true;
        }

        void Entidade::desativar() {
            ativo = false;
            setPosicao(-1000, -1000);
        }

        bool Entidade::estaAtivo() const {
            return ativo;
        }
        /*
        void Entidade::salvarDataBuffer();
        */
    }
}
