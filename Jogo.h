#pragma once

#ifndef JOGO_H_
#define JOGO_H_

#include "Jogador.h"
#include "GerenciadorGrafico.h"

namespace Trabalhojogo {

	class Jogo
	{
		private:
			//Entidades::Personagens::Jogador* pJog1; Emprementar o resto depois
			Gerenciadores::GerenciadorGrafico* pGG;
			sf::RenderWindow window;

		public:
			Jogo();
			~Jogo();

			void executar();
	};
}

#endif
