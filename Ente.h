#pragma once

#ifndef ENTE_H_
#define	ENTE_H_

#include <iostream>


class Gerenciador_Grafico;
class Figura;

class Ente
{
protected:
    int id;
    static Gerenciador_Grafico* pGG;
    Figura* pFig;

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void desenhar();
    static void setGG(Gerenciador_Grafico* pG);

};


#endif