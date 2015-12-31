#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char** split(char* frase, int lung){
	char** parole;
	char* parola;
	int i=0,j=0,k=0;
	parole=malloc(sizeof(char*)*lung);
	i=0;
	while(frase[i]!='\0'){
		j=0;
		parola=malloc(sizeof(char)*20);
		while(frase[i]!=' ' && frase[i]!='\0'){
			parola[j]=frase[i];
			j++;
			i++;
			}
		parole[k]=parola;
		k++;
		if(frase[i]!='\0') i++;
	}
	return parole;
}

int conta_parole(char frase[], char parola[]){
	int i,cont=0;
	char** parole;
	int num_parole;
	num_parole=len(frase);
	parole=split(frase, num_parole);
	for(i=0;i<num_parole;i++)
		if (strcmp(parole[i],parola)==0)
			cont++;
	return cont;
}

int main(){
	int conta;
conta=conta_parole("rallentarsi golfi le interrotte golfi tutto distendersi le interrotte golfi","golfi");
	printf("Conta=%d\n",conta);
conta=conta_parole("sensibile sensibile ancor sensibile sensibile e sensibile sensibile e parte","sensibile");
	printf("Conta=%d\n",conta);
	return 0;
}
