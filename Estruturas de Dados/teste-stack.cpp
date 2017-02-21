#include <stdio.h>
#include <stdlib.h>
#define TAM 2
float stack[TAM];
int tamanho = 0;

int vazio(float v[TAM], int tamanho){
	if (tamanho == 0) return 1;
	else return 0;
}

void exibe(float v[TAM], int t){
	if (!vazio(v,tamanho)){
		printf("A sua pilha eh:\n");
		for (int i=0;i<tamanho;i++){
			printf("%f\t",v[i]);
		}
	}
	else{
		printf("A pilha esta vazia.\n\n");
	}
}

void push(float v[TAM], int t){
	float n;
	if (t<TAM){
		printf("Digite o numero que deseja adicionar a pilha:\n");
		scanf("%f",&n);
		v[tamanho]=n;
		tamanho++;
		printf("Numero adicionado com sucesso\n");
	}
	if (tamanho == TAM) printf("A pilha esta cheia\n");
}

void pop(float v[TAM], int t){
	if (!vazio(v,t)){
		v[tamanho] =0;
		tamanho--;
	}
	else printf("A pilha esta vazia.\n");
}

	
int main(){
	int op=1;
	while (op != 0){
				printf("Digite a sua opcao:\n1)Exibir\n2)Adicionar\n3)Remover\n\nOpcao: ");
		scanf("%d",&op);
		if(op == 1){
			exibe(stack,tamanho);
		}
		if (op == 2){
			push(stack,tamanho);
		}
		if (op ==3){
			pop(stack,tamanho);
		}
	}

	return 0;
}
