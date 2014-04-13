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
    TipoGrafo gGrafo;

    int iNumVertices,
        iNumArestas;
    int iIndex;

    //DEBUG
    int iTeste, iIndexTest;

    TipoValorVertice V1, V2;

    TipoPeso iPeso;

    scanf("%d", &iTeste); // DEBUG

    for(iIndexTest = 1; iIndexTest <= iTeste; iIndexTest++)
    {
        scanf("%d %d", &iNumVertices, &iNumArestas);

        gGrafo.NumVertices = iNumVertices;
        FGVazio(&gGrafo);

        printf("\nTeste %d\n", iIndexTest); // DEBUG

        iIndex = 0;
        while(iIndex < iNumArestas)
        {
            scanf("%d", &V1);
            scanf("%d", &V2);
            scanf("%d", &iPeso);
            if(!ExisteAresta(V1,V2, &gGrafo))
                InsereAresta(&V1, &V2, &iPeso, &gGrafo);
            iIndex++;
        }

        // DEBUG
        ImprimeGrafo(&gGrafo);
        LiberaGrafo(&gGrafo);
    }

    return 0;
}
