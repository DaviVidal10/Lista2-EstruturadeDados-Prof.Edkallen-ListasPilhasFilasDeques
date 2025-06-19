//Projeto Edkallen
//QUESTÃO 2

/*
** Função : Marcação de consultas ou atendimentos.
** Autor : Davi Vidal
** Data :10/06
** Observações: Símbolos como ❌  e  ✅ foram ideias que peguei da IA. Também usei o chat gpt para relembrar como zerar ou diminuir o número de pacientes de acordo com que fossem atendidos. f->total-- é oque zera o número de pacientes nas funções "atenderMedico" e "atenderEnfermagem", conforme são atendidos. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_MEDICO 5

// estrutura do paciente
typedef struct {
    int id;
    char nome[MAX_NOME];
    char data[11];
} Paciente;

// fila estática - médico (limite de 5 pessoas)
typedef struct {
    Paciente pacientes[MAX_MEDICO];
    int inicio, fim, total;
} FilaMedico;

// fila dinâmica - enfermagem (sem limites)
typedef struct No {
    Paciente paciente;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int total;
} FilaEnfermagem;

// funções médico
void iniciarFilaMedico(FilaMedico* f) {
    f->inicio = f->fim = f->total = 0;
}

int agendarMedico(FilaMedico* f, Paciente p) {
    if (f->total >= MAX_MEDICO) {
        printf(" ❌ Médico lotado! Máximo %d consultas.\n", MAX_MEDICO);
        return 0;
    }
    f->pacientes[f->fim] = p;
    f->fim = (f->fim + 1) % MAX_MEDICO;
    f->total++;
    printf("✅ Agendado com MÉDICO: %s\n", p.nome);
    return 1;
}

int atenderMedico(FilaMedico* f) {
    if (f->total == 0) {
        printf("Nenhum paciente na fila do médico.\n");
        return 0;
    }
    printf("Atendido pelo MÉDICO: %s\n", f->pacientes[f->inicio].nome);
    f->inicio = (f->inicio + 1) % MAX_MEDICO;
    f->total--;
    return 1;
}

void listarMedico(FilaMedico* f) {
    if (f->total == 0) {
        printf("Fila do médico vazia.\n");
        return;
    }
    printf("\nFILA MÉDICO (%d/%d):\n", f->total, MAX_MEDICO);
    int i = f->inicio;
    for (int j = 0; j < f->total; j++) {
        printf("%d. %s - %s\n", j+1, f->pacientes[i].nome, f->pacientes[i].data);
        i = (i + 1) % MAX_MEDICO;
    }
}

// funções enfermagem 
void iniciarFilaEnfermagem(FilaEnfermagem* f) {
    f->inicio = f->fim = NULL;
    f->total = 0;
}

int agendarEnfermagem(FilaEnfermagem* f, Paciente p) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) return 0;
    
    novo->paciente = p;
    novo->proximo = NULL;
    
    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
    f->total++;
    printf("✅ Agendado com ENFERMAGEM: %s\n", p.nome);
    return 1;
}

int atenderEnfermagem(FilaEnfermagem* f) {
    if (f->inicio == NULL) {
        printf("Nenhum paciente na fila da enfermagem.\n");
        return 0;
    }
    No* temp = f->inicio;
    printf("Atendido pela ENFERMAGEM: %s\n", temp->paciente.nome);
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) f->fim = NULL;
    f->total--;
    free(temp);
    return 1;
}

void listarEnfermagem(FilaEnfermagem* f) {
    if (f->inicio == NULL) {
        printf("Fila da enfermagem vazia.\n");
        return;
    }
    printf("\nFILA ENFERMAGEM (%d consultas):\n", f->total);
    No* atual = f->inicio;
    int i = 1;
    while (atual) {
        printf("%d. %s - %s\n", i++, atual->paciente.nome, atual->paciente.data);
        atual = atual->proximo;
    }
}

void liberarEnfermagem(FilaEnfermagem* f) {
    while (f->inicio) {
        atenderEnfermagem(f);
    }
}

// principais funções  
Paciente criarPaciente(int id) {
    Paciente p;
    p.id = id;
    
    printf("Nome do paciente: ");
    scanf(" %[^\n]", p.nome);
    
    printf("Data (DD/MM/AAAA): ");
    scanf("%s", p.data);
    
    return p;
}

void menu() {
    printf("\n=== CLÍNICA MÉDICA ===\n");
    printf("1. Agendar com Médico\n");
    printf("2. Agendar com Enfermagem\n");
    printf("3. Atender Médico\n");
    printf("4. Atender Enfermagem\n");
    printf("5. Lista Médico\n");
    printf("6. Lista Enfermagem\n");
    printf("0. Sair\n");
    printf("Opção: ");
}

int main() {
    FilaMedico medico;
    FilaEnfermagem enfermagem;
    
    iniciarFilaMedico(&medico);
    iniciarFilaEnfermagem(&enfermagem);
    
    int opcao, id = 1;
    
    do {
        menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                agendarMedico(&medico, criarPaciente(id++));
                break;
            case 2:
                agendarEnfermagem(&enfermagem, criarPaciente(id++));
                break;
            case 3:
                atenderMedico(&medico);
                break;
            case 4:
                atenderEnfermagem(&enfermagem);
                break;
            case 5:
                listarMedico(&medico);
                break;
            case 6:
                listarEnfermagem(&enfermagem);
                break;
            case 0:
                printf("Encerrando...\n");
                liberarEnfermagem(&enfermagem);
                break;
            default:
                printf("❌ Opção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}