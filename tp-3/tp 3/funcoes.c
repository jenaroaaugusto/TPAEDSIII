#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "head.h"

//Ordenação usando o QuickSort 
void QuickSort(FINAL *vet,int esquerda,int direita){
	int i, j;
    i = esquerda;
    j = direita;
    FINAL aux;
    FINAL pivo;
    pivo = vet[(esquerda + direita) / 2];

    while(i <= j){
        int controli = 0 ,controlj =0;
        while(vet[i].Freq >= pivo.Freq && i < direita && controli == 0){
            if(vet[i].Freq > pivo.Freq){
                i++;
            }
            else{
                int l = strcmp(vet[i].palavras,pivo.palavras);
                if (l < 0){
                    i++;
                }
                else{
                    controli = 1;
                }
            }
        }
        while(vet[j].Freq <= pivo.Freq && j > esquerda && controlj == 0){
             if(vet[j].Freq < pivo.Freq){
                j--;
            }
            else{
                int l = strcmp(vet[j].palavras,pivo.palavras);
                if (l > 0){
                    j--;
                }
                else{
                    controlj = 1;
                }
            }
        }
        if(i <= j){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }
    if(j > esquerda){
        QuickSort(vet, esquerda, j);
    }
    if(i < direita){
        QuickSort(vet,  i, direita);
    }
}

void Verificar (char *ponteiro ,FINAL *comparar, int massa){
	int i=0;
	for(i=0;i<256;i++){
		if (strcmp(ponteiro,comparar[i].palavras)==0){
			comparar[i].inclusa=0;
		}
	}
} 

void maiusculo(char *word){//converte uma palavra para o maiusculo
  long int i=0;
  for(i=0;i<strlen(word);i++){
    word[i]=tolower(word[i]);
  }
}

int Verifica(char *origem,FINAL *comparar){
	int i;
	for (i=0;i<256;i++){
		if(strcmp(origem,comparar[i].palavras)==0){
			return 0;
		}
	}
	return 2;
}
void Frequancia(temporaria *palavras,int cont){//Varifica a repetição de palavas no texto.
	//Frequancia_Texto *freq;
	int i=0,j=0;
	int cont_freq=0;
	
	for (i = 0; i < cont; i++){
		for(j=0;j<cont;j++){
			if(strlen(palavras[i].palavras)>2){
				if(strcmp(palavras[i].palavras,palavras[j].palavras)==0){
					palavras[i].Freq=cont_freq++;
				}	
			}
		}	
		palavras[i].Freq=cont_freq;
		cont_freq=0;
	}
}

void Incluir(int total,char *origem,int Freq,int cont,FINAL *cadeia,int TotalPalavras){
	int i=0,Nk=3; 
	
	Nk=Verifica(origem,cadeia);
	if(Nk==2){
		if(cadeia[total].cont==0 && cadeia[total].inclusa==1){
			
		
			strcpy(cadeia[total].palavras,origem);
			cadeia[total].cont=1;
			cadeia[total].Freq=Freq;

			Verificar(origem,cadeia,TotalPalavras);
		}else{
			
			if(cadeia[total+1].cont==0 && cadeia[total+1].inclusa==1 && Nk==2){
				strcpy(cadeia[total+1].palavras,origem);

				cadeia[total+1].cont=1;
				cadeia[total+1].Freq=Freq;

				total++;
				
				Verificar(origem,cadeia,TotalPalavras);
			}else{
		
				int complemento=total;
				complemento=complemento+2;
				
				while(cadeia[complemento].cont==0 && complemento<=256 && cadeia[complemento].inclusa==1 && Nk==2){
					//printf("Entro Else--\n");
					strcpy(cadeia[complemento].palavras,origem);
					cadeia[complemento].cont=1;
					cadeia[complemento].Freq=Freq;

					Verificar(origem,cadeia,TotalPalavras);	
				}
			}		
		}
	}
}
void Hash_test(temporaria*palavras,temporaria3 *ASCII,int cont, int TAM,FINAL *cadeia,int TotalPalavras){
	int k=0,j=0;
	int stringT=0;
	int total=0;
			
	for(j=0;j<TAM;j++){

		total=total+(ASCII[cont].posi[j] * j);
	}

	total=total % 256;
	Incluir(total,palavras[cont].palavras,palavras[cont].Freq,cont,cadeia,TotalPalavras);
	//printf("Posição na Hash %d\n",total);//Calcula a hash da Palavra. 
}
