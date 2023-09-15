#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Estrutura Utilizada
struct Node {
    int data;
    struct Node* next;
};

//Iniciar uma pilha vazia
struct Node* initialize(){
    return NULL;
};

//Verifica se a pilha está vazia
bool isEmpty(struct Node* top){
return top == NULL;
};

//Adicionar elemento no topo da pilha
struct Node* push(struct Node* top/*pilha*/,int value/*Valor a ser armazenado*/){
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
if(newNode == NULL){
printf("falha na alocação de memória. Não é possível adicionar novos elementos");
return top;
}
newNode->data = value;
newNode->next = top;
return newNode;
};

//Verifica o tamanho da pilha
int size(struct Node* top){

int count = 0;
struct Node* temp = top;
while(temp != NULL){
count++;
temp = temp->next;
}
return count;
}

// Obtem a estrutura no topo da pilha 
int peek(struct Node* top) {
	if (isEmpty(top)){
		printf("Pilha vazia! nao ha elementos para mostrar. \n");
		exit(EXIT_FAILURE);
	}
	return top->data;
}

//Remover do topo da  pilha 
struct Node* pop(struct Node* top) {
	if(isEmpty(top)){
	printf("Pilha vazia! nao ha elementos para mostrar. \n");
	return top;	
	}
	
	struct Node* temp = top;
	top = top->next;
	free(temp);
	return top;
	
}


//Função Principal
int main(){
struct Node* stack = initialize();
int choice,value;
while(1){
printf("Menu\n"
   "1. Empilhar (Push)\n"
   "2. Desempilhar (pop)\n"
   "3. Ver topo (peek)\n"
   "4. Ver tamanho da pilha\n"
   "5. Sair \n"
   "Escolha uma opcao\n");
scanf("%d",&choice);
switch(choice){
case 1:{
printf("Digite um valor a ser empilhado\n");
scanf("%d",&value);
stack = push(stack, value);
}

case 2:{
	if(isEmpty(stack)){
		stack = pop(stack);
		printf("Valor desempilhado.\n");
	}else{
		printf("Pilha vazia!\n");
	}
	break;
}

case 3:{
	if(!isEmpty(stack)){
		value=peek(stack);
		printf("Valor no topo da pilha: %d\n", value);
	} else {
		printf("Pilha vazia!\n");
	}
	break;
}

case 4:{
printf("Tamanho da pilha: %d\n",size(stack));
break;
}

case 5:{
	while(!isEmpty(stack)){
		stack = pop(stack);
	}
	exit(EXIT_SUCCESS);
	default:
		printf("erro\n");
	
}


}
}
return 0;
}