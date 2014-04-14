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

TipoGrafo ArvoreGMinima(TipoGrafo *Grafo)
{
    TipoGrafo A;

    A.NumVertices = Grafo->NumVertices;
    FGVazio(&A);

    TipoApontador celAux;
    celAux = Grafo->Adj[0].Primeiro;

    TipoValorVertice iTemp = 0xFFFFFFFF;
    int iIndex = 1;

    while(celAux->Prox != NULL)
    {
        /* find the minumum cost */
        if(!(ExisteAresta(iIndex, celAux->Item.Vertice, &A)))
        {
            if(celAux->Item.Peso < iTemp)
                iTemp = celAux->Item.Peso;
        }
        celAux = celAux->Prox; ++iIndex;
    }

    int V1,
        V2;
        V1 = 0;
        V2 = iIndex-1;


    InsereAresta(&V1, &V2, &iTemp, &A);

    return A;
}
