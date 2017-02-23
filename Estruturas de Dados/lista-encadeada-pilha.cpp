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
	printf("1. Zerar pilha\n");
	printf("2. Exibir pilha\n");
	printf("3. Push\n");
	printf("4. Pop\n");
	printf("Opcao: "); scanf("%d",&opt);
	return opt;
}


void inicia(node *pilha){
	pilha->prox =NULL;
	tam =0;
}

int vazia(node *pilha){
	if(pilha->prox == NULL)
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

void push(node *pilha){
	node *novo = aloca();
	novo->prox = NULL;
	if (vazia(pilha)){
		pilha->prox = novo;
	}
	else{
		node *tmp = pilha->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
	tmp->prox = novo;
	}
	tam++;
}

node *pop(node *pilha){
	if(pilha->prox == NULL){
		printf("A pilha ja esta vazia\n");
		return NULL;
	}
	else{
		node *ultimo = pilha->prox, *penultimo = pilha;
		while (ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		penultimo->prox = NULL;
		tam--;
		return ultimo;
	}
}

void exibe(node *pilha){
	if (vazia(pilha)){
		printf("A pilha esta vazia.\n\n");
		return ;
	}
	node *tmp;
	tmp = pilha->prox;
	printf("A pilha:\n");
	while(tmp != NULL){
		printf("%5d",tmp->n);
		tmp = tmp->prox;
	}
	printf("\n\n");
}


void libera(node *pilha){
	if (!vazia(pilha)){
		node *proxNode, *atual;

		atual = pilha->prox;
		while (atual!= NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

void opcao(node *PILHA, int op)
{
 node *tmp;
 switch(op){
  case 0:
   libera(PILHA);
   break;

  case 1:
   libera(PILHA);
   inicia(PILHA);
   break;

  case 2:
   exibe(PILHA);
   break;

  case 3:
   push(PILHA);
   break;

  case 4:
   tmp= pop(PILHA);
   if(tmp != NULL)
   printf("Retirado: %3d\n\n", tmp->n);
   break;

  default:
   printf("Comando invalido\n\n");
 }
}



int main(){
	node *pilha = (node *)malloc(sizeof(node));
	if(!pilha){
		printf("Sem memoria disponivel\n");
		exit(1);
	}else{
		inicia(pilha);
		int opt;

		do{
			opt=menu();
			opcao(pilha,opt);
		}while(opt);
		
		free(pilha);
		return 0;
	}
}
