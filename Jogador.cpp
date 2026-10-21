#include "Jogador.h"

using namespace Personagens;

Jogador::Jogador(): Personagem(), vel(sf::Vector2(0.0f, 0.0f)), pontos(0)
{
    inicializa();
}

Jogador::~Jogador()
{    
}

void Jogador::inicializa()
{
    pontos = 0;
    body.setSize(sf::Vector2f(150.0f, 150.0f));
    body.setFillColor(sf::Color::Blue);
    vel = sf::Vector2f(8.0f, 8.0f);
}

void Jogador::mover()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        body.move(-vel.x, 0.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        body.move(vel.x, 0.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        body.move(0.0f, vel.y);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        body.move(0.0f, -vel.y);
    }
}

void Jogador::executar()
{
    inicializa();
    mover();
}


void Jogador::salvar()
{

}

