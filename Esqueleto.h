#ifndef ESQUELETO_H_
#define ESQUELETO_H_

#include "Inimigo.h"


namespace Tripulacao_Amaldicoada
{
    namespace Entidades
    {
        class Osso;

        namespace Personagens
        {
            class Jogador;

            class Esqueleto: public Inimigo
            {
                private:
                    Tripulacao_Amaldicoada::Entidades::Personagens::Jogador* jogador;
                    Osso* pOsso;
                    sf::Clock lancarProjetil;
                    sf::Clock relogioPulo;
                    float intervaloPulo;
                    void inicializa();
                    void pulosAleatorios();                 
                    bool pulando;
                public:
                    Esqueleto(Jogador* pJogador, Osso* pO = NULL);

                    ~Esqueleto();
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