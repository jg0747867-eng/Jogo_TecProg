#include "ListaEntidade.h"

namespace Trabalhojogo
{
    namespace Listas
    {
        ListaEntidades::ListaEntidades(): LEs()
        {
            limpaLista();
        }

        ListaEntidades::~ListaEntidades()
        {
            limpaLista();
        }

        void ListaEntidades::limpaLista()
        {
            LEs.limpaLista();
        }

        void ListaEntidades::incluir(Entidades::Entidade* pE)
        {
            if(pE)
                LEs.incluir(pE);
        }

        void ListaEntidades::apagar(Entidades::Entidade* pE)
        {
            if (pE)
            {
                LEs.apagar(pE);
            }
        }

        void ListaEntidades::apagar(size_t indice)
        {
            LEs.apagar(indice);
        }

        Entidades::Entidade* ListaEntidades::operator[](int indice) const
        {
            return LEs[indice];
        }

        void ListaEntidades::percorrer()
        {
            LEs.percorrer();
        }

    }
}