#include <stdio.h>
#define MAX_TAREFAS 50
#define MAX_CHAR 50

void addTarefa(char listaTarefas[MAX_TAREFAS][MAX_CHAR], int *contador, int status[MAX_TAREFAS]){
    if(*contador >= MAX_TAREFAS){
        printf("Limite de Tarefas Excedido!\n\n");
        return;
    }
    
    printf("\nDigite uma tarefa: ");
    getchar();
    scanf("%[^\n]", listaTarefas[*contador]);
    status[*contador] = 0;
    (*contador)++;
    printf("Tarefa Adicionada!\n\n");
}

void listarTarefas(char listaTarefas[MAX_TAREFAS][MAX_CHAR], int *contador, int status[MAX_TAREFAS]){
    if(*contador == 0){
        printf("Lista Vazia!\n\n");
        return;
    }
    printf("\n");
    for(int i=0; i<(*contador); i++){
        if(status[i] == 0){
            printf("%d. %s - PENDENTE\n", i+1, listaTarefas[i]);
        } else if(status[i] == 1){
            printf("%d. %s - CONCLUÍDA\n", i+1, listaTarefas[i]);
        }
    }
    printf("\n");
}

void marcarConcluida(char listaTarefas[MAX_TAREFAS][MAX_CHAR], int *contador, int status[MAX_TAREFAS]){
    if(*contador == 0){
        printf("Lista Vazia!\n\n");
        return;
    }
    int tarefaConcluida;
    printf("Digite qual tarefa deseja marcar como concluída (posição, de acordo com a opção 2): ");
    scanf("%d", &tarefaConcluida);
    if(tarefaConcluida < 1 || tarefaConcluida > *contador){
        printf("Elemento Inválido!\n");
        return;
    }
    status[tarefaConcluida-1] = 1;
    printf("Tarefa marcada como concluída!\n");
}

int main() {
    int opc, contador=0;
    char listaTarefas[MAX_TAREFAS][MAX_CHAR];
    int status[MAX_TAREFAS];
    while(1){
        printf("===== Lista de Tarefas =====\n");
        printf("[1] - Adicionar Tarefa\n");
        printf("[2] - Listar Tarefas\n");
        printf("[3] - Marcar como Concluída\n");
        printf("[4] - Sair do Programa\n");
        scanf("%d", &opc);
        switch(opc){
            case 1: 
                addTarefa(listaTarefas, &contador, status);
                break;
            case 2: 
                listarTarefas(listaTarefas, &contador, status);
                break;
            case 3:
                marcarConcluida(listaTarefas, &contador, status);
                break;
            case 4:
                printf("Encerrando...\n");
                return 0;
            default:
                printf("Opção Inválida!\n");
        }
    }

    return 0;
}

