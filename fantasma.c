#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include"mecanica.h"

int iniciaCordenadas (objeto *pacman,objeto *fantasma1,objeto *fantasma2,objeto *fantasma3,objeto *fantasma4)
{
	pacman->px=10;pacman->py=1;
	fantasma1->px=10;fantasma1->py=9;
	fantasma2->px=10;fantasma2->py=10;
	fantasma3->px=11;fantasma3->py=9;
	fantasma4->px=11;fantasma4->py=10;
return 0;
}

int printfantasma(objeto *fant)
{
int i,j;
	i=fant->px;j=fant->py;
	mvwprintw(win,i+5,j*2+50,"+");
	
return 0;
}

int fantasmaAleatorio(char **mapa,char movi,objeto *fant)
{
int i;
	i=(rand()%4);
	mvwprintw(win,fant->px+5,fant->py*2+50,"%c",mapa[fant->px][fant->py]);/*atualiza o ponto anterior do fantasma*/

	if ((mapa[fant->px-1][fant->py]!='H') && (i==0))/*cima*/
		fant->px=fant->px-1;
	else
		if ((mapa[fant->px][fant->py-1]!='H')&&(i==1))/*esquerda*/
			fant->py=fant->py-1;
		else
			if ((mapa[fant->px+1][fant->py]!='H')&&(i==2))/*baixo*/
				fant->px=fant->px+1;
			else
				if ((mapa[fant->px][fant->py+1]!='H')&&(i==3))/*direita*/
					fant->py=fant->py+1;

return 0;
}

int fantasmaDistancia(char **mapa,char movi,objeto *fant)
{
	mvwprintw(win,fant->px+5,fant->py*2+50,"%c",mapa[fant->px][fant->py]);/*atualiza o ponto anterior do fantasma*/

	if ((mapa[fant->px-1][fant->py]!='H') && (movi=='w'))/*cima*/
		fant->px=fant->px-1;
	else
		if ((mapa[fant->px][fant->py-1]!='H')&&(movi=='a'))/*esquerda*/
			fant->py=fant->py-1;
		else
			if ((mapa[fant->px+1][fant->py]!='H')&&(movi=='s'))/*baixo*/
				fant->px=fant->px+1;
			else
				if ((mapa[fant->px][fant->py+1]!='H')&&(movi=='d'))/*direita*/
					fant->py=fant->py+1;

return 0;
}

int fantasmaPercegue(char **mapa,objeto pacman,objeto *fant)
{
	mvwprintw(win,fant->px+5,fant->py*2+50,"%c",mapa[fant->px][fant->py]);/*atualiza o ponto anterior do fantasma*/

	if ((mapa[fant->px-1][fant->py]!='H')&&(pacman.px<fant->px))/*cima*/
		fant->px=fant->px-1;
	else
		if ((mapa[fant->px][fant->py-1]!='H')&&(pacman.py<fant->py))/*esquerda*/
			fant->py=fant->py-1;
		else
			if ((mapa[fant->px+1][fant->py]!='H')&&(pacman.px>fant->px))/*baixo*/
				fant->px=fant->px+1;
			else
				if ((mapa[fant->px][fant->py+1]!='H')&&(pacman.py>fant->py))/*direita*/
					fant->py=fant->py+1;
return 0;
}

int colisao (objeto pacman,objeto fantasma)
{
	if ((pacman.px==fantasma.px)&&(pacman.py==fantasma.py))
		return 1;
return 0;
}
