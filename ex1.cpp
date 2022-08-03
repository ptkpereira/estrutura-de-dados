#include <stdio.h>
#include <stdlib.h>

// Inicializa as funções para reconhecimento
int menu();
void inserirMusica();
void listarMusicas();

// Cria uma lista encadeada simples não circular
struct Musica {
	char nome[50];
	char artista[50];
	float duracao;
	struct Musica *prox;
} *Head;

int main() {
	int op, c;

	while (1) {
		// Exibe o menu e recebe a opção pelo input
		op = menu();
		switch (op)
		{
		case 1:
			inserirMusica();
			break;
		case 2:
			listarMusicas();
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
	return 0;
}

int menu() {
	// Exibe as opções do menu e retorna a opção escolhida

	int op;
	printf("Cpotify\n");
	printf("------------------\n");
	printf("1.Inserir musica\n");
	printf("2.Listar musicas da playlist\n");
	printf("3.Sair\n");
	printf("Digite sua escolha: ");

	scanf("%d", &op);
	fflush(stdin);

	return op;
}

void inserirMusica() {
	
	// Nova música do tipo ponteiro da scruct Musica
	Musica *NovaMusica; 
	// Aloca espaço na memória para a nova musica do tamanho da struct Musica
	NovaMusica = (struct Musica *)malloc(sizeof(struct Musica)); 
	// Cria uma variável de varredura
	Musica *Varredura;
	Varredura = (struct Musica *)malloc(sizeof(struct Musica));
	
	// Recebe os dados da nova musica pelo input
	printf("Digite o nome da musica: ");
	fgets(NovaMusica->nome, 50, stdin);
	fflush(stdin);
	printf("Digite o artista: ");
	fgets(NovaMusica->artista, 50, stdin);
	fflush(stdin);
	printf("Digite a duracao: ");
	scanf("%f", &NovaMusica->duracao);

	// Se Head for nulo, a lista está vazia, recebe a nova musica no Head
	if (Head == NULL) {
		Head = NovaMusica;
		Head->prox = NULL;
	} else {
		// Se houver musicas, encontra o último elemento, como é uma lista não circular,
		// o último elemento tem o próximo nulo
		Varredura = Head;
		while (Varredura->prox != NULL) {
			Varredura = Varredura->prox;
		}
		// Define a nova músiva como próximo do valor que estava como último
		Varredura->prox = NovaMusica;
		// Define nulo pois é não circular
		NovaMusica->prox = NULL;
	}
}

void listarMusicas() {

	// Aloca na memória a variável que será usada para varredura
	Musica *Varredura;
	Varredura = (struct Musica *)malloc(sizeof(struct Musica));

	// Inicializa no head, ou seja, início da lista
	Varredura = Head;
	if (Varredura == NULL) {
		printf("Playlist vazia\n");
		return;
	}
	printf("-----Playlist-----\n");

	// Imprime as musicas até encontrar um valor nulo
	while(Varredura != NULL) {
		printf("Nome: %s", Varredura->nome);
		printf("Artista: %s", Varredura->artista);
		printf("Duração: %.2f", Varredura->duracao);
		printf("\n------------------\n");

		// Como é uma lista não circular, o último será nulo, portanto vai parar o loop
		Varredura = Varredura->prox;
	}
	printf("\n");
}