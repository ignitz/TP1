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
    Grafo->bZeroOROne = 0; // Identificador inicial para Vertice 0
    // Adiciona uma lista de adjacencia de 0 ate n com n+1 vertices
    Grafo->Adj = (TipoLista *) malloc( sizeof(TipoLista)*Grafo->iNumVertices + 1);

    int iIndex;
    // Gera o grafo com 0 arestas
    for(iIndex = 0; iIndex <= Grafo->iNumVertices; iIndex++)
    {
        Grafo->Adj[iIndex].Next = NULL;
    } // fim do for

    return;
} // fim do FGVazio

void InsereAresta(TipoGrafo *Grafo, int *V1, int *V2, int *iPeso)
{
    // Se vertice de entrada for n de um grafo de n vertices entao
    // ignora o vertice zero para adicionar o vertice n
    if(*V2 == Grafo->iNumVertices)
        Grafo->bZeroOROne = 1;

    // Se o vertice nao contem nenhuma aresta adiciona o primeiro
    if(Grafo->Adj[*V1].Next == NULL)
    {
        Pointer Cell;
        Cell = (Pointer) malloc(sizeof(Celula));
        Cell->Item.Vertice = *V2;
        Cell->Item.iPeso = *iPeso;
        Grafo->Adj[*V1].Next = Cell;
        Cell->Next = NULL;
    } // fim do if

    else   // Se o vertice ja contem pelo menos uma aresta
    {
        Pointer Cell, // Para a nova celula
                Aux, // Ponteiro pra andar na lista
                Prev; // Ponteiro auxiliar para guardar o ponteiro da celula anterior

        // Cria uma celula representando uma aresta
        Cell = (Pointer) malloc(sizeof(Celula));
        Cell->Item.Vertice = *V2;
        Cell->Item.iPeso = *iPeso;

        Aux = Grafo->Adj[*V1].Next;

        do {
            if(Aux == NULL) // Inserido no final da lista
            {
                if(Grafo->Adj[*V1].Next == NULL) // Tratamento no inicio da lista
                {
                    Grafo->Adj[*V1].Next = Cell;
                    Cell->Next = NULL;
                } // fim do if(Grafo->Adj[*V1].Next == NULL)

                else // Fora do inicio da lista
                {
                    Prev->Next = Cell;
                    Cell->Next = NULL;
                } // fim do else

                break;
            } // fim do if

            else
            {
                if(*V2 <= Aux->Item.Vertice) // Se eh adicionado da segunda celula em diante
                {
                    if(Grafo->Adj[*V1].Next == Aux) // Tratamento no inicio da lista
                    {
                        Grafo->Adj[*V1].Next = Cell;
                        Cell->Next = Aux;
                    } // fim do if(Grafo->Adj[*V1]...

                    else
                    {
                        Prev->Next = Cell;
                        Cell->Next = Aux;
                    } // fim do else

                    break;
                } // fim do if(*V2 <= Aux->...

            } // fim do else

            Prev = Aux;
            Aux = Aux->Next; // Passa para a proxima celula
        } while(1);

    } // fim do else

    return;

} // fim do InsereAresta

// Funcao que varre toda a lista de adjacencia imprimindo todas as arestas
// V1 e V2 tal que V1 < V2
void Imprime(TipoGrafo *Grafo)
{
    int iIndex = Grafo->bZeroOROne;

    Pointer Aux;
    while(iIndex < Grafo->iNumVertices + Grafo->bZeroOROne)
    {
        Aux = Grafo->Adj[iIndex].Next;

        while(Aux != NULL)
        {
            if(iIndex < Aux->Item.Vertice)
                printf("%d %d %d\n", iIndex, Aux->Item.Vertice, Aux->Item.iPeso);
            Aux = Aux->Next;
        } // fim do while

        iIndex++;
    } // fim do while

} // fim do Imprime
