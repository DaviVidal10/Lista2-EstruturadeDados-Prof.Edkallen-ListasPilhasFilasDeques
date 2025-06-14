/*
Função: Vetor de Inteiros
Autor: Carlos Eduardo
Data:14/06/2025
observação:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Lista* criarLista() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

void adicionarEstudante(Lista *lista, Estudante e) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dados = e;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void removerEstudante(Lista *lista, int matricula) {
    No *ant = NULL, *atual = lista->inicio;
    while (atual != NULL && atual->dados.matricula != matricula) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual) {
        if (ant) ant->prox = atual->prox;
        else lista->inicio = atual->prox;
        free(atual);
    }
}

Estudante* buscarEstudante(Lista *lista, int matricula) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dados.matricula == matricula)
            return &atual->dados;
        atual = atual->prox;
    }
    return NULL;
}

void listarEstudantes(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        imprimirEstudante(atual->dados);
        atual = atual->prox;
    }
}

void liberarLista(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}