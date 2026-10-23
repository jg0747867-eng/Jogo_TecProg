#ifndef LISTA_ENTIDADE_H_
#define LISTA_ENTIDADE_H_
#include "Lista.h"
#include "Entidade.h"
#include "iostream"
/* 
 * Ressalto novamente meu agradecimento aos colegas do PETECO,
 * Raphael Geraldine e Marco Vendramin, e também ao Burda, 
 * visto que nossa implementação foi baseada na deles.
 * 
 * Vide: 
 * https://github.com/Raphael-Geraldine/O-Equilibrio-da-Forca/blob/master/include/Lista.h  
 * e vídeo 8 da playlist Tutorial Jogo SFML.
 */




namespace Trabalhojogo
{
    namespace Listas
    {
        class ListaEntidades: public Lista<Entidades::Entidade>
        {
            private:
                Lista<Entidades::Entidade> LEs;
            
            public:
                ListaEntidades();

                ~ListaEntidades();

                void incluir(Entidades::Entidade* pE);
                void apagar(Entidades::Entidade* pE);
                void apagar(size_t indice);
                size_t getTamanho() const{return LEs.getTamanho();}

                Entidades::Entidade* operator[](int indice) const;


                void percorrer();
                void limpaLista();
                //void salvar(ostream* arquivo);

        };

    }
}

#endif
