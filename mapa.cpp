#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
void constroiMatriz(int matriz[][20]){
FILE *arq;
	char num[400];//tamanho total da matriz	
	arq=fopen("mapa.txt","r"); 
	if(arq==NULL){
		exit(1);
	} // checa se pode abrir arquivo
	for(int i=0;i<20;i++)
	{	
 		 fgets(num,400,arq);
		 for(int j=0;j<strlen(num);j++){
			if(num[j]=='1')
				matriz[j][i]=1;
			else if (num[j]=='0')
				matriz[j][i]=0;
		 }
	}
	fclose(arq);
}

void inicializaMatriz(int matriz[][20]){
	int a, b; 
	for (a=0;a<20;a++){
		for (b=0;b<20;b++){
			matriz[a][b]=0;
		}
	}
}


	
int main(){ 
	int mat[20][20];
   	inicializaMatriz(mat);
   	constroiMatriz(mat);

	int i,j;

	for(i=0;i<20;i++){
printf("\n");
		for(j=0;j<20;j++){

	printf("%d",mat[i][j]);
	
	}
		}	


return 0;
}
