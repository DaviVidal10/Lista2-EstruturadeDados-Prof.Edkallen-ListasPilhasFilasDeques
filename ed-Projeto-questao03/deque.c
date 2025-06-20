#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

Deque* criarDeque() {
    Deque *deque = (Deque*)malloc(sizeof(Deque));
    deque->inicio = deque->fim = NULL;
    return deque;
}

void inserirInicio(Deque *deque, Estudante e) {
    NodoDeque *novo = (NodoDeque*)malloc(sizeof(NodoDeque));
    novo->dados = e;
    novo->ant = NULL;
    novo->prox = deque->inicio;
    if (deque->inicio) deque->inicio->ant = novo;
    else deque->fim = novo;
    deque->inicio = novo;
}

void inserirFim(Deque *deque, Estudante e) {
    NodoDeque *novo = (NodoDeque*)malloc(sizeof(NodoDeque));
    novo->dados = e;
    novo->prox = NULL;
    novo->ant = deque->fim;
    if (deque->fim) deque->fim->prox = novo;
    else deque->inicio = novo;
    deque->fim = novo;
}

void removerInicio(Deque *deque) {
    if (deque->inicio) {
        NodoDeque *temp = deque->inicio;
        deque->inicio = temp->prox;
        if (deque->inicio) deque->inicio->ant = NULL;
        else deque->fim = NULL;
        free(temp);
    }
}

void removerFim(Deque *deque) {
    if (deque->fim) {
        NodoDeque *temp = deque->fim;
        deque->fim = temp->ant;
        if (deque->fim) deque->fim->prox = NULL;
        else deque->inicio = NULL;
        free(temp);
    }
}

void listarDeque(Deque *deque) {
    NodoDeque *atual = deque->inicio;
    while (atual) {
        imprimirEstudante(atual->dados);
        atual = atual->prox;
    }
}

void liberarDeque(Deque *deque) {
    while (deque->inicio) {
        removerInicio(deque);
    }
    free(deque);
}