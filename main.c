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
    TipoGrafo   Grafo, // Grafo de entrada
                Grafo_min; // Grafo para gerar AGM
    int iIndex, // Contador
        iAux, // Variavel para troca
        V1, // Vertice 1 leitura
        V2, // Vertice 2 leitura
        iPeso; // Peso da aresta

    scanf("%d %d", &Grafo.iNumVertices, &Grafo.iNumArestas);
    Grafo_min.iNumVertices = Grafo.iNumVertices; // Iguala o numero
    FGVazio(&Grafo); // Gera a lista de adjacencia com malloc
    FGVazio(&Grafo_min); // Idem para o AGM

    iIndex = 0;
    while(iIndex < Grafo.iNumArestas) {
        scanf("%d %d %d", &V1, &V2, &iPeso);

        if( V1 > V2 ) { // Efetua troca para V1 <= V2
            iAux = V1;
            V1 = V2;
            V2 = iAux;
        } // fim do if( V1 > V2 )

        // Insere o grafo nas duas direcoes
        InsereAresta(&Grafo, &V1, &V2, &iPeso);
        InsereAresta(&Grafo, &V2, &V1, &iPeso); // Grafo direcionado na direcao oposta

        iIndex++;
    } // fim do while(iIndex < Grafo.iNumArestas)

    Grafo_min.bZeroOROne = Grafo.bZeroOROne; // Identificador booleano para adicionar vertice 0 ou nao

    //Funcao para gerar e imprimir o AGM dado o Grafo de entrada
    ArvoreMin(&Grafo, &Grafo_min);
    ImprimeMIN(&Grafo_min);

    return 0;
}
