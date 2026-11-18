#include "Osso.h"
#include "Jogador.h"
#include <cmath>

#define VELOCIDADE_ESCALAR 18.0f
#define GRAVIDADE 0.45f
#define PI 3.14159265f

namespace IlhaDosPiratas
{
    namespace Entidades
    {
        Osso::Osso(int dano):
            Entidade(),
            posX(0.0f),
            posY(0.0f),
            velX(0.0f),
            velY(0.0f),
            gravidade(GRAVIDADE),
            dano(dano)
        {
            inicializa();
            desativar();
        }

        Osso::~Osso()
        {

        }

        void Osso::inicializa()
        {
            body.setSize(sf::Vector2f(36.0f, 14.0f));
            body.setFillColor(sf::Color::White);
            // carregarTextura();
        }

        void Osso::calcularTrajetoria(float alvoX, float alvoY, float v0)
        {
            float deltaX = alvoX - posX;
            float deltaY = alvoY - posY;

            int direcao = (deltaX >= 0.0f) ? 1 : -1;
            float dx = std::fabs(deltaX);

            if(dx < 1.0f)
            {
                velX = 0.0f;
                velY = (deltaY < 0.0f) ? -v0 : v0;
                return;
            }

            float A =  (gravidade * dx * dx) / (2.0f * v0 * v0);
            float B = dx;
            float C = A - deltaY;

            float discriminante = (B * B) - (4.0f * A * C);
            float theta = 0.0f;

            if(discriminante >= 0.0f)
            {
                float tanTheta = (-B + std::sqrt(discriminante)) / (2.0f * A);
                theta = std::atan(tanTheta);
            }
            else
            {
                theta = -PI / 4.0f;
            }

            velX = direcao * v0 * std::cos(theta);
            velY = v0 * std::sin(theta);
        }


        void Osso::mover()
        {
            posX += velX;
            posY += velY + 0.5f * gravidade;
            velY += gravidade;

            setPosicao(static_cast<int>(posX), static_cast<int>(posY));

            float anguloGraus = std::atan2(velY, velX) * (180.0f / PI);
            body.setRotation(anguloGraus);

            if(posX < -100.0f || posX > 2020.0f || posY > 1150.0f)
            {
                desativar();
            }
        }

        void Osso::executar()
        {
            if(!estaAtivo())
            {
                return;
            }

            mover();
        }

        void Osso::disparar(float origemX, float origemY, float alvoX, float alvoY)
        {
            posX = origemX;
            posY = origemY;
            setPosicao(static_cast<int>(posX), static_cast<int>(posY));
            calcularTrajetoria(alvoX, alvoY, VELOCIDADE_ESCALAR);
            ativar();
        }

        void Osso::danificar(Personagens::Jogador* pJogador)
        {
            if(pJogador != NULL && pJogador->getVida() > 0)
            {
                pJogador->receberDano(dano);
                desativar();
            }
        }

        void Osso::salvar()
        {

        }


    }
}
