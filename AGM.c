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

#define MAX_VERT 0xFFFFFF
#define iNum Grafo->iNumVertices // Diminuir notacao

void ArvoreMin(TipoGrafo *Grafo, TipoGrafo *Grafo_min)
{
    int V1,
        V2,
        *bFlag, // Flag usado para indicar vertices no processo AGM
        iPeso_INF, // Variavel auxiliar de peso infimo para encontrar o menor peso das arestas
        iCountVert, // Contar a quantidade de vertices no AGM
        iIndex; // Contador

    Pointer Aux; //Ponteiro auxiliar

    bFlag = (int *) malloc( sizeof(int)*iNum); // Cria um flag para indicar a insercao do vertice no AGM
    for(iIndex = 0; iIndex <= iNum; iIndex++)
        *(bFlag + iIndex) = 0;
    *(bFlag + Grafo->bZeroOROne) = 1; // Adiciona o vertice 0 ou 1 no grafo a ser gerado
    iCountVert = 1;

    do // inicio do while(iCountVert < iNum)
    {
        iIndex = Grafo->bZeroOROne; // Se inicia o vertice no 0 ou 1
        iPeso_INF = MAX_VERT; // Peso infinito

        while(iIndex < iNum + Grafo->bZeroOROne) { // Varre toda a lista de adjacencia
            if(*(bFlag + iIndex) == 1) // Se o vertice existe no AGM
            {
                Aux = Grafo->Adj[iIndex].Next;
                while(Aux != NULL)
                {
                    // Encontra a aresta com o vertice nao adicionado na AGM menor que o peso infimo
                    if(iPeso_INF > Aux->Item.iPeso
                       && *(bFlag + Aux->Item.Vertice) == 0)
                    {
                        iPeso_INF = Aux->Item.iPeso;
                        V1 = iIndex;
                        V2 = Aux->Item.Vertice;
                    } // fim do if(iPeso_INF ...

                    Aux = Aux->Next;
                } // fim do while(Aux != NULL)

            } // fim do if(*(bFlag + iIndex) == 1)
            iIndex++;

        } // fim do while(iIndex < ...

        // Se nao acha o vertice com peso minimo ele pula o if
        if(iPeso_INF != MAX_VERT)
        {
            InsereAresta(Grafo_min, &V1, &V2, &iPeso_INF);
            *(bFlag + V2) = 1;
            InsereAresta(Grafo_min, &V2, &V1, &iPeso_INF);
        } // fim do if(iPeso_INF...

        iCountVert++;
    } while(iCountVert < iNum);

    Grafo_min->iNumArestas = iCountVert - 1; // Determina quantas arestas na AGM
    return;
} // fim do ArvoreMin

void ImprimeMIN(TipoGrafo *Grafo)
{
    printf("%d %d\n",Grafo->iNumVertices, Grafo->iNumArestas);
    Imprime(Grafo);
    return;
} // fim do ImprimeMIN
