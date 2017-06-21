#include <iostream>

#define ERR "Error en operacion"

using namespace std;

class Nodo{
private:
	int value;
public:
	Nodo *next;
	Nodo(void){
		next=NULL;
	}
	Nodo(int value){
		this->value=value;
		next=NULL;
	}
	int getValue(){
		return value;
	}
};

class linkedList{
private:
	Nodo *top,*tail;
public:
	linkedList(void){
		top=tail=NULL;
	}
	bool isEmpty(){
		return top==NULL;
	}
	void insert(int num){
		Nodo*temp=new Nodo(num);
		if(isEmpty()){
			top=tail=temp;
		}
		else{
			tail->next=temp;
			tail=temp;
		}
	}
	void deleteTop();
	void printList();
};

void linkedList::deleteTop(){
	if(isEmpty()){
		cout<<ERR<<endl;
		return;
	}
	else{
		Nodo *temp=top;
		top=top->next;
		delete(temp);
	}
}

void linkedList::printList(){
	Nodo *temp=top;
	while(temp!=NULL){
		cout<<temp->getValue()<<endl;
		temp=temp->next;
	}
}

int main(){
	linkedList myList;
	int num;
	for(;;){
		if(cin>>num&&num!=0)
			myList.insert(num);
		else
			break;
	}
	myList.printList();
	return 0;
}