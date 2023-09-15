#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Fila {
    int capacidade;
    char **nomes;
    char **senhas;
    int primeiro;
    int ultimo;
    int nItens;
};

void criarFila(struct Fila *f, int c) {
    f->capacidade = c;
    f->nomes = (char **)malloc(f->capacidade * sizeof(char *));
    f->senhas = (char **)malloc(f->capacidade * sizeof(char *));
    f->primeiro = 0;
    f->ultimo = -1;
    f->nItens = 0;
}

void inserir(struct Fila *f, char *nome, char *senha) {
    if (f->ultimo == f->capacidade - 1)
        f->ultimo = -1;

    f->ultimo++;
    f->nomes[f->ultimo] = nome;
    f->senhas[f->ultimo] = senha;
    f->nItens++;
}

int remover(struct Fila *f) {
    char *senha = f->senhas[f->primeiro];
    f->primeiro++;

    if (f->primeiro == f->capacidade)
        f->primeiro = 0;

    f->nItens--;
    return senha;
}

int estaVazia(struct Fila *f) {
    return (f->nItens == 0);
}

int estaCheia(struct Fila *f) {
    return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f) {
    int cont, i;

    for (cont = 0, i = f->primeiro; cont < f->nItens; cont++) {
        printf("Posição: %d | Nome: %s | Senha: %s\n", cont + 1, f->nomes[i], f->senhas[i]);

        i = (i + 1) % f->capacidade;
    }
    printf("\n");
}

int main() {
	
	system("chcp 65001");
    int opcao, capa;
    char nome[50];
    char senha[50];
    struct Fila umaFila;

    // cria a fila
    printf("Capacidade da fila? ");
    scanf("%d", &capa);
    criarFila(&umaFila, capa);

    // apresenta menu
    while (1) {
        printf("1 - Inserir cliente\n2 - Chamar próximo cliente\n3 - Mostrar fila de clientes\n0 - Sair\n\nOpção? ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                exit(0);

            case 1: // insere cliente
                if (estaCheia(&umaFila)) {
                    printf("Fila Cheia!\n\n");
                } else {
                    printf("Nome do cliente: ");
                    scanf("%s", nome);

                    int senhaIncremental = umaFila.nItens + 1;  // Gera a senha incremental   
                    sprintf(senha, "%d", senhaIncremental);

                    inserir(&umaFila, nome, senha);
                }
                break;


            case 2: // chamar próximo cliente
                if (estaVazia(&umaFila)) {
                    printf("Fila Vazia!\n\n");
                } else {
                    char *senhaChamada = remover(&umaFila);
                    printf("Chamando cliente: Senha %s\n\n", senhaChamada);
                }
                break;

            case 3: // mostrar fila de clientes
                if (estaVazia(&umaFila)) {
                    printf("Fila Vazia!\n\n");
                } else {
                    printf("Conteúdo da fila de clientes:\n");
                    mostrarFila(&umaFila);
                }
                break;

            default:
                printf("Opção Inválida!\n\n");
        }
    }
    return 0;
}