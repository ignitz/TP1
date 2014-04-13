//
//  Grafo.c
//
//  Tipo Abstrato de Dados retirado do livro
//  Projeto de Algoritmos [Nivio Ziviane]
//
//  Created by Yuri Niitsuma on 12/04/14.
//  Copyright (c) 2014 Yuri Niitsuma. All rights reserved.
//

#include "Grafo.h"

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void FGVazio(TipoGrafo *Grafo)
{
    long i;
    for(i = 0; i < Grafo->NumVertices; i++)
        FLVazia(&Grafo->Adj[i]);
}

void InsereAresta(TipoValorVertice *V1,
                  TipoValorVertice *V2,
                  TipoPeso *Peso,
                  TipoGrafo *Grafo)
{
    TipoItem x;
    x.Vertice = *V2;
    x.Peso = *Peso;
    Insere(x, &Grafo->Adj[*V1]);

    // Modificação pra grafo nao-direcionado
    x.Vertice = *V1;
    Insere(x, &Grafo->Adj[*V2]);
}

short ExisteAresta(TipoValorVertice Vertice1,
                   TipoValorVertice Vertice2,
                   TipoGrafo *Grafo)
{
    TipoApontador Aux;
    short EncontrouAresta = FALSE;
    Aux = Grafo->Adj[Vertice1].Primeiro->Prox;
    while(Aux != NULL && EncontrouAresta == FALSE)
    {
        if(Vertice2 == Aux->Item.Vertice)
            EncontrouAresta = TRUE;
        Aux = Aux->Prox;
    }
    return EncontrouAresta;
}

/* Operadores para obter a lista de adjacentes */
short ListaAdjVazia(TipoValorVertice *Vertice,
                    TipoGrafo *Grafo)
{
    return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}

void ProxAdj(TipoValorVertice *Vertice,
             TipoGrafo *Grafo,
             TipoValorVertice *Adj,
             TipoPeso *Peso,
             TipoApontador *Prox,
             short *FimListaAdj)
{
    /* Retorna Adj e Peso do Item apontado por Prox */
    *Adj = (*Prox)->Item.Vertice;
    *Peso = (*Prox)->Item.Peso;
    *Prox = (*Prox)->Prox;
    if(*Prox == NULL)
        *FimListaAdj = TRUE;
}

void Retira(TipoApontador p,
            TipoLista *Lista,
            TipoItem *Item)
{
    /* O item a ser retirado e o seguinte ao ser apontado por p-- */
    TipoApontador q;
    if(Vazia(*Lista) || p == NULL || p->Prox == NULL)
    {
        printf("Erro: Lista vazia ou posicao nao existe\n");
        return;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    if(p->Prox == NULL) Lista->Ultimo = p;
    free(q);
}

void LiberaGrafo(TipoGrafo *Grafo)
{
    TipoApontador AuxAnterior, Aux; long i;
    for(i = 0; i< Grafo->NumVertices; i++)
    {
        Aux = Grafo->Adj[i].Primeiro->Prox;
        free(Grafo->Adj[i].Primeiro); // Libera celula cabeça
        Grafo->Adj[i].Primeiro = NULL;
        while(Aux != NULL)
        {
            AuxAnterior = Aux;
            Aux = Aux->Prox;
            free(AuxAnterior);
        }
    }
    Grafo->NumVertices = 0;
}

void ImprimeGrafo(TipoGrafo *Grafo)
{
    int i;
    TipoApontador Aux;
    for(i = 0; i < Grafo->NumVertices; i++)
    {
        printf("Vertice%2d: ", i);
        if(!Vazia(Grafo->Adj[i]))
        {
            Aux = Grafo->Adj[i].Primeiro->Prox;
            while(Aux != NULL)
            {
                printf("%3d (%d)", Aux->Item.Vertice, Aux->Item.Peso);
                Aux = Aux->Prox;
            }
        }
        putchar('\n');
    }
}
