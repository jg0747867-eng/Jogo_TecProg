#include "Jogo.h"

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    Tripulacao_Amaldicoada::Jogo jogo;
    jogo.executar();

    return 0;

}