#ifndef DEQUE_H
#define DEQUE_H

#include "estudante.h"

typedef struct NodoDeque {
    Estudante dados;
    struct NodoDeque *ant, *prox;
} NodoDeque;

typedef struct {
    NodoDeque *inicio;
    NodoDeque *fim;
} Deque;

Deque* criarDeque();
void inserirInicio(Deque *deque, Estudante e);
void inserirFim(Deque *deque, Estudante e);
void removerInicio(Deque *deque);
void removerFim(Deque *deque);
void listarDeque(Deque *deque);
void liberarDeque(Deque *deque);

#endif