#pragma once

#ifndef ENTIDADE_H_
#define ENTIDADE_H_

class Entidade
{
protected:
    int x;
    int y;
    // ostream buffer (como a gente conversou não sei direito o que é)

public:
    Entidade();
    virtual ~Entidade();
    virtual void executar() = 0;
    virtual void salvar() = 0;

    //protected:
        // void salvarDataBuffer();
};

#endif