#include "Jogo.h"
#include "Ente.h"
#include "GerenciadorGrafico.h"
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <ctime>

namespace Trabalhojogo {

	Jogo::Jogo() :
		pGG(NULL),
        pJog1(NULL)
	{
		pGG = new Gerenciadores::GerenciadorGrafico();
		Ente::setGG(pGG);
        pJog1 = new Entidades::Personagens::Jogador();
	}
	Jogo::~Jogo()
	{
		delete pGG;
        delete pJog1;
	}
    void Jogo::executar()
    {
        sf::RenderWindow& janela = pGG->getJanela();

        while (janela.isOpen())
        {
            sf::Event evento;

            while (janela.pollEvent(evento))
            {
                if (evento.type == sf::Event::Closed)
                    janela.close();
            }

            pJog1->executar();
            janela.clear(sf::Color::Black);
            pGG->desenharEnte(pJog1);
            janela.display();
        }
    }
}