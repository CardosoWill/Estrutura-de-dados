#include <stdio.h>
#include <stdlib.h>

struct node{
	int nDado;
	struct node *next;
};

// Mostrar a lista
void display(struct node *p){
	printf("mostrando a lista: \n");
	if(p){

		do{
			printf("%d\n", p->nDado);
		p=p->next;
		} while(p);
	} else {
		printf("Lista vazia.\n");
	}
}

int main(void) {
	
	struct node *pNode1 = NULL;
	struct node *pNode2 = NULL;
	struct node *pNode3 = NULL;
	struct node *pNode99 = NULL;
	struct node *pNodeNew = NULL;
	

	//Criando os Nodes e associar os dados
	pNode1 = (struct node*) malloc(sizeof(struct node*));
	pNode1->nDado = 10;
	
	pNode2 = (struct node*) malljoc(sizeof(struct node*));
	pNode2->nDado = 20;
	
	pNode3 = (struct node*) malloc(sizeof(struct node*));
	pNode3->nDado = 30;
	
	pNode99 = (struct node*) malloc(sizeof(struct node*));
	pNode99->nDado = 99;

	pNodeNew = (struct node*) malloc(sizeof(struct node*));
	pNodeNew->nDado = 1;


	//Conectando os nos
	pNode1->next = pNodeNew;
	pNodeNew->next = pNode2;
	pNode2->next = pNode3;			
	pNode3->next = pNode99; 
	pNode99->next = NULL;

		if(pNode1){
			display(pNode1);
		}
	return 0;
}