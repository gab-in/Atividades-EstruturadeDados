#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *prox;
}No;


No *alocaNo(int k);
void insereLista(No **p, int k);
void removeLista(No **p);
void imprimir(No *p);


int main(){
	No *lista=NULL;
	int aux=0,op,k;
	
	printf("\n\n----------------------------------------------------------------------------------------");
	printf("\nInsira o primeiro elemento da lista (Deve ser um int):");
	printf("\n----------------------------------------------------------------------------------------\nDigite: ");
	scanf("%d",&k);
	
	lista=alocaNo(k);
	
	while(!aux){
		printf("\n\n----------------------------------------------------------------------------------------");
		printf("\n1-Inserir novo elemento | 2-Remover elemento mais recente | 3-Imprimir lista | 4-Sair");
		printf("\n----------------------------------------------------------------------------------------\nDigite: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("\nInsira o novo elemento: ");
				scanf("%d",&k);
				insereLista(&lista,k);
				break;
			case 2:
				removeLista(&lista);
				break;
			case 3:
				imprimir(lista);
				break;
			case 4:
				aux++;
				break;
			default:
				printf("\nOpção inválida!!");
				break;
		}//chave do switch
	}//chave do while
	free(lista);
	lista=NULL;
	
	printf("\n\n----------------------------------------------------------------------------------------");
	printf("\nFim do programa!!");
	printf("\n----------------------------------------------------------------------------------------");
}//chave da main






No *alocaNo(int k){
	printf("\n\n\n----------------------------------------------------------------------------------------");
	printf("\nAlocando nó . . .");	
	printf("\n----------------------------------------------------------------------------------------");
	
	No *novo=(No *)malloc(sizeof(No));
	
	if(!novo){
	printf("\n\n----------------------------------------------------------------------------------------");
	printf("\nAlocação dinâmica falhou!");
	printf("\n----------------------------------------------------------------------------------------");
	return NULL;
	}
	
	printf("\n----------------------------------------------------------------------------------------");
	printf("\nSucesso!!");
	printf("\n----------------------------------------------------------------------------------------\n");
	novo->chave=k;
	novo->prox=NULL;
	return novo;
	
	
}//chave do alocaNo

void insereLista(No **p, int k){
	No *novo=NULL;
	novo = alocaNo(k);
	
	if(!novo)return;
	novo->prox=*p;
	*p=novo;
}//chave do insireLista

void removeLista(No **p){
	if(!*p){
		printf("\n\n----------------------------------------------------------------------------------------");
		printf("\nLista Vazia!!");
		printf("\n----------------------------------------------------------------------------------------\n");
		return;
	}
	
	No *aux=*p;
	*p=(*p)->prox;
	free(aux);
	aux=NULL;

	return;
}//chave do removeLista
void imprimir(No *p){
	printf("\n\n----------------------------------------------------------------------------------------");
	while(p){
		printf("\n:%d",p->chave);
		p=p->prox;
	}//chave do while
	printf("\n----------------------------------------------------------------------------------------");
	return;
}//chave do imprimir
