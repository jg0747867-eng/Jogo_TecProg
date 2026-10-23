#pragma once

#ifndef JOGO_H_
#define JOGO_H_

#include "Jogador.h"
#include "GerenciadorGrafico.h"

namespace Trabalhojogo {
	namespace Fases {
		class FasePrimeira;
	}
	class Jogo
	{
		private:
			//Entidades::Personagens::Jogador* pJog1; Emprementar o resto depois
			Gerenciadores::GerenciadorGrafico* pGG;
			sf::RenderWindow window;
			Entidades::Personagens::Jogador* pJog1;
			Fases::FasePrimeira* pFase;

		public:
			Jogo();
			~Jogo();

			void executar();
	};
}

#endif
