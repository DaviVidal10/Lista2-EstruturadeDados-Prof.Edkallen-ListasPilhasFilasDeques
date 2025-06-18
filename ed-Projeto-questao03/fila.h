/*
Função: Vetor de Inteiros
Autor: Carlos Eduardo
Data: 17/06/2025
observação:
*/

#ifndef FILA_H
#define FILA_H

#include "estudante.h"

typedef struct NodoFila {
    Estudante dados;
    struct NodoFila *prox;
} NodoFila;

typedef struct {
    NodoFila *inicio;
    NodoFila *fim;
} Fila;

Fila* criarFila();
void enfileirar(Fila *fila, Estudante e);
void desenfileirar(Fila *fila);
void listarFila(Fila *fila);
void liberarFila(Fila *fila);

#endif