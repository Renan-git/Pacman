#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"rank.h"

int leNome(jogador *player)
{
printf("Insira o Seu Nome:");
scanf(" %[^\n]s",player->Nome);
return 0;
}

int recebeRank(jogador v[])
{
int i;

FILE *Rank;
	Rank=fopen("rank.txt","r");
for (i=0;i<10;i++)
{
	fscanf(Rank," %[^\n]s",v[i].Nome);
	fscanf(Rank,"%d",&v[i].Pontos);
}
fclose(Rank);
return 0;
}

int imprimeRank(jogador v[])
{
int i;
system("clear");
for (i=0;i<10;i++)
	printf("%d-%s:%d\n",(i+1),v[i].Nome,v[i].Pontos);
return 0;
}

void bubbleSort(jogador *v, int n)
{ 
    if (n < 1)return; 
 
    for (int i=0; i<n; i++) 
        if (v[i].Pontos < v[i+1].Pontos) 
            {swap(&v[i].Pontos, &v[i+1].Pontos);swapstring(v[i].Nome, v[i+1].Nome);}  
    bubbleSort(v, n-1); 
} 
void swap(int *a, int *b)
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}
void swapstring(char *a,char *b)
{
char aux[50];
	strcpy(aux,a); 
    strcpy(a,b);
    strcpy(b,aux);
}
int inserirPlayer(jogador v[],jogador player)
{
	v[10].Pontos=player.Pontos;
	strcpy(v[10].Nome,player.Nome);
return 0;
}
int moveRank(jogador v[])
{
int i=5;
FILE *Rank;
	Rank=fopen("rank.txt","w");
	for (i=0;i<10;i++)
		fprintf(Rank,"%s\n%d\n",v[i].Nome,v[i].Pontos);
fclose(Rank);
return 0;
}
int resetRank (jogador v[])
{
int i;
	for(i=0;i<=10;i++)
	{	
		strcpy(v[i].Nome,"#");
		v[i].Pontos=0;
	}
return 0;
}
