#include "Jogador.h"
#include "FaseSegunda.h"
#include "Espinho.h"
#include "Osso.h"

#include <iostream>

#include "GerenciadorGrafico.h"

namespace Tripulacao_Amaldicoada {
    namespace Fases {

        FaseSegunda::FaseSegunda(
            int quantidadeJogadores,
            Entidades::Personagens::Jogador* pJog1,
            Entidades::Personagens::Jogador* pJog2
        ) :
            Fase(quantidadeJogadores, pJog1, pJog2),
            maxEspinhos(5), maxEsqueletos(5)
        {
            carregaFundo("assets/cenario2.jpeg");
            criarCenario();
        }

        FaseSegunda::~FaseSegunda()
        {
        }

        void FaseSegunda::criarInimigos()
        {
            criarFantasmas();
            criarEsqueletos();
        }

        void FaseSegunda::criarObstaculos()
        {
            criarEspinhos();
            criarPlataformas();
        }

        void FaseSegunda::carregaFundo(const std::string& caminho)
        {
            if (!texturaFundo.loadFromFile(caminho))
            {
                std::cout << "Erro ao carregar fundo: "
                    << caminho << std::endl;
                return;
            }

            fundo.setTexture(texturaFundo);

            sf::Vector2u tamTextura = texturaFundo.getSize();
            sf::Vector2u tamJanela = pGG->getJanela().getSize();

            fundo.setScale(
                static_cast<float>(tamJanela.x) / tamTextura.x,
                static_cast<float>(tamJanela.y) / tamTextura.y
            );
        }

        void FaseSegunda::criarEspinhos()
        {
            int quantidade = gerarQuantidadeAleatoria(maxEspinhos);

            int posicoes[5][2] =
            {
                {310, 740},
                {650, 920},
                {1000, 490},
                {1390, 660},
                {650, 630}
             
            };

            for (int i = 0; i < quantidade; i++)
            {
                Entidades::Obstaculos::Espinho* pEspinho =
                    new Entidades::Obstaculos::Espinho();

                pEspinho->setPosicao(
                    posicoes[i][0],
                    posicoes[i][1]
                );

                listaEnts.incluir(pEspinho);

                if (pGC != NULL)
                {
                    pGC->incluirObstaculo(pEspinho);
                }
            }
        }


        void FaseSegunda::criarProjeteis(Entidades::Personagens::Esqueleto* pEsqueleto)
        {
            if (pEsqueleto == NULL)
            {
                return;
            }

            Entidades::Osso* pOsso = new Entidades::Osso(3);

            pEsqueleto->setOsso(pOsso);
            listaEnts.incluir(pOsso);

            if(pGC != NULL)
            {
                pGC->incluirProjetil(pOsso);
            }

        }

        void FaseSegunda::criarEsqueletos()
        {
            int quantidade = gerarQuantidadeAleatoria(maxEsqueletos);

			int posicoes[5][2] = 
			{
				{600, 800},
				{830, 800},
				{1240, 800},
				{1600, 800},
				{1700, 800}
			};

            for(int i = 0; i < quantidade; i++)
            {
                Entidades::Personagens::Esqueleto* pEsqueleto =
                new Entidades::Personagens::Esqueleto(pJog1);

                pEsqueleto->setPosicao(
                posicoes[i][0],
                posicoes[i][1]
                );

                listaEnts.incluir(pEsqueleto);

                if(pGC != NULL)
                {
                    pGC->incluirInimigo(pEsqueleto);
                }

                criarProjeteis(pEsqueleto);
                inimigosVivos++;
            }
        }

        bool FaseSegunda::jogadorVivo() const
        {
            return (pJog1 != NULL && pJog1->estaAtivo()) ||
                (pJog2 != NULL && pJog2->estaAtivo());
        }

    }
}
