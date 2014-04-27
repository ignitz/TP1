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
    TipoGrafo Grafo;
    long iIndex; // Contador
    int iAux, // Variavel para troca
        V1, // Vertice 1 leitura
        V2, // Vertice 2 leitura
        iPeso; // Peso da aresta

    scanf("%d %d", &Grafo.iNumVertices, &Grafo.iNumArestas);
    FGVazio(&Grafo);

    iIndex = 0;
    while(iIndex < Grafo.iNumArestas) {
        scanf("%d %d %d", &V1, &V2, &iPeso);
        if( V1 > V2 ) { // Efetua troca para V1 <= V2
            iAux = V1;
            V1 = V2;
            V2 = iAux;
        } // fim do if

        InsereAresta(&Grafo, &V1, &V2, &iPeso);
        // Imprime(&Grafo);
        InsereAresta(&Grafo, &V2, &V1, &iPeso); // Grafo direcionado na direcao oposta
        // Imprime(&Grafo);
        iIndex++;
    } // fim do while

    // Teste de Impressao dos vertices

    Imprime(&Grafo);

    return 0;
}
