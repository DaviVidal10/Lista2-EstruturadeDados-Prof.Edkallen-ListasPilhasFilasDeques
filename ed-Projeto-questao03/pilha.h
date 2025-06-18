/*
Função: Vetor de Inteiros
Autor: Carlos Eduardo
Data: 17/06/2025
observação:
*/

#ifndef PILHA_H
#define PILHA_H

typedef struct NodoPilha {
    float notasAntigas[3];
    struct NodoPilha *prox;
} NodoPilha;

typedef struct {
    NodoPilha *topo;
} Pilha;

Pilha* criarPilha();
void empilhar(Pilha *pilha, float notas[3]);
void desempilhar(Pilha *pilha);
void listarPilha(Pilha *pilha);
void liberarPilha(Pilha *pilha);

#endif