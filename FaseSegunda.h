
#pragma once

#ifndef FASE_SEGUNDA_H_
#define FASE_SEGUNDA_H_

#include "Fase.h"

namespace IlhaDosPiratas {
    namespace Fases {

        class FaseSegunda : public Fase
        {
        private:
            const int maxEspinhos;

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

            void carregaFundo(const std::string& caminho);
        };
    }
}

#endif
