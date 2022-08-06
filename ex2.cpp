#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Registro heterogênero para armazenar cada elemento da ávore binária
struct Aluno
{
    char nome[50];
    char email[50];
    int ru;
    struct Aluno *esquerda, *direita;
};

// Inicializa as funções para reconhecimento
int menu();
void buscarAluno(Aluno **ElementoVarredura, int num);

int main()
{
    int op;

    // Inicia todas as variáveis para os 10 alunos e aloca memória para eles
    Aluno *aluno1, *aluno2, *aluno3, *aluno4, *aluno5, *aluno6, *aluno7, *aluno8, *aluno9, *aluno10;
    aluno1 = (Aluno *)malloc(sizeof(Aluno));
    aluno2 = (Aluno *)malloc(sizeof(Aluno));
    aluno3 = (Aluno *)malloc(sizeof(Aluno));
    aluno4 = (Aluno *)malloc(sizeof(Aluno));
    aluno5 = (Aluno *)malloc(sizeof(Aluno));
    aluno6 = (Aluno *)malloc(sizeof(Aluno));
    aluno7 = (Aluno *)malloc(sizeof(Aluno));
    aluno8 = (Aluno *)malloc(sizeof(Aluno));
    aluno9 = (Aluno *)malloc(sizeof(Aluno));
    aluno10 = (Aluno *)malloc(sizeof(Aluno));

    // Adiciona o RU para o aluno
    aluno1->ru = 3298195;
    // Adiciona o nome para o aluno, como aqui é um array, precisa usar a funcão strcpy
    strcpy(aluno1->nome, "Marina");
    strcpy(aluno1->email, "marina@email.com");
    // O primeiro elemento da arvóre não possui elemento a esquerda
    aluno1->esquerda = NULL;
    // Os alunos com ru maiores ficam sempre a direita, para que a árvore está em ordem crescente
    aluno1->direita = aluno2;

    aluno2->ru = 3298196;
    strcpy(aluno2->nome, "Joao");
    strcpy(aluno2->email, "joao@email.com");
    aluno2->esquerda = aluno1;
    aluno2->direita = aluno3;

    aluno3->ru = 3298197;
    strcpy(aluno3->nome, "Jose");
    strcpy(aluno3->email, "jose@email.com");
    aluno3->esquerda = aluno2;
    aluno3->direita = aluno4;

    aluno4->ru = 3298198;
    strcpy(aluno4->nome, "Maria");
    strcpy(aluno4->email, "maria@email.com");
    aluno4->esquerda = aluno3;
    aluno4->direita = aluno5;

    aluno5->ru = 3298199;
    strcpy(aluno5->nome, "Patrick");
    strcpy(aluno5->email, "patrick@email.com");
    aluno5->esquerda = aluno4;
    aluno5->direita = aluno6;

    aluno6->ru = 3298200;
    strcpy(aluno6->nome, "Roberto");
    strcpy(aluno6->email, "roberto@email.com");
    aluno6->esquerda = aluno5;
    aluno6->direita = aluno7;

    aluno7->ru = 3298201;
    strcpy(aluno7->nome, "Olivia");
    strcpy(aluno7->email, "olivia@email.com");
    aluno7->esquerda = aluno6;
    aluno7->direita = aluno8;

    aluno8->ru = 3298202;
    strcpy(aluno8->nome, "Rafael");
    strcpy(aluno8->email, "rafael@email.com");
    aluno8->esquerda = aluno7;
    aluno8->direita = aluno9;

    aluno9->ru = 3298203;
    strcpy(aluno9->nome, "Vera");
    strcpy(aluno9->email, "vera@email.com");
    aluno9->esquerda = aluno8;
    aluno9->direita = aluno10;

    // O último elemento da árvore não possui elementos a direita
    aluno10->ru = 3298204;
    strcpy(aluno10->nome, "Thiago");
    strcpy(aluno10->email, "thiago@email.com");
    aluno10->esquerda = aluno9;
    aluno10->direita = NULL;

    // Loop infinito para pesquisar múltiplas vezes
    while (1)
    {
        op = menu();
        // chama a busca passando o root, que é o aluno1 e o RU que está sendo buscado
        buscarAluno(&aluno1, op);
    }
}

int menu()
{
    // Exibe o menu e retorna o RU para buscar
    int op;
    printf("\nBuscar Aluno\n");
    printf("------------------\n");
    printf("Digite o RU para buscar o aluno: ");
    scanf("%d", &op);
    fflush(stdin);

    return op;
}

void buscarAluno(Aluno **ElementoVarredura, int num)
{
    // A árvore está em ordem crescente, esquerda são menores e direita maiores
    // Para buscar, verifica se o elemento atual é menor ou maior que o RU buscado

    // Mensagem de erro caso o RU não seja encontrado
    if (*ElementoVarredura == NULL)
    {
        printf("RU não encontrado.\n");
    }

    // Se o RU buscado for menor que o elemento atual, retorna recursivamente buscando pelos elementos da esquerda
    else if (num < (*ElementoVarredura)->ru)
    {
        buscarAluno(&((*ElementoVarredura)->esquerda), num);
    }
    else
    {
        // Se o RU buscado for maior que o elemento atual, retorna recursivamente buscando pelos elementos da direita
        if (num > (*ElementoVarredura)->ru)
        {
            buscarAluno(&((*ElementoVarredura)->direita), num);
        }
        else
        {
            // Quando achar o RU, exibe na tela o nome e email do aluno
            if (num == (*ElementoVarredura)->ru)
            {
                printf("Encontrado:\n");
                printf("%s\n", (*ElementoVarredura)->nome);
                printf("%s\n", (*ElementoVarredura)->email);
            }
        }
    }
}