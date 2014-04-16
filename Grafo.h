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

typedef struct Celula_str *Pointer;
typedef struct Celula_str {
    // Coordenadas da Matriz
    int iMat_i,
        iMat_j;
    Pointer Right, Down;
    int iPeso;
} Celula;

typedef struct TipoGrafo {
    int iNumVertice,
        iNumArestas;
    Pointer Inicial;
} TipoGrafo;

#endif // GRAFO_H_INCLUDED

// Lista de funções
void FGVazio(TipoGrafo *Grafo); // Cria um grafo vazio
void FLCHead(TipoGrafo *Grafo); // Faz Linhas e Colunas cabeca
void InsereCelula(TipoGrafo *Grafo, int *iVertice_I, int *iVertice_J, int *iPeso); // Insere um peso entre os vertices
void ImprimeGrafo(TipoGrafo *Grafo); // Imprime os pesos das arestas
