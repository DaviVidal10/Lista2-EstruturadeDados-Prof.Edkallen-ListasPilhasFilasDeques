/*
Função: Vetor de Inteiros
Autor: Carlos Eduardo
Data: 17/06/2025
observação:
*/


#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criarFila() {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = fila->fim = NULL;
    return fila;
}

void enfileirar(Fila *fila, Estudante e) {
    NodoFila *novo = (NodoFila*)malloc(sizeof(NodoFila));
    novo->dados = e;
    novo->prox = NULL;
    if (fila->fim) fila->fim->prox = novo;
    else fila->inicio = novo;
    fila->fim = novo;
}

void desenfileirar(Fila *fila) {
    if (fila->inicio) {
        NodoFila *temp = fila->inicio;
        fila->inicio = temp->prox;
        if (!fila->inicio) fila->fim = NULL;
        free(temp);
    }
}

void listarFila(Fila *fila) {
    NodoFila *atual = fila->inicio;
    while (atual) {
        imprimirEstudante(atual->dados);
        atual = atual->prox;
    }
}

void liberarFila(Fila *fila) {
    while (fila->inicio) {
        desenfileirar(fila);
    }
    free(fila);
}