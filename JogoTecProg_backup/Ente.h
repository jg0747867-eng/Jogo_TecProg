#pragma once

#ifndef ENTE_H_
#define	ENTE_H_

#include <iostream>
#include "SFML/Graphics.hpp"

namespace Trabalhojogo {
    namespace Gerenciadores {
        class GerenciadorGrafico;
    }
    class Ente
    {
    protected:
        int id;
        static Gerenciadores::GerenciadorGrafico* pGG;
        sf::RectangleShape body;

    public:
        Ente();
        virtual ~Ente();

        virtual void executar() = 0;
        void desenhar();

        static void setGG(Gerenciadores::GerenciadorGrafico* pG);

        sf::RectangleShape& getBody();
        const sf::RectangleShape& getBody() const;
    };
}




#endif