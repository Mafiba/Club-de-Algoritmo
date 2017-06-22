#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *next;
}Tnodo, *ptrnodo;

typedef struct stack{
	ptrnodo top;
}Tstack, *stack;

int Empty(stack s){return(s->top==NULL);}

void push(stack s, int numb){
	ptrnodo new=(ptrnodo)malloc(sizeof(Tnodo));
	new->num=numb;
	new->next=s->top;
	s->top=new;
}

stack initStack(){
	stack s=(stack)malloc(sizeof(Tstack));
	s->top=NULL;
	return s;
}

int pop (stack s){
	if(Empty(s)==0){
	ptrnodo temp=s->top;
	int numb=s->top->num;
	s->top=s->top->next;
	free(temp);
	return numb;
	}
}