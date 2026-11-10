#pragma once

#ifndef GERENCIADOR_GRAFICO_H_
#define GERENCIADOR_GRAFICO_H_
#include <SFML/Graphics.hpp>

namespace IlhaDosPiratas
{
	class Ente;

	namespace Gerenciadores
	{
		class GerenciadorGrafico
		{
			private:
				sf::RenderWindow obj;
			public:
				GerenciadorGrafico();
				~GerenciadorGrafico();

				bool janelaAberta() const;
				void fecharJanela();

				void desenharEnte(Ente* pE);
				void mostrar();

				sf::RenderWindow& getJanela();

		};
	}
}

#endif
