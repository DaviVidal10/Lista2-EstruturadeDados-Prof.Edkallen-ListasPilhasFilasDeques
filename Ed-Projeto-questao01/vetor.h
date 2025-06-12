#ifndef VETOR_H
#define VETOR_H

typedef struct Vetor Vetor;

// Criação do vetor
Vetor* criarVetor(int capacidadeInicial);

// Inserir um elemento no final
void inserirElemento(Vetor* v, int elemento);

// Remover um elemento em uma posição
void removerElemento(Vetor* v, int posicao);

// Consulta do elemento em uma determinada posição
int obterElemento(Vetor* v, int posicao);

// Impressão dos elementos do vetor
void imprimirVetor(Vetor* v);

// Liberação da memória do vetor
void liberarVetor(Vetor* v);

#endif
