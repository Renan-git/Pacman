#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include"mecanica.h"

int main ()
{
char **Mapa,movi='0';
objeto pacman,fantasm1,fantasm2,fantasm3,fantasm4;
int ponto=0;
/*cordenadas pacman*/
pacman.px=10;pacman.py=1;

initscr();
noecho();
cbreak();
curs_set(0);
win = newwin(0,0,0,0);
wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');

Mapa=criaMapa(Mapa,TAMLINHA,TAMCOLUNA);
carregaMapa(Mapa,TAMLINHA,TAMCOLUNA);
printMapa(Mapa,TAMLINHA,TAMCOLUNA);

while(movi!='q')
{

	wrefresh(win);
	scanf(" %c",&movi);//movimento do Pacman
	moviPac(Mapa,&pacman,movi,&ponto);
}
endwin();
return 0;
}
