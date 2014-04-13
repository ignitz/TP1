//
//  AGM.c
//  Arvore Geradora Minima
//
//  Tipo Abstrato de Dados para encontrar a arvore geradora
//  minima de um grafo utilizando o algoritmo de Djiskra
//
//  Created by Yuri Niitsuma on 12/04/14.
//  Copyright (c) 2014 Yuri Niitsuma. All rights reserved.
//

#include "AGM.h"

TipoGrafo ArvoreGMinima(TipoGrafo *Grafo)
{
    TipoGrafo A;
    A.NumVertices = Grafo->NumVertices;
    A.NumArestas = 0;

    return A;
}
