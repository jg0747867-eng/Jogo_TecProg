#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>
/* 
 * Quero agradecer de antemão os colegas do PETECO
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
        template <class TL>
        class Lista
        {
            public:
            
            template <class TE>
            class Elemento
            {
                private:
                    Elemento<TE>* pProx;
                    TE* pInfo;
                
                public:
                    /*
                        Por questões de organização de código, decidi
                        inicializar os atributos da classe e seus metodos
                        logo em suas respectivas implementações.
                    */
                    Elemento(): pProx(NULL), pInfo(NULL){}
                    ~Elemento()
                    {
                        pProx = NULL;
                        pInfo = NULL;
                    }

                    void incluir(TE* pE)
                    {
                        if (pE)
                        {
                            pInfo = pE;
                        }
                    }
                    void setProx(Elemento<TE>* pE)
                    {
                        pProx = pE;
                    }
                    Elemento<TE>* getProx() const {return pProx;}
                    TE* getInfo() const {return pInfo;}
            };

            private:
                Elemento<TL>* pPrimeiro;
                Elemento<TL>* pUltimo;
                size_t tamLista;

            public:
                //Construtora e Destrutora também inicializados por organização
                Lista(): pPrimeiro(NULL), pUltimo(NULL), tamLista(0){}

                ~Lista()
                {
                    limpaLista();
                    pPrimeiro = NULL;
                    pUltimo = NULL;
                    tamLista = -1;
                }

                size_t getTamanho() const
                {
                    return tamLista;
                }

                TL* operator[](int indice) const;


                void apagar(int id);
                void apagar(TL* pInfo);

                void incluir(TL* pL);
                void percorrer();
                void limpaLista();
        };

        // Implentação dos metodos restantes do template Lista (TL)

        template <class TL>
        void Lista<TL>::incluir(TL* pL)
        {
            if (pL)
            {
                Elemento<TL>* pAux = NULL;
                pAux = new Elemento<TL>();

                pAux->incluir(pL);

                if(pPrimeiro == NULL)
                {
                    pPrimeiro = pAux;
                    pUltimo = pAux;
                }
                else
                {
                    pUltimo->setProx(pAux);
                    pUltimo = pAux;   
                }

                tamLista++;
            }
        }

        template <class TL>
        void Lista<TL>::limpaLista()
        {
            Elemento<TL>* pAux = NULL;

            while(pPrimeiro != NULL)
            {
                pAux = pPrimeiro->getProx();
                delete pPrimeiro;
                pPrimeiro = pAux;
            }

            pUltimo = NULL;
            tamLista = 0;
        }

        template <class TL>
        TL* Lista<TL>::operator[] (int indice) const
        {
            if(indice < 0 || indice >= (int)tamLista)
                return NULL;
            
            Elemento<TL>* pAux = pPrimeiro;
            int i = 0;
            while(i < indice)
            {
                pAux = pAux->getProx();
                i++;
            }

            return pAux->getInfo();
        } 

        template <class TL>
        void Lista<TL>::apagar(int indice)
        {
            if(indice < 0 || indice >= (int)tamLista)
                return; 
            
            Elemento<TL>* pAtual = NULL;
            Elemento<TL>* pAnte = NULL;

            TL* info = pAtual->getInfo();

            int i = 0;
            while(i < indice)
            {
                pAnte = pAtual;
                pAtual = pAnte->getProx();
                i++;
            }

            if(pAtual == pPrimeiro)
            {
                pPrimeiro = pAtual->getProx();
            }
            else if(pAtual == pUltimo)
            {
                pAnte->setProx(NULL);
                pUltimo = pAnte;
            }
            else
                pAnte->setProx(pAtual->getProx());
            
            tamLista--;
            delete pAtual;
        }    

        template<class TL>
        void Lista<TL>::apagar(TL* pinfo)
        {
            if(pPrimeiro == NULL)
                return;
            
            Elemento<TL>* pAtual = pPrimeiro;
            Elemento<TL>* pAnte = NULL;

            TL* info = pAtual->getInfo();

            while(pAtual != NULL && pAtual->getInfo() != pinfo)
            {
                pAnte = pAtual;
                pAtual = pAnte->getProx();
            }

            if (pAtual == pPrimeiro)
            {
                pPrimeiro = pAtual->getProx();
            }
            else if (pAtual == pUltimo)
            {
                pAnte->setProx(NULL);
                pUltimo = pAnte;
            }
            else
                pAnte->setProx(pAtual->getProx());

            tamLista--;
            delete pAtual;
        }

        template <class TL>
        void Lista<TL>::percorrer()
        {
            Elemento<TL>* pAux = NULL;

            while(pPrimeiro != NULL)
            {
                pAux = pPrimeiro->getProx();
            }
        }
    }
}

#endif
