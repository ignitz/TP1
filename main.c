//
//  main.c
//  Trabalho Pratico 1 - Arvore Geradora Minima
//
//  Created by Yuri Niitsuma on 12/04/14.
//  Copyright (c) 2014 Yuri Niitsuma. All rights reserved.
//

//  This code uses hungarian notation for variables
//  Example
//  int iIndex, char cCharacter, struct sStruct

#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#include "AGM.h"

int main()
{
    int iIndex, // Contador
        iAux, // var auxiliar
        // Var de leitura
        iVertice1,
        iVertice2,
        iPeso;


    TipoGrafo Grafo;
    FGVazio(&Grafo);

    scanf("%d %d",&Grafo.iNumVertice, &Grafo.iNumArestas); // Numero de vertices e numero de arestas do grafo
    FLCHead(&Grafo); // Faz Linhas e Colunas cabeca da matriz por listas

    iIndex = 0;
    while(iIndex < Grafo.iNumArestas)
    {
        scanf("%d %d %d", &iVertice1, &iVertice2, &iPeso); // Leitura dos vertices e peso
        if(iVertice1 > iVertice2) { // Troca pra ordem crescente do vertice
            iAux = iVertice1;
            iVertice1 = iVertice2;
            iVertice2 = iAux;
        } // fim do if
        if(Grafo.Inicial != Grafo.Inicial->Right) // Verifica se é vazio
            InsereCelula(&Grafo, &iVertice1, &iVertice2, &iPeso);
        iIndex++;
    } // fim do while

    // DEBUG
    ImprimeGrafo(&Grafo);

    return 0;
} // fim do main
