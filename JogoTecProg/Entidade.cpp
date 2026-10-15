#include "Entidade.h"

Entidade::Entidade() : x(0), y(0) // nao sei se a gente inicia o x e o y em 0, qualquer coisa alteramos depois
{
}

Entidade::~Entidade()
{
    x = -1;
    y = -1;
}

/*
void Entidade::salvarDataBuffer();
*/