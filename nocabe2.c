//Essa é uma outra forma de organizar o "Nó Cabeça" numa lista não contígua, portanto o código é baseado no último que eu fiz, por fins de facilidade

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *prox;
}No;

typedef struct cabeca{
	int total;
	struct no *ini, *fim;
}Cabeca;

//Funções
Cabeca *criaCabe();
No *alocaNo(int k);
void insereLista(Cabeca *lista, int k);
void removeLista(Cabeca *lista);
void imprime(No *lista);
//

int main(){
	Cabeca *cabeca=criaCabe();//Antes ele usava alocaNo();, agora ele é uma função sozinha que aloca por si, porque o No Cabeça é uma struct completamente diferente
	
	insereLista(cabeca,1);
	insereLista(cabeca,2);
	insereLista(cabeca,3);
	
	imprime(cabeca->ini);
	
	removeLista(cabeca);
	
	printf("\n\nImpressão pós remoção:");
	imprime(cabeca->ini);
	
	//Honestamente é só mais do mesmo, exatamente igual ao que eu fiz ontem, não tem porque eu gastar mais com isso 
	
	free(cabeca);
	cabeca=NULL;
	return 0;	
}

Cabeca *criaCabe(){
	Cabeca *ptr=NULL;
	
	ptr=(Cabeca *)malloc(sizeof(Cabeca));
	if(!ptr)return NULL;
	
	ptr->total=0;
	ptr->ini=NULL;
	ptr->fim=NULL;
	
	return ptr;
}


void insereLista(Cabeca *lista, int k){
	No *novo=alocaNo(k);// Novo elemento criado
	if(!novo)return;
	
	if(!lista->fim){ //Verifica se existe primeiro elemento
		lista->fim=novo;//Como é o primeiro elemento adicionado, então novo é o último elemento também
		lista->ini=novo;
		return;
	}
	
	novo->prox=lista->ini;//Já tem elementos, o novo elemento olha para o ex-primeiro da lista
	lista->ini=novo;//Atualiza a lista para olhar para o novo, tornando ele o primeiro elemento da lista
	lista->total++;//Aumenta a contagem do número de elementos
}


void removeLista(Cabeca *lista){
	if(!lista)return;
	No *aux=NULL;
	aux=lista->ini;//aux olha para o primeiro elemento (por completo) da lista
	lista->ini=aux->prox;//Se eu estiver correto, aux->prox é o segundo elemento, e agora lista->ini olha para ele, efetivamente tornando ele o primeiro elemento
	free(aux); // Limite a memória alocada para o ex-primeiro elemento
	aux=NULL;
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

void imprime(No *lista){
	if(!lista)return;
	while(lista){
		printf("\n%d",lista->chave);
		lista=lista->prox;
	}
}
