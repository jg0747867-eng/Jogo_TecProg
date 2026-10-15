#include "Jogo.h"
#include "Ente.h"
#include "GerenciadorGrafico.h"
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <ctime>

namespace Trabalhojogo {

	Jogo::Jogo() :
		pGG(NULL)
	{
		pGG = new Gerenciadores::GerenciadorGrafico();
		Ente::setGG(pGG);
	}
	Jogo::~Jogo()
	{
		delete pGG;
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

            janela.clear(sf::Color::Black);
            janela.display();
        }
    }
}