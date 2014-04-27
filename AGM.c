//
//  AGM.c
//  Arvore Geradora Minima
//
//  Tipo Abstrato de Dados para encontrar a arvore geradora
//  minima de um grafo utilizando o algoritmo de Prim
//
//  Created by Yuri Niitsuma on 12/04/14.
//  Copyright (c) 2014 Yuri Niitsuma. All rights reserved.
//

#include "AGM.h"

void ArvoreMin(TipoGrafo *Grafo, TipoGrafo *Grafo_min)
{
    int V1,
        V2,
        *bFlag, // Flag usado para indicar vertices no processo AGM
        iPeso_INF,
        iCountVert,
        iIndex;
    int iNum = Grafo->iNumVertices;
    Pointer Aux;

    bFlag = (int *) malloc( sizeof(int)*iNum);
    for(iIndex = 0; iIndex <= iNum; iIndex++)
        *(bFlag + iIndex) = 0;
    *(bFlag + 1) = 1; // Adiciona o vertice zero no grafo a ser gerado

    iCountVert = 1;
    do
    {
        iIndex = Grafo->bZeroOROne;
        iPeso_INF = 0xFFFFFF;
        while(iIndex < iNum + Grafo->bZeroOROne) {
            if(*(bFlag + iIndex) == 1)
            {
                Aux = Grafo->Adj[iIndex].Next;
                while(Aux != NULL)
                {
                    if(iPeso_INF > Aux->Item.iPeso && *(bFlag + Aux->Item.Vertice) == 0)
                    {
                        iPeso_INF = Aux->Item.iPeso;
                        V1 = iIndex;
                        V2 = Aux->Item.Vertice;
                    } // fim do if

                    Aux = Aux->Next;
                } // fim do while

            } // fim do if
            iIndex++;

        } // fim do while

        if(iPeso_INF != 0xFFFF)
        {
            InsereAresta(Grafo_min, &V1, &V2, &iPeso_INF);
            *(bFlag + V2) = 1;
            InsereAresta(Grafo_min, &V2, &V1, &iPeso_INF);
        } // fim do if
        iCountVert++;
    } while(iCountVert < iNum);

    Grafo_min->iNumArestas = iCountVert - 1;
    return;
} // ArvoreMin

void ImprimeMIN(TipoGrafo *Grafo)
{
    printf("%d %d\n",Grafo->iNumVertices, Grafo->iNumArestas);
    Imprime(Grafo);
    return;
} // fim do ImprimeMIN
