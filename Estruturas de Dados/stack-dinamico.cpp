#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int n;
	struct Node *prox;
}node;

int tam;

void inicia(node *pilha){
	pilha -> prox =NULL;
	tam =0
}

node *aloca(){
	node *novo = (node *)malloc(sizeof(node));
	if (!node){
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
			tmp = tmp-prox;
	tmp->prox = novo;
	}
	tam++;
}

node *pop(node *pilha){
	if(pilha->prox == NULL)
		printf("A pilha ja esta vazia\n");
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
