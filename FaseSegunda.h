#ifndef FASE_SEGUNDA_H_
#define FASE_SEGUNDA_H_

#include "Fase.h"
class Jogador;

namespace Tripulacao_Amaldicoada {
    namespace Fases {

        class FaseSegunda : public Fase
        {
        private:
            const int maxEspinhos;
            const int maxEsqueletos;

        public:
            FaseSegunda(int quantidadeJogadores, Entidades::Personagens::Jogador* pJog1,
                Entidades::Personagens::Jogador* pJog2
            );

            ~FaseSegunda();

            virtual bool jogadorVivo() const;

        protected:
            virtual void criarInimigos();
            virtual void criarObstaculos();

            void criarEspinhos();
            void criarEsqueletos();

            void carregaFundo(const std::string& caminho);
        };
    }
}

#endif
