#include "Ente.h"
#include "GerenciadorGrafico.h"
namespace Trabalhojogo {

    Gerenciadores::GerenciadorGrafico* Ente::pGG = NULL;

    Ente::Ente() : id(0), body(sf::Vector2f(100.f, 100.f))
    {
    }

    Ente::~Ente()
    {
    }

    void Ente::setGG(Gerenciadores::GerenciadorGrafico* pG)
    {
        pGG = pG;
    }

    void Ente::desenhar()
    {
        if (pGG != NULL)
        {
            pGG->desenharEnte(this);
        }
    }
    sf::RectangleShape& Ente::getBody()
    {
        return body;
    }
    const sf::RectangleShape& Ente::getBody() const
    {
        return body;
    }
}
