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
#include <sys/time.h>

#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500

#define FALSE 0
#define TRUE 1

typedef int TipoValorVertice;
typedef int TipoPeso;
typedef struct TipoItem {
    TipoValorVertice Vertice;
    TipoPeso Peso;
} TipoItem;

typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct TipoLista {
    TipoApontador Primeiro, Ultimo;
} TipoLista;

typedef struct TipoGrafo {
    TipoLista Adj[MAXNUMVERTICES + 1];
    TipoValorVertice NumVertices;
    short NumArestas;
} TipoGrafo;

#endif // GRAFO_H_INCLUDED

// Lista de funções
void FGVazio(TipoGrafo *Grafo);

void InsereAresta(TipoValorVertice *V1,
                  TipoValorVertice *V2,
                  TipoPeso *Peso,
                  TipoGrafo *Grafo);

short ExisteAresta(TipoValorVertice Vertice1,
                   TipoValorVertice Vertice2,
                   TipoGrafo *Grafo);

short ListaAdjVazia(TipoValorVertice *Vertice,
                    TipoGrafo *Grafo);

void ProxAdj(TipoValorVertice *Vertice,
             TipoGrafo *Grafo,
             TipoValorVertice *Adj,
             TipoPeso *Peso,
             TipoApontador *Prox,
             short *FimListaAdj);

void LiberaGrafo(TipoGrafo *Grafo);
void ImprimeGrafo(TipoGrafo *Grafo);
