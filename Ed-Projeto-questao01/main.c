#include <stdio.h>
#include "vetor.h"

int main() {
    Vetor* v = criarVetor(4);

    inserirElemento(v, 10);
    inserirElemento(v, 20);
    inserirElemento(v, 30);
    inserirElemento(v, 40);

    imprimirVetor(v);

    removerElemento(v, 1); 
    
    imprimirVetor(v);

    printf("Elemento na posição 1: %d\n", obterElemento(v, 1));

    inserirElemento(v, 50);
    inserirElemento(v, 60);
    imprimirVetor(v);

    liberarVetor(v);
    return 0;
}
