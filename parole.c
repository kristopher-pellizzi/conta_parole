#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	char* parola;
	int cont;
	struct nodo* prossimo;
	};

void insert(char* parola,struct nodo** head){
	struct nodo* new;
	if(*head==NULL || strcmp(parola,(*head)->parola)<0){
		new=malloc(sizeof(struct nodo));
		new->parola=parola;
		new->cont=1;
		new->prossimo=*head;
		*head=new;}
	else
		if(strcmp(parola,(*head)->parola)==0)
			(*head)->cont++;
		else
			insert(parola,&((*head)->prossimo));
}

struct nodo* split(char* frase,int len){
	struct nodo* parole;
	char* parola;
	parole=NULL;
	int i=0,lung_par=0,j,k=0,ind=0;
	while(frase[i]!='\0'){
		lung_par=0;
		k=0;
		while(frase[i]!=' ' && frase[i]!='\0'){
			lung_par++;
			i++;}
		parola=malloc(sizeof(char)*lung_par+1);
		for(j=i-lung_par;j<i;j++){
			parola[k++]=frase[j];}
		parola[k]='\0';
		if(frase[i]!='\0') i++;
		insert(parola,&parole);
	}
	return parole;
}

int len(char* frase){
	int i=0,cont=0;
	while(frase[i]!='\0'){
		if(frase[i]==' ')
			cont++;
		i++;
		}
	cont++;
	return cont;
}

int conta_parole(char* frase, char* parola){
	int i,cont=0;
	int lung_frase;
	struct nodo* parole;
	parole=NULL;
	lung_frase=len(frase);
	parole=split(frase,lung_frase);
	while(parole!=NULL){
		if(strcmp(parola,parole->parola)==0)
			cont=parole->cont;
		parole=parole->prossimo;}
	return cont;
}

int main(){
	int i,conta=0;
	char** parole;
	conta=conta_parole("destra destra le dallaltra allocchio allocchio trasformazione le allocchio due","allocchio");	
	printf("%d\n",conta);
	return 0;
}
