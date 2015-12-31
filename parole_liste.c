#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	char *parola;
	int contatore;
	struct nodo* prossimo;};

char len(char* frase){
	int cont=0;
	int i=0;
	while(frase[i]!='\0'){
		if(frase[i]==' ')
			cont++;
		i++;
	}
	cont++;
	return cont;
}

void insert(char parola[],struct nodo** head){
	struct nodo* new;
	if(*head==NULL || strcmp(parola,(*head)->parola)<0){
		new=malloc(sizeof(struct nodo));
		new->parola=parola;
		new->contatore=1;
		new->prossimo=*head;
		*head=new;
	}
	else
		if(strcmp((*head)->parola,parola)==0)
			(*head)->contatore++;
		else
			insert(parola,&((*head)->prossimo));
}

struct nodo* split(char* frase, int lung){
	char** parole;
	char* parola;
	struct nodo* head;
	int i=0,j=0,k=0;
	head=NULL;
	//parole=malloc(sizeof(char*)*lung);
	i=0;
	while(frase[i]!='\0'){
		j=0;
		parola=malloc(sizeof(char)*20);
		while(frase[i]!=' ' && frase[i]!='\0'){
			parola[j]=frase[i];
			j++;
			i++;
			}
		parola[j]='\0';
		insert(parola,&head);
		//parole[k]=parola;
		k++;
		if(frase[i]!='\0') i++;
	}
	//while(head->prossimo!=NULL)
	//	printf("Parola: %s\nContatore: %d\n\n",head->parola,head->contatore);
	return head;
}

int conta_parole(char frase[], char parola[]){
	int i,cont=0;
	struct nodo* head;
	char** parole;
	int num_parole;
	head=NULL;
	num_parole=len(frase);
	head=split(frase, num_parole);
	while(head!=NULL){
		if(strcmp(parola,head->parola)==0){
			cont=head->contatore;
			}
		printf("Parola: %s\nContatore: %d\n\n",head->parola,head->contatore);
		head=head->prossimo;}
	return cont;
}

int main(){
	int conta;
	struct nodo* head=NULL;
	conta=conta_parole("lago lascian nuovi lago lago lago lascian nuovi allocchio allocchio","lago");
	printf("%d\n",conta);
	return 0;
}
