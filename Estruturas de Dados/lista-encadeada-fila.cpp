#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int n;
	Node *prox;
}node;

int tam=0;

node *aloca(){
	node *novo = (node *)malloc(sizeof(node));
	if (!novo){
		printf("Nao ha memoria suficiente.\n");
		exit(1);
	}else{
		printf("Deseja adicionar o numero: \n"); scanf("%d",&novo->n);
		return novo;
	}
}

void inicia(node *fila){
	fila->prox = NULL
	tam = 0;
}

int vazia(node *fila){
	if (fila->prox == NULL)
		return 1;
	else
		return 0;
}

void push(node *fila){
	node *novo = aloca();
	novo->prox = NULL;
	if(vazia(fila)){
		fila->prox->novo;
	}else{
		node *tmp = pilha->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novo;
	}
	tam++;
}


void pop(node *fila){
	if (vazia(fila))
		printf("A lista ja esta vazia.\n");
	else{
		node *tmp = fila->prox;
		fila->prox = tmp->prox;
		tam--;
		return tmp;
	}
}

void exibe(node *fila){
	if (vazia(fila)){
			printf("A fila esta vazia\n\n");
			return ;
	}
	node *tmp = fila->prox;
	while(tmp != NULL){
		printf("%5d\t",tmp->n);
		tmp=tmp->prox;
	}
	printf("\n\n");
}

void libera(node *fila){
	if (!vazia(fila)){
		node *proxNode, *atual;
		atual = fila->prox;
		while (atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}

}

int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar fila\n");
	printf("2. Exibir fila\n");
	printf("3. Adicionar Elemento na Fila\n");
	printf("4. Retirar Elemento da Fila\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(node *FILA, int op)
{
	node *tmp;
	switch(op){
		case 0:
			libera(FILA);
			break;

		case 1:
			libera(FILA);
			inicia(FILA);
			break;

		case 2:
			exibe(FILA);
			break;

		case 3:
			push(FILA);
			break;

		case 4:
			tmp= pop(FILA);
			if(tmp != NULL){
				printf("Retirado: %3d\n\n", tmp->num);
				libera(tmp);
			}
			break;

		default:
			printf("Comando invalido\n\n");
	}
}

int main(){
	node *FILA = (node *) malloc(sizeof(node));
	if(!FILA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(FILA);
	int opt;

	do{
		opt=menu();
		opcao(FILA,opt);
	}while(opt);

	free(FILA);
	return 0;
	}
}
