#include "Ente.h"

Ente::Ente() : id(0), pFig(NULL)
{
}

Ente::~Ente()
{
    pFig = NULL;
}

void Ente::setGG(Gerenciador_Grafico* pG)
{
    pGG = pG;
}

void Ente::desenhar()
{
    // desenharEnte(this); não sei se é isso mesmo e a funcao nao ta feita ainda
    // deixei comentado pois tava dando erro. Acho que o uso do this faz sentido...
}