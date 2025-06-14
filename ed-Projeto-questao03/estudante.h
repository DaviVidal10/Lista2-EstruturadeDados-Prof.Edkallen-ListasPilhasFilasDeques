/*
Função: Vetor de Inteiros
Autor: Carlos Eduardo
Data:14/06/2025
observação:
*/

#ifndef ESTUDANTE_H
#define ESTUDANTE_H

// estrutura
typedef struct {
    char nome[50];
    int matricula;
    float notas[3];
} Estudante;

void imprimirEstudante(Estudante e);
float calcularMedia(Estudante e);

#endif