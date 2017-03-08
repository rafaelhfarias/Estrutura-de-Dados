#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int n;
	struct Node *prox;
}node;

int tam;

int menu(void){
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar lista\n");
	printf("2. Exibir lista\n");
	printf("3. Push\n");
	printf("4. Pop\n");
	printf("Opcao: "); scanf("%d",&opt);
	return opt;
}


void inicia(node *lista){
	lista->prox =NULL;
	tam =0;
}

int vazia(node *lista){
	if(lista->prox == NULL)
		return 1;
	else
		return 0;
}

node *aloca(){
	node *novo = (node *)malloc(sizeof(node));
	if (!novo){
		printf("Nao ha memoria suficiente\n");
		exit(1);
	}else{
		printf ("Novo elemento: "); scanf("%d",&novo->n);
		return novo;
	}
}

void push(node *lista){
	node *novo = aloca();
	novo->prox = NULL;
	if (vazia(lista)){
		lista->prox = novo;
	}
	else{
		node *tmp = lista->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
	tmp->prox = novo;
	}
	tam++;
}

node *pop(node *lista){
	if(lista->prox == NULL){
		printf("A lista ja esta vazia\n");
		return NULL;
	}
	else{
		node *ultimo = lista->prox, *penultimo = lista;
		while (ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		penultimo->prox = NULL;
		tam--;
		return ultimo;
	}
}

void exibe(node *lista){
	if (vazia(lista)){
		printf("A lista esta vazia.\n\n");
		return ;
	}
	node *tmp;
	tmp = lista->prox;
	printf("A lista:\n");
	while(tmp != NULL){
		printf("%5d",tmp->n);
		tmp = tmp->prox;
	}
	printf("\n\n");
}


void libera(node *lista){
	if (!vazia(lista)){
		node *proxNode, *atual;

		atual = lista->prox;
		while (atual!= NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

void opcao(node *lista, int op)
{
 node *tmp;
 switch(op){
  case 0:
   libera(lista);
   break;

  case 1:
   libera(lista);
   inicia(lista);
   break;

  case 2:
   exibe(lista);
   break;

  case 3:
   push(lista);
   break;

  case 4:
   tmp= pop(lista);
   if(tmp != NULL)
   printf("Retirado: %3d\n\n", tmp->n);
   break;

  default:
   printf("Comando invalido\n\n");
 }
}



int main(){
	node *lista = (node *)malloc(sizeof(node));
	if(!lista){
		printf("Sem memoria disponivel\n");
		exit(1);
	}else{
		inicia(lista);
		int opt;

		do{
			opt=menu();
			opcao(lista,opt);
		}while(opt);
		
		free(lista);
		return 0;
	}
}
