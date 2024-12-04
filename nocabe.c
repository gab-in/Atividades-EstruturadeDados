#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *prox;
}No;

//Funções
No *criaCabe();
No *alocaNo(int k);
void insereLista(No *lista, int k);
void removeLista(No *lista);
void imprime(No *lista);
//

int main(){
	No *cabeca=criaCabe();//Nó cabeça só é um jeito de organizar uma lista encadeada(Lista não contígua)... Essencialmente é mais do mesmo, só que o primeiro elemento da lista não é utilizado digamos assim, ele só serve para apontar o resto da lista
	insereLista(cabeca,1);
	insereLista(cabeca,2);
	insereLista(cabeca,3);
	
	imprime(cabeca->prox);
	
	removeLista(cabeca);
	
	printf("\n\nImpressão pós remoção:");
	imprime(cabeca->prox);
	
	//Honestamente é só mais do mesmo, exatamente igual ao que eu fiz ontem, não tem porque eu gastar mais com isso 
	
	free(cabeca);
	cabeca=NULL;
	return 0;	
}

No *criaCabe(){
	No *cabeca=alocaNo(-1);
	if(!cabeca)return NULL;
	return cabeca;
}

No *alocaNo(int k){
	No *novo=NULL;
	novo = (No *)malloc(sizeof(No));
	if(!novo){
		printf("\nAlocação do cabeça inválida: ");
		return NULL;
	}
	novo->chave=k;
	novo->prox=NULL;
	return novo;
}

void insereLista(No *lista, int k){
	No *novo=alocaNo(k);
	if(!novo)return;
	novo->prox=lista->prox; //O novo já tem um valor, você diz para ele olhar para o primeiro elemento
	lista->prox=novo;//Atualiza a lista para olhar para o novo, tornando ele o primeiro elemento da lista
}

void imprime(No *lista){
	if(!lista)return;
	while(lista){
		printf("\n%d",lista->chave);
		lista=lista->prox;
	}
}

void removeLista(No *lista){
	if(!lista)return;
	No *aux=NULL;
	aux=lista->prox;//aux olha para o primeiro elemento (por completo) da lista
	lista->prox=aux->prox;//Se eu estiver correto, aux->prox é o segundo elemento, e agora lista->prox olha para ele, efetivamente tornando ele o primeiro elemento
	free(aux); // Limite a memória alocada para o ex-primeiro elemento
	aux=NULL;
}
