#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

Pilha* criarPilha() {
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void empilhar(Pilha *pilha, float notas[3]) {
    NodoPilha *novo = (NodoPilha*)malloc(sizeof(NodoPilha));
    memcpy(novo->notasAntigas, notas, sizeof(float) * 3);
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void desempilhar(Pilha *pilha) {
    if (pilha->topo) {
        NodoPilha *temp = pilha->topo;
        pilha->topo = temp->prox;
        free(temp);
    }
}

void listarPilha(Pilha *pilha) {
    NodoPilha *atual = pilha->topo;
    while (atual) {
        printf("Notas anteriores: %.2f %.2f %.2f\n",
               atual->notasAntigas[0], atual->notasAntigas[1], atual->notasAntigas[2]);
        atual = atual->prox;
    }
}

void liberarPilha(Pilha *pilha) {
    while (pilha->topo) {
        desempilhar(pilha);
    }
    free(pilha);
}