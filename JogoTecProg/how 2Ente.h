[1mdiff --cc Ente.h[m
[1mindex c60ab74,b78e304..0000000[m
[1m--- a/Ente.h[m
[1m+++ b/Ente.h[m
[36m@@@ -3,27 -3,27 +3,9 @@@[m
  #ifndef ENTE_H_[m
  #define	ENTE_H_[m
  [m
[31m--#include <iostream>[m
[31m--[m
[31m--[m
[31m--class Gerenciador_Grafico;[m
[31m--class Figura;[m
[31m--[m
  class Ente[m
  {[m
[31m- protected:[m
[31m-     int id;[m
[31m-     static Gerenciador_Grafico* pGG;[m
[31m-     Figura* pFig;[m
[31m -    protected:[m
[31m -        int id;[m
[31m -        static Gerenciador_Grafico* pGG;[m
[31m -        Figura* pFig;[m
[31m--[m
[31m- public:[m
[31m-     Ente();[m
[31m-     virtual ~Ente();[m
[31m-     virtual void executar() = 0;[m
[31m-     void desenhar();[m
[31m-     static void setGG(Gerenciador_Grafico* pG);[m
[31m -    public:[m
[31m -        Ente();[m
[31m -        virtual ~Ente();[m
[31m -        virtual void executar() = 0;[m
[31m -        void desenhar();[m
[31m -        static void setGG(Gerenciador_Grafico* pG);[m
  [m
  };[m
  [m
[31m--[m
[31m- #endif[m
[32m+ #endif[m
