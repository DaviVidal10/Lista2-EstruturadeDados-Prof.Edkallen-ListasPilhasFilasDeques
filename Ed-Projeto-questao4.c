//Projeto Edkallen
//QUESTÃO 4

/*
** Função : 
** Autor : Davi Vidal
** Data :18/06
** Observações: 
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========== TAD TAREFA ==========
typedef struct {
    char descricao[50];
    int prioridade;     // 1, 2, 3
    int dataVencimento; // DDMMYYYY
} Tarefa;

// ========== LISTA ENCADEADA ==========
typedef struct NoLista {
    Tarefa tarefa;
    struct NoLista* proximo;
} NoLista;

// ========== PILHA ==========
typedef struct NoPilha {
    Tarefa tarefa;
    struct NoPilha* proximo;
} NoPilha;

// ========== FILA ==========
typedef struct NoFila {
    Tarefa tarefa;
    struct NoFila* proximo;
} NoFila;

// ========== DEQUE ==========
typedef struct NoDeque {
    Tarefa tarefa;
    struct NoDeque* proximo;
    struct NoDeque* anterior;
} NoDeque;

// ========== VARIÁVEIS GLOBAIS ==========
NoLista* todoList = NULL;
NoPilha* pilhaConcluidas = NULL;
NoFila* filaInicio = NULL;
NoFila* filaFim = NULL;
NoDeque* dequeInicio = NULL;
NoDeque* dequeFim = NULL;

// ========== FUNÇÕES AUXILIARES ==========
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void imprimirTarefa(Tarefa t) {
    printf("Desc: %s | Prioridade: %d", t.descricao, t.prioridade);
    if (t.dataVencimento > 0) {
        printf(" | Data: %d", t.dataVencimento);
    }
    printf("\n");
}

// ========== LISTA ENCADEADA ==========
void adicionarLista(Tarefa t) {
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    novo->tarefa = t;
    novo->proximo = todoList;
    todoList = novo;
}

Tarefa removerLista() {
    if (todoList == NULL) {
        Tarefa vazia = {"", 0, 0};
        return vazia;
    }
    
    NoLista* temp = todoList;
    Tarefa t = temp->tarefa;
    todoList = todoList->proximo;
    free(temp);
    return t;
}

void mostrarLista() {
    if (todoList == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    NoLista* atual = todoList;
    int i = 1;
    while (atual != NULL) {
        printf("%d. ", i++);
        imprimirTarefa(atual->tarefa);
        atual = atual->proximo;
    }
}

// ========== PILHA ==========
void empilhar(Tarefa t) {
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    novo->tarefa = t;
    novo->proximo = pilhaConcluidas;
    pilhaConcluidas = novo;
}

void mostrarPilha() {
    if (pilhaConcluidas == NULL) {
        printf("Nenhuma tarefa concluída!\n");
        return;
    }
    
    NoPilha* atual = pilhaConcluidas;
    int i = 1;
    printf("Tarefas concluídas:\n");
    while (atual != NULL) {
        printf("%d. ", i++);
        imprimirTarefa(atual->tarefa);
        atual = atual->proximo;
    }
}

// ========== FILA ==========
void enfileirar(Tarefa t) {
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    novo->tarefa = t;
    novo->proximo = NULL;
    
    if (filaFim == NULL) {
        filaInicio = novo;
        filaFim = novo;
    } else {
        filaFim->proximo = novo;
        filaFim = novo;
    }
}

void mostrarFila() {
    if (filaInicio == NULL) {
        printf("Nenhuma tarefa agendada!\n");
        return;
    }
    
    NoFila* atual = filaInicio;
    int i = 1;
    printf("Tarefas agendadas:\n");
    while (atual != NULL) {
        printf("%d. ", i++);
        imprimirTarefa(atual->tarefa);
        atual = atual->proximo;
    }
}

// ========== DEQUE ==========
void inserirInicioDeque(Tarefa t) {
    NoDeque* novo = (NoDeque*)malloc(sizeof(NoDeque));
    novo->tarefa = t;
    novo->proximo = dequeInicio;
    novo->anterior = NULL;
    
    if (dequeInicio == NULL) {
        dequeFim = novo;
    } else {
        dequeInicio->anterior = novo;
    }
    dequeInicio = novo;
}

void inserirFimDeque(Tarefa t) {
    NoDeque* novo = (NoDeque*)malloc(sizeof(NoDeque));
    novo->tarefa = t;
    novo->proximo = NULL;
    novo->anterior = dequeFim;
    
    if (dequeFim == NULL) {
        dequeInicio = novo;
    } else {
        dequeFim->proximo = novo;
    }
    dequeFim = novo;
}

Tarefa removerInicioDeque() {
    if (dequeInicio == NULL) {
        Tarefa vazia = {"", 0, 0};
        return vazia;
    }
    
    NoDeque* temp = dequeInicio;
    Tarefa t = temp->tarefa;
    dequeInicio = temp->proximo;
    
    if (dequeInicio == NULL) {
        dequeFim = NULL;
    } else {
        dequeInicio->anterior = NULL;
    }
    
    free(temp);
    return t;
}

void mostrarDeque() {
    if (dequeInicio == NULL) {
        printf("Deque vazio!\n");
        return;
    }
    
    NoDeque* atual = dequeInicio;
    int i = 1;
    printf("Deque:\n");
    while (atual != NULL) {
        printf("%d. ", i++);
        imprimirTarefa(atual->tarefa);
        atual = atual->proximo;
    }
}

// ========== FUNÇÃO RECURSIVA ==========
int contarTarefas(NoLista* no) {
    if (no == NULL) {
        return 0;
    }
    return 1 + contarTarefas(no->proximo);
}

// ========== PRINCIPAIS FUNÇÕES ==========
void adicionarTarefa() {
    Tarefa nova;
    int temData;
    
    printf("Descrição: ");
    fgets(nova.descricao, sizeof(nova.descricao), stdin);
    nova.descricao[strcspn(nova.descricao, "\n")] = 0;
    
    printf("Prioridade (1-3): ");
    scanf("%d", &nova.prioridade);
    
    printf("Tem data? (1-Sim, 0-Não): ");
    scanf("%d", &temData);
    
    if (temData) {
        printf("Data (DDMMYYYY): ");
        scanf("%d", &nova.dataVencimento);
        enfileirar(nova);
        printf("Tarefa agendada!\n");
    } else {
        nova.dataVencimento = 0;
        adicionarLista(nova);
        printf("Tarefa adicionada!\n");
    }
    limparBuffer();
}

void concluirTarefa() {
    if (todoList == NULL) {
        printf("Nenhuma tarefa para concluir!\n");
        return;
    }
    
    Tarefa concluida = removerLista();
    empilhar(concluida);
    printf("Tarefa concluída: %s\n", concluida.descricao);
}

void menuDeque() {
    int opcao;
    
    do {
        printf("\n=== DEQUE ===\n");
        printf("1. Mover tarefa para início do deque\n");
        printf("2. Mover tarefa para fim do deque\n");
        printf("3. Remover do início do deque\n");
        printf("4. Mostrar deque\n");
        printf("0. Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch (opcao) {
            case 1:
                if (todoList != NULL) {
                    Tarefa t = removerLista();
                    inserirInicioDeque(t);
                    printf("Movido para início do deque!\n");
                } else {
                    printf("Lista vazia!\n");
                }
                break;
            case 2:
                if (todoList != NULL) {
                    Tarefa t = removerLista();
                    inserirFimDeque(t);
                    printf("Movido para fim do deque!\n");
                } else {
                    printf("Lista vazia!\n");
                }
                break;
            case 3: {
                Tarefa t = removerInicioDeque();
                if (strlen(t.descricao) > 0) {
                    printf("Removido: %s\n", t.descricao);
                }
                break;
            }
            case 4:
                mostrarDeque();
                break;
        }
    } while (opcao != 0);
}

// ========== MAIN ==========
int main() {
    int opcao;
    
    printf("=== SISTEMA DE TAREFAS ===\n");
    
    do {
        printf("\n1. Adicionar tarefa\n");
        printf("2. Mostrar To-Do List\n");
        printf("3. Concluir tarefa\n");
        printf("4. Mostrar concluídas\n");
        printf("5. Mostrar agendadas\n");
        printf("6. Menu Deque\n");
        printf("7. Contar tarefas (recursivo)\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch (opcao) {
            case 1:
                adicionarTarefa();
                break;
            case 2:
                printf("\n=== TO-DO LIST ===\n");
                mostrarLista();
                break;
            case 3:
                concluirTarefa();
                break;
            case 4:
                mostrarPilha();
                break;
            case 5:
                mostrarFila();
                break;
            case 6:
                menuDeque();
                break;
            case 7:
                printf("Total de tarefas: %d\n", contarTarefas(todoList));
                break;
            case 0:
                printf("Tchau!\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}