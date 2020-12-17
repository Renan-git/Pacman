#include<stdlib.h>
#include<ncurses.h>
#include<stdio.h>
#include"mecanica.h"

int iniciancurses()
{
	initscr();
	noecho();
	cbreak();
	halfdelay(10);/*ver porque o fantasma para no movi*/
	curs_set(0);
	win = newwin(0,0,0,0);
	wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
return 0;
}




int moviPac(char **mapa,objeto *pacman,char movi,int *ponto)
{
	int aux1=0,aux2=0;
	if (movi=='w')
		aux1=-1;
	else
		if (movi=='a')
			aux2=-1;
		else
			if (movi=='s')
				aux1=1;
			else
				if (movi=='d')
					aux2=1;
	if(mapa[pacman->px+aux1][pacman->py+aux2]=='.')
		{	mapa[pacman->px+aux1][pacman->py+aux2]=mapa[pacman->px][pacman->py];
			mapa[pacman->px][pacman->py]=' ';
			mvwprintw(win,pacman->px+5,pacman->py*2+50,"%c",mapa[pacman->px][pacman->py]);
			pacman->px=pacman->px+aux1;pacman->py=pacman->py+aux2;
			mvwprintw(win,pacman->px+5,pacman->py*2+50,"%c",mapa[pacman->px][pacman->py]);
			*ponto=*ponto+1;
			mvwprintw(win,1,1,"Ponto:%.02d",*ponto);
		}
		else
			if(mapa[pacman->px+aux1][pacman->py+aux2]==' ')
			{	mapa[pacman->px+aux1][pacman->py+aux2]=mapa[pacman->px][pacman->py];
				mapa[pacman->px][pacman->py]=' ';
				mvwprintw(win,pacman->px+5,pacman->py*2+50,"%c",mapa[pacman->px][pacman->py]);
				pacman->px=pacman->px+aux1;pacman->py=pacman->py+aux2;
				mvwprintw(win,pacman->px+5,pacman->py*2+50,"%c",mapa[pacman->px][pacman->py]);
			}
return 0;
}


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
		for (j=0;j<coluna;j++)
			mvwprintw(win,i+5,j*2+50,"%c",mapa[i][j]);

return 0;
}
int resultado(int *ponto)
{
system("clear");
	if (*ponto==173)
		printf("\n\n\n\n\n\n\n\n\n\nPARABENS VOCE SAIU VIVO DO LABIRINTO\n\n\n\n\n\n\n\n\n\n%d Pontos\n\n\n\n\n\n\n\n\n\n\n\n\n\n",*ponto);
	else
		printf("\n\n\n\n\n\n\n\n\n\nINFELIZMENTE VOCE FALECEU				Pontuação:%d\n\n\n\n\n\n\n\n\n\n\n\n\n\n",*ponto);
	printf("Digite Qualquer caracter para sair\n\n\n\n\n");
	*ponto=0;
return 0;
}
void opcoes (int *op)
{
printf("\n\n\n\n");
printf("1-jogar\n2-Imprimir Rank\n3-Resetar Rank\n0-Sair");
scanf(" %d",op);
}
