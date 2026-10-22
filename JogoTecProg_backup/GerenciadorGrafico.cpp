#include "GerenciadorGrafico.h"
#include "Ente.h"

#include "SFML/Graphics.hpp"

namespace Trabalhojogo {
	namespace Gerenciadores {
		GerenciadorGrafico::GerenciadorGrafico() : obj(sf::VideoMode(1920, 1080), "TrabalhoJogo++") 
		{
			obj.setFramerateLimit(60);
		}
		GerenciadorGrafico::~GerenciadorGrafico() {
			if (obj.isOpen())
			{
				obj.close();
			}
		}
		bool GerenciadorGrafico::janelaAberta() const {
			return obj.isOpen();
		}
		void GerenciadorGrafico::fecharJanela() {
			obj.close();
		}
		sf::RenderWindow& GerenciadorGrafico::getJanela() {
			return obj;
		}
		void GerenciadorGrafico::desenharEnte(Ente* pE) {
			if (pE != NULL)
			{
				obj.draw(pE->getBody());
			}
		}
		void GerenciadorGrafico::mostrar() {
			obj.display();
		}
	}
}

