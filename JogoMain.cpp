#include "Jogo.h"

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    IlhaDosPiratas::Jogo jogo;
    jogo.executar();

    return 0;

}