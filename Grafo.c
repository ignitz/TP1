//
//  Grafo.c
//
//  Tipo Abstrato de Dados como base do livro
//  Projeto de Algoritmos [Nivio Ziviane]
//
//  Created by Yuri Niitsuma on 12/04/14.
//  Copyright (c) 2014 Yuri Niitsuma. All rights reserved.
//

#include "Grafo.h"

void FGVazio(TipoGrafo *Grafo)
{
    Pointer pAux = (Pointer) malloc(sizeof(Celula));
    Grafo->Inicial = pAux;
    Grafo->Inicial->Right = Grafo->Inicial;
    Grafo->Inicial->Down = Grafo->Inicial;
    Grafo->Inicial->iMat_i = -1;
    Grafo->Inicial->iMat_j = -1;
    Grafo->Inicial->iPeso = NULL;
    //DEBUG
//        printf("DEBUG (%d, %d, %d, R(%d, %d), D(%d, %d))\n", pAux->iMat_i, pAux->iMat_j, pAux->iPeso,
//               pAux->Right->iMat_i, pAux->Right->iMat_j, pAux->Down->iMat_i, pAux->Down->iMat_j);
}

void FLCHead(TipoGrafo *Grafo) // Faz Linhas e Colunas cabeca
{
    int iIndex;
    // Variaveis auxiliares
    Pointer pMalloc,
            pAux;

    // Bloco para gerar as células cabeças da matriz
    pAux = Grafo->Inicial;
    iIndex = 0;
    while(iIndex < Grafo->iNumVertice) // Forma as celulas cabecas das colunas
    {
        pMalloc = (Pointer) malloc(sizeof(Celula));
        pAux->Right = pMalloc; // Aponta pra nova celula
        pMalloc->Right = Grafo->Inicial; // Ultima celula aponta pra Inicial
        pMalloc->Down = pMalloc; // Ponteiro cabeca coluna aponta pra ela mesma
        if(pAux->Right != Grafo->Inicial) // Define coordenadas
        {
            pAux->Right->iMat_i = iIndex;
            pAux->Right->iMat_j = -1;
            pAux->Right->iPeso = NULL;
        } // fim do if

        pAux = pAux->Right; // Caminha pra direita
        iIndex++;

        //DEBUG
        // printf("DEBUG (%d, %d, %d, R(%d, %d), D(%d, %d))\n", pAux->iMat_i, pAux->iMat_j, pAux->iPeso,
        //        pAux->Right->iMat_i, pAux->Right->iMat_j, pAux->Down->iMat_i, pAux->Down->iMat_j);

    } // fim do while da coluna

    pAux = Grafo->Inicial;
    iIndex = 0;
    while(iIndex < Grafo->iNumVertice) // Forma as celulas cabecas das linhas
    {
        pMalloc = (Pointer) malloc(sizeof(Celula));
        pAux->Down = pMalloc; // Aponta pra nova celula
        pMalloc->Down = Grafo->Inicial; // Ultima celula aponta pra Inicial
        pMalloc->Right = pMalloc; // Ponteiro cabeca linha aponta pra ela mesma
        if(pAux->Down != Grafo->Inicial) // Define coordenadas
        {
            pAux->Down->iMat_i = -1;
            pAux->Down->iMat_j = iIndex;
            pAux->Down->iPeso = NULL;
        } // fim do if

        pAux = pAux->Down; // Caminha pra baixo
        iIndex++;
//DEBUG
//        printf("DEBUG (%d, %d, %d, R(%d, %d), D(%d, %d))\n", pAux->iMat_i, pAux->iMat_j, pAux->iPeso,
//               pAux->Right->iMat_i, pAux->Right->iMat_j, pAux->Down->iMat_i, pAux->Down->iMat_j);

    } // fim do while da linha
} // fim do Bloco

// Insere uma aresta com peso entre os vertices
void InsereCelula(TipoGrafo *Grafo, int *iVertice_I, int *iVertice_J, int *iPeso)
{
    int iIndex_I, iIndex_J;
    Pointer pMalloc = (Pointer) malloc(sizeof(Celula));
    Pointer pAux = Grafo->Inicial;

    iIndex_J = 0;
    while(iIndex_J < *iVertice_J)
    {
        pAux = pAux->Down; // Caminha pra baixo
        iIndex_J++;
    } // fim do while

    if(pAux->Right != pAux)
        while(pAux->iMat_i < *iVertice_I)
            pAux = pAux->Right; // Caminha pra Direita
    // Efetua troca dos ponteiros
    pMalloc->Right = pAux->Down->Right;
    pAux->Right = pMalloc;

    pAux = Grafo->Inicial;

    iIndex_I = 0;
    while(iIndex_I < *iVertice_I)
    {
        pAux = pAux->Right; // Caminha pra direita
        iIndex_I++;
    } // fim do while

    if(pAux->Down != pAux)
        while(pAux->iMat_j < *iVertice_J)
            pAux = pAux->Down; // Caminha pra Baixo
    // Efetua troca dos ponteiros
    pMalloc->Down = pAux->Right->Down;
    pAux->Down = pMalloc;

    pMalloc->iMat_i = *iVertice_I;
    pMalloc->iMat_j = *iVertice_J;
    pMalloc->iPeso = *iPeso;

    //DEBUG
        printf("DEBUG (%d, %d, %d, R(%d, %d), D(%d, %d))\n", pMalloc->iMat_i, pMalloc->iMat_j, pMalloc->iPeso,
               pMalloc->Right->iMat_i, pMalloc->Right->iMat_j, pMalloc->Down->iMat_i, pMalloc->Down->iMat_j);

} // fim do InsereCelula

void ImprimeGrafo(TipoGrafo *Grafo)
{
    Pointer pAux;
    Pointer pAux_Fix = Grafo->Inicial->Down;
    while( pAux_Fix != Grafo->Inicial )
    {
        pAux = pAux_Fix->Right;

        printf("Vertice(%d): ", pAux->iMat_j);
        while(pAux->iMat_i != pAux_Fix->iMat_i) //
        {
            printf("(%d, %d, %d)\n", pAux->iMat_i, pAux->iMat_j, pAux->iPeso);

            //DEBUG
            printf("DEBUG (%d, %d, %d, R(%d, %d), D(%d, %d))\n", pAux->iMat_i, pAux->iMat_j, pAux->iPeso,
            pAux->Right->iMat_i, pAux->Right->iMat_j, pAux->Down->iMat_i, pAux->Down->iMat_j);

            pAux = pAux->Right;
        } // fim do while

        printf("\n");
        pAux_Fix = pAux_Fix->Down; // Caminha pra baixo
        //DEBUG
        // printf("DEBUG (%d, %d, %d, R(%d, %d), D(%d, %d))\n", pAux->iMat_i, pAux->iMat_j, pAux->iPeso,
        //       pAux->Right->iMat_i, pAux->Right->iMat_j, pAux->Down->iMat_i, pAux->Down->iMat_j);

    } // fim do While
} // fim do ImprimeGrafo
