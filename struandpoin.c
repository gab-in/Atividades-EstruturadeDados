#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
char nome[50];
int ra;
int idade;
} TipoAluno;

TipoAluno *aloca(){
	TipoAluno *pa;
	pa=(TipoAluno *)malloc(sizeof(TipoAluno));
	if(pa==NULL) return NULL;
	return pa;
} //FUnçã de alocação de memória... Retorna um TipoAluno, retorna um ponteiro, por isso ela é ambos.

void alterar(TipoAluno *paluno){
	printf("\nNome: \n");
	fgets(paluno->nome,50,stdin);
	
	printf("\nRA: \n");
	scanf("%d",&(paluno->ra));
	
	printf("\nIdade: \n");
	scanf("%d",&(paluno->idade));
} //Função basiquinha de alteração

void liberar(TipoAluno **p){
	free(*p);
	*p=NULL;
}

void main(){
	TipoAluno *p; //Ponteiro para receber um TipoAluno
	p=aloca(); //Chama função de alocação de memória para um aluno novo, recebe um endereço de memória
	alterar(p); //Chama função para alterar o espaço de memória em questão
	printf("\nAluno %s inserido!",p->nome); //Usando o mesmo ponteiro utilizado antes, fala o nome criado
	
	liberar(&p); //Não tenho certeza se tá certo
}

