// Buscar um aluno em uma estrutura de arvore binaria ou hash
// armazenar nome, email e RU -> heterogenea
// nao precisa ler os dados dos aluno, pode deixar ja registrado 10, meu precisa estar
// menu, pedir pra digitar ru, se achar mostrar nome e mail, se nao achar, mostrar mensagem de erro
// captura de tela com meu ru

#include <stdio.h>
#include <stdlib.h>

// Inicializa as funções para reconhecimento
void factory();
int menu();

struct Aluno
{
  char nome[50];
  char email[50];
  int ru;
  struct Aluno *direita, *esquerda;
};

struct Aluno aluno1, aluno2, aluno3, aluno4, aluno5, aluno6, aluno7, aluno8, aluno9, aluno10;

int main()
{
}

int menu()
{
}

void factory()
{
  aluno1 = {
      "Joao",
      "joao@email.com",
      1234,
      NULL,
      &aluno2};

  aluno2 = {
      "Maria",
      "maria@email.com",
      1234,
      &aluno1,
      NULL};

  aluno3 = {
      "Maria",
      "maria@email.com",
      1234,
      &aluno1,
      NULL};

  aluno4 = {
      "Maria",
      "maria@email.com",
      1234,
      &aluno1,
      NULL};

  aluno5 = {
      "Maria",
      "maria@email.com",
      1234,
      &aluno1,
      NULL};

  aluno6 = {
      "Maria",
      "maria@email.com",
      1234,
      &aluno1,
      NULL};

  aluno7 = {
      "Maria",
      "maria@email.com",
      1234,
      &aluno1,
      NULL};

  aluno8 = {
      "Maria",
      "maria@email.com",
      1234,
      &aluno1,
      NULL};

  aluno9 = {
      "Maria",
      "maria@email.com",
      1234,
      &aluno1,
      NULL};

  aluno10 = {
      "Maria",
      "maria@email.com",
      1234,
      &aluno1,
      NULL};
}

void buscarAluno()
{
}