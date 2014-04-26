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
    Grafo->Adj = (TipoLista *) malloc( sizeof(TipoLista)*Grafo->iNumVertices );

    long iIndex;
    for(iIndex = 0; iIndex < Grafo->iNumVertices; iIndex++)
    {
        Grafo->Adj[iIndex].First = NULL;
    } // fim do for
    return;
} // fim do FGVazio

void InsereAresta(TipoGrafo *Grafo, int *V1, int *V2, int *iPeso)
{
    if(Grafo->Adj[*V1].First == NULL)   // Se o vertice nao contem nenhuma aresta
    {
        Pointer Cell;
        Cell = (Pointer) malloc(sizeof(Celula));
        Cell->Item.Vertice = *V2;
        Cell->Item.iPeso = *iPeso;
        Grafo->Adj[*V1].First = Cell;
        Cell->Next = NULL;
    } // fim do if
    else   // Se o vertice ja contem pelo menos uma aresta
    {
        Pointer Cell, // Para a nova celula
                Aux, // Ponteiro pra andar na lista
                Prev; // Ponteiro auxiliar para guardar o ponteiro da celula anterior
        Cell = (Pointer) malloc(sizeof(Celula));
        Cell->Item.Vertice = *V2;
        Cell->Item.iPeso = *iPeso;

        Aux = Grafo->Adj[*V1].First;

        if(*V2 <= Aux->Item.Vertice)   // Caso seja o primeiro da lista
        {
            Cell->Next = Grafo->Adj[*V1].First;
            Grafo->Adj[*V1].First = Cell;
        } // fim do if

        Prev = Aux;
        Aux = Aux->Next;

        do
        {
            if(Aux == NULL) // Trata se o segundo ponteiro e nulo
            {
                Prev->Next = Cell;
                Cell->Next = NULL;
                break;
            } // fim do if
            if(*V2 <= Aux->Item.Vertice)   // Insere a celula no meio da lista
            {
                Cell->Next = Aux;
                Prev->Next = Cell;
                break;
            } // fim do if

            Prev = Aux;
            Aux = Aux->Next;
        } while (Aux != NULL); // fim do while
    } // fim do else
    return;
} // fim do InsereAresta

void Imprime(TipoGrafo *Grafo)
{
    int iIndex = 0;

    Pointer Aux;

    while(iIndex < Grafo->iNumVertices)
    {
        Aux = Grafo->Adj[iIndex].First;
        printf("Vertice(%d): ", iIndex);
        while(Aux != NULL)
        {
            printf("(%d,%d) ", Aux->Item.Vertice, Aux->Item.iPeso);
            Aux = Aux->Next;
        } // fim do while
        iIndex++;
        printf("\n");

    } // fim do while
} // fim do Imprime
