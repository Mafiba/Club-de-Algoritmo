#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *next;
}Tnodo,*Ptrnodo;

typedef struct{
	Ptrnodo top, tail;
}Tcola, *Cola;

void push(Cola c, int numb){
	Ptrnodo _new=(Ptrnodo)malloc(sizeof(Tnodo));
	_new->num=numb;
	if(empty(c)){
		c->top=c->tail=_new;
	}
	else{
		c->tail->next=_new;
		c->tail=_new;
	}
} 

int pop(Cola c) {
	if(empty(c))
		exit(1);
	else{
	int numb=c->top->num;
	Ptrnodo aux=c->top;
	c->top=c->top->next;
	free(aux);
	return numb;
	}
}

Cola initcola (){
	Cola c=(Cola)malloc(sizeof(Tcola));
	c->top=c->tail=NULL;
	return c;
}

int empty(Cola c){
	return (c->top==NULL);
}