#include "head.h"

int main(int argc,char *argv[]){

	//ponteiro para arquivo de leitura
	FILE *arquivo;
	FINAL cadeia[256];
	Frequancia_Texto freq[256];


	//contadores
	int j=0,cont=0,s=0;
	int i=0,n=0,A=0;
	long ArqTamanho=0;
	printf("Nome %s\n",argv[1]);
	arquivo=fopen(argv[1],"r");

	fseek(arquivo, 0, SEEK_END);

	ArqTamanho=ftell(arquivo);
	
	fseek(arquivo, 0, SEEK_SET);
	//Base palavras[256];
	temporaria aux[ArqTamanho];
	ASCII aux4[ArqTamanho];
	
	printf("%li\n",ArqTamanho);
	char letras[ArqTamanho];
	int temp=0;
	for(i=0;i<256;i++){

		aux[i].cont=0;
		cadeia[i].cont=0;
		cadeia[i].inclusa=1;
	}
	j=0;
	
		printf("I=%i\n",i);
		

	//leitura do arquivo e armazena no vetor
	cont = 0;
	i = 0;
	while(!feof(arquivo)){
		fscanf(arquivo,"%s",aux[i].palavras);
		cont++;
		i++;
	}
	int tamanhos=0;

	//remoção de caracteres especiais
	for(i = 0; i < cont; i++){
		for(j = 0; j < strlen(aux[i].palavras);j++){
			if(aux[i].palavras[j] == ' '){
				aux[i].palavras[j] = '\0';
				

			}else if(aux[i].palavras[j] == ','){
				aux[i].palavras[j] = '\0';
			
			}else if(aux[i].palavras[j] == '!'){
				aux[i].palavras[j] = '\0';
				

			}else if(aux[i].palavras[j]=='-'){
				aux[i].palavras[j] = '\0';
				

			}else if(aux[i].palavras[j]=='.'){
				aux[i].palavras[j] = '\0';
				

			}else if(aux[i].palavras[j]=='.'){
				aux[i].palavras[j] = '\0';
				
			}
		}
	}
 	A=0;
 
 	for(i=0;i<256;i++){
	 		
			freq[i].Freq=0;
		} 

 	temporaria3 AUX5[400];
 	for(i=0;i<400;i++){
 		for(j=0;j<50;j++){
			AUX5[i].posi[j]=0;
		}
	}
	for(i=0;i<cont;i++){
		maiusculo(aux[i].palavras);

	}
	int contTemp=0,contTemp2=0,posicao=0;
	printf("Numero de Palavras %d\n",cont);
	contTemp=cont;
	contTemp2=cont;
	Frequancia(aux,contTemp2);
 	for (i = 0; i <cont; ++i){
 		A = strlen(aux[i].palavras);

 		for (j = 0; j < A; ++j){
 		
 			AUX5[i].posi[j]=aux[i].palavras[j];

 		}
 		

 		if(A==1){
 			contTemp--;
 			
 		}
 		if(A>2){
 			posicao=i;
 			
 			Hash_test(aux,AUX5,posicao,A,cadeia,contTemp);
 			
 		}else if(A==1){
 		
 		}
	}
	contTemp=256;
	int esquerda=0;
	QuickSort(cadeia,esquerda,contTemp);
	for(i=0;i<256;i++){
		if(cadeia[i].Freq>=2){
			if(strlen(cadeia[i].palavras)>=2){
				printf("Freq->%d Palavras->%s \n",cadeia[i].Freq ,cadeia[i].palavras);
			}
		}
	}
fclose(arquivo);
return 0;	
}
