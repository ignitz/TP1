//
//  Grafo.h
//
//  Tipo Abstrato de Dados retirado do livro
//  Projeto de Algoritmos [Nivio Ziviane]
//
//  Created by Yuri Niitsuma on 12/04/14.
//  Copyright (c) 2014 Yuri Niitsuma. All rights reserved.
//

#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h> /** Usado pra Seed Random*/

#define FALSE 0
#define TRUE 1

/*
 _______________            _______________
| iPeso | Right | -------->| iPeso | Right | --------> ...
|_______|_______|          |_______|_______|

*/

typedef struct TipoItem {
    int Vertice,
        iPeso;
} TipoItem;

typedef struct Celula_str *Pointer;
typedef struct Celula_str {
    TipoItem Item;
    Pointer Next;
} Celula;

typedef struct TipoLista {
    Pointer First;
} TipoLista;

typedef struct TipoGrafo {
    int iNumVertices, iNumArestas;
    TipoLista *Adj;
} TipoGrafo;

#endif // GRAFO_H_INCLUDED

// Lista de funções
void FGVazio(TipoGrafo *Grafo);
void InsereAresta(TipoGrafo *Grafo, int *V1, int *V2, int *iPeso);
void Imprime(TipoGrafo *Grafo);
