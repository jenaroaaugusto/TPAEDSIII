#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Inicio{
	int cont;
	int Freq;
	char palavras[50];
	int inclusa;
}FINAL;

typedef struct Ele{
	int cont; 
	int Freq;
	char palavras[50];
}temporaria;

typedef struct Elas2{
	
	int LetasASC[50];	
}ASCII;

typedef struct Elas{
	
	int palavrasASCII[50];
}temporaria2;

typedef struct Eles{
	
	int Freq;
	char palavras[50];

}Frequancia_Texto;

typedef struct Eless{
	
	int posi[500];
	char palavras[50];

}temporaria3;
typedef int TipoIndice;

//Ordenação usando o QuickSort 
void QuickSort(FINAL *vet,int esquerda,int direita);

void Verificar (char *ponteiro ,FINAL *comparar, int massa);//Verifica se a palavra já não foi inserida.

void maiusculo(char *word);//converte uma palavra para o maiusculo

int Verifica(char *origem,FINAL *comparar);
void Frequancia(temporaria *palavras,int cont);//Varifica a repetição de palavas no texto.
void Incluir(int total,char *origem,int Freq,int cont,FINAL *cadeia,int TotalPalavras);
void Hash_test(temporaria*palavras,temporaria3 *ASCII,int cont, int TAM,FINAL *cadeia,int TotalPalavras);



