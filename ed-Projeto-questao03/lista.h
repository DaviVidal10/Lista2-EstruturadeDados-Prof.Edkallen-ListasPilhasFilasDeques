/*
Função: Vetor de Inteiros
Autor: Carlos Eduardo
Data: 14/06/2025
observação:
*/

#ifndef LISTA_H
#define LISTA_H

#include "estudante.h"

typedef struct No {
    Estudante dados;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

Lista* criarLista();
void adicionarEstudante(Lista *lista, Estudante e);
void removerEstudante(Lista *lista, int matricula);
Estudante* buscarEstudante(Lista *lista, int matricula);
void listarEstudantes(Lista *lista);
void liberarLista(Lista *lista);

#endif