#include <stdio.h>
#define TAM 5
typedef struct endereco{
	int CEP, num;
}TEnd;
typedef struct aluno{
	char nome[20];
	float coef[2];
	TEnd endereco;
}TAluno;

int main(){
	
	TAluno valunos[TAM];
	int i;
	
	printf("tamanho %d", sizeof(valunos));
	printf("tamanho %d", sizeof(valunos[0].nome));
	
	
	//Definição aluno
	for(i=0;i<TAM;i++){
		printf("\nInforme o nome do aluno %d:",i+1);
		scanf("%[^\n]",valunos[i].nome);
		setbuf(stdin,NULL);
		
		printf("\nInforme CEP: ");
		scanf("%d",&valunos[i].endereco.CEP);
		setbuf(stdin,NULL);
		
		printf("\nInforme o número da casa: ");
		scanf("%d",&valunos[i].endereco.num);
		setbuf(stdin,NULL);
	}
	//Saída
	
	for(i=0;i<TAM;i++){
		printf("\n\nAluno: %s",&valunos[i].nome);
		printf("\nCEP: %d",&valunos[1].endereco.CEP);
		printf("\nNúmero da casa: %d", &valunos[i].endereco.num);
	}
	
}
