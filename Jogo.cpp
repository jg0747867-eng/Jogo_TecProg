
#include "Jogo.h"
#include "Ente.h"
#include <SFML/Graphics.hpp>

namespace Trabalhojogo {

    Jogo::Jogo() :
        pGG(new Gerenciadores::GerenciadorGrafico()),
        pFase(nullptr)
    {
        Ente::setGG(pGG);

        // O construtor da FasePrimeira já chama criarCenario().
        pFase = new Fases::FasePrimeira();
    }

    Jogo::~Jogo()
    {
        delete pFase;
        pFase = nullptr;

        delete pGG;
        pGG = nullptr;
    }

    void Jogo::executar()
    {
        if (pGG == nullptr || pFase == nullptr) {
            return;
        }

        // getJanela() retorna uma referência, não um ponteiro.
        sf::RenderWindow& janela = pGG->getJanela();

        while (janela.isOpen()) {
            sf::Event evento;

            while (janela.pollEvent(evento)) {
                if (evento.type == sf::Event::Closed) {
                    janela.close();
                }
            }

            if (!janela.isOpen()) {
                break;
            }

            janela.clear(sf::Color::Black);

            pFase->executar();

            pGG->mostrar();
        }
    }
}
