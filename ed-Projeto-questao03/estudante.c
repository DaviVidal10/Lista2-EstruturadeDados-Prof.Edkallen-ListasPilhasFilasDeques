/*
Função: Vetor de Inteiros
Autor: Carlos Eduardo
Data:14/06/2025
observação:
*/

#include <stdio.h>
#include "estudante.h"

void imprimirEstudante(Estudante e) {
    printf("Nome: %s\n", e.nome);
    printf("Matrícula: %d\n", e.matricula);
    printf("Notas: %.2f, %.2f, %.2f\n", e.notas[0], e.notas[1], e.notas[2]);
}

float calcularMedia(Estudante e) {
    return (e.notas[0] + e.notas[1] + e.notas[2]) / 3.0;
}