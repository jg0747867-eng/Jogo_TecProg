#include "Jogo.h"

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    Tripulação_Amaldiçoada::Jogo jogo;
    jogo.executar();

    return 0;

}