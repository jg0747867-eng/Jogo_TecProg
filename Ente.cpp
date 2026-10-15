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

        // desenharEnte(this); não sei se é isso mesmo e a funcao nao ta feita ainda
        // deixei comentado pois tava dando erro. Acho que o uso do this faz sentido...
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
