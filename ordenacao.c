#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8

struct aluno {
	char nome[81];
	char mat[8];
	char turma;
	char email[41];
};
typedef struct aluno Aluno;


void bolha_gen(int, void*, int tam, int (*cmp)(void*,void*));
int compara_int(void*, void*);
int compara_reais(void*, void*);
int compara_inteiro(const void*, const void*);
int compara_aluno (void*, void*);
int (*cmp)(void*,void*);
void* acessa(void* v, int i, int tam);
void troca(void*a, void*b, int tam);
Aluno* cadastraAluno(int, Aluno**, int);
void inicializa(int, Aluno**);
void imprimeTodosAluno(int,Aluno**);


int main(int argc, char *argv[]) {

	int i, k;
	printf("Digite a quantidade de alunos: ");
	scanf("%d", &k);
	printf("\n");
	Aluno* alunos[k];
	inicializa(k, alunos);
	for(i = 0; i < k; i++){
		cadastraAluno(k, alunos, i);
	}

	imprimeTodosAluno(k, alunos);
	
	int Root;
	do{
		printf("\n\n------> Escolha o tipo de ordenacao <-----\n");
		printf(" \t (1): Nome");
		printf(" \t (0): Sair");
		
		printf("\n\t --->");
		scanf("%d", &Root);
		printf("\n\n");
		
		switch(Root){
			case 1:
				bolha_gen(k, alunos, sizeof(Aluno), compara_aluno);
				imprimeTodosAluno(k, alunos);
			break;
		}
	}while(Root!=0);
	
}

void inicializa(int n, Aluno** a){
	int i;
	for(i=0;i<n;i++){
		a[i] = NULL;
	}
}

Aluno* cadastraAluno(int n, Aluno** a, int i){
	if(i<0 || i>=n){
		exit(1);
	}
	
	if(a[i] == NULL){
		a[i] = (Aluno*)malloc(sizeof(Aluno));
		
		printf("\n");
		printf("Digite o nome: ");
		scanf("%s", &a[i]->nome);
		
		printf("Digite a matricula: ");
		scanf("%s", a[i]->mat);
		
		fflush(stdin);
		printf("Digite a turma: ");
		scanf("%c", &a[i]->turma);
		
		printf("Digite o email: ");
		scanf("%s", &a[i]->email);
		
		printf("\n");

	}
	
}

void imprimeTodosAluno(int n, Aluno** a){
	int i;
	for(i=0;i<n;i++){
		imprime(n,a,i);
	}
}

void imprime(int n, Aluno** a, int i){
	if(i < 0 || i>= n){
		exit(1);
	}
	if(a[i]!=NULL){
		printf("\n---- Aluno {%d} ----\n", i+1);
		printf("Nome: %s\n", a[i]->nome);
		printf("Matricula: %s\n", a[i]->mat);
		printf("Turma: %c\n", a[i]->turma);
		printf("E-mail: %s\n", a[i]->email);
		printf("\n--------------------\n");
	}
}

void bolha_gen (int n, void* v, int tam, int(*cmp)(void*,void*)){
	int i, j;
	for (i=n-1; i>0; i--) {
		int fez_troca = 0;
		for (j=0; j<i; j++) {
			void* p1 = acessa(v,j,tam);
			void* p2 = acessa(v,j+1,tam);
			if (cmp(p1,p2)) {
				printf("\t\t\t\tteste.....4");
				troca(p1,p2,tam);
				fez_troca = 1;
			}
			printf("\t\t\t\tteste.....5");
			
			
		}
		if (fez_troca == 0)
		return;
	}
}

int compara_int(void* a, void* b){
	int* p1 = (int*) a;
	int* p2 = (int*) b;
	int f1 = *p1;
	int f2 = *p2;
	if(f1 > f2) return 1;
	else return 0;
}

void* acessa (void* v, int i, int tam){
	char* t = (char*)v;
	t += tam*i;
	return (void*)t;
}

void troca(void* a, void* b, int tam){
	char* v1 = (char*) a;
	char* v2 = (char*) b;
	int i;
	for (i=0; i<tam; i++) {
		char temp = v1[i];
		v1[i] = v2[i];
		v2[i] = temp;
	}
}

int compara_reais(void* a, void* b){
	float* p1 = (float*) a;
	float* p2 = (float*) b;
	float f1 = *p1;
	float f2 = *p2;
	if(f1 > f2) return 1;
	else return 0;
}

int compara_aluno (void* a, void* b){
	Aluno** p1 = (Aluno**) a;
	Aluno** p2 = (Aluno**) b;
	Aluno* i1 = *p1;
	Aluno* i2 = *p2;
	if (strcmp(i1->nome,i2->nome) > 0) return 1;
	else return 0;
}
