#include<stdlib.h>
#include<stdio.h>
#include"mecanica.h"

int carregaMapa(char **mapa,int linha,int coluna)
{
	int i,j;
	FILE *ArqMapa;
	ArqMapa=fopen("Mapa.txt","r");
	for(i=0;i<linha;i++)
		for(j=0;j<coluna;j++)
			fscanf(ArqMapa," %c",&mapa[i][j]);
fclose(ArqMapa);
return 0;
}


char** criaMapa(char **mapa,int linha,int coluna)
{
int i;
mapa = malloc (linha * sizeof (char*)) ;
for (i=0; i < linha; i++)
  mapa[i] = malloc (coluna * sizeof (char)) ;
return mapa;
}

int printMapa(char **mapa,int linha,int coluna)
{
int i,j;
	for (i=0;i<linha;i++)
	{
		for (j=0;j<coluna;j++)
			printf("%c ",mapa[i][j]);
			printf("\n");
	}
return 0;
}
