#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

struct Vetor {
    int* dados;
    int tamanho;
    int capacidade;
};

Vetor* criarVetor(int capacidadeInicial) {
    Vetor* v = (Vetor*) malloc(sizeof(Vetor));
    v->dados = (int*) malloc(capacidadeInicial * sizeof(int));
    v->tamanho = 0;
    v->capacidade = capacidadeInicial;
    return v;
}

void inserirElemento(Vetor* v, int elemento) {
    if (v->tamanho == v->capacidade) {
        v->capacidade *= 2;
        v->dados = (int*) realloc(v->dados, v->capacidade * sizeof(int));
    }
    v->dados[v->tamanho++] = elemento;
}

void removerElemento(Vetor* v, int posicao) {
    if (posicao < 0 || posicao >= v->tamanho) {
        printf("Posição inválida para remoção!\n");
        return;
    }
    for (int i = posicao; i < v->tamanho - 1; i++) {
        v->dados[i] = v->dados[i + 1];
    }
    v->tamanho--;
}

int obterElemento(Vetor* v, int posicao) {
    if (posicao < 0 || posicao >= v->tamanho) {
        printf("Posição inválida!\n");
        return -1;
    }
    return v->dados[posicao];
}

void imprimirVetor(Vetor* v) {
    printf("Vetor: ");
    for (int i = 0; i < v->tamanho; i++) {
        printf("%d ", v->dados[i]);
    }
    printf("\n");
}

void liberarVetor(Vetor* v) {
    free(v->dados);
    free(v);
}
