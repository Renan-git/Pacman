#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include"mecanica.h"
#include"fantasma.h"
#include"rank.h"

//Falta tirar os link Pointer
int main ()
{

char **Mapa,movi='0';
objeto pacman,fantasma1,fantasma2,fantasma3,fantasma4;
int ponto=0,colidiu=0,op=1;
/*cordenadas pacman*/
jogador v[11];jogador player;
recebeRank(v);

while (op)
{
opcoes(&op);/*imprime Opções*/
	if (op==1)
	{
		leNome(&player);
		colidiu=0;
		iniciaCordenadas(&pacman,&fantasma1,&fantasma2,&fantasma3,&fantasma4);
		iniciancurses();

		Mapa=criaMapa(Mapa,TAMLINHA,TAMCOLUNA);
		carregaMapa(Mapa,TAMLINHA,TAMCOLUNA);
		printMapa(Mapa,TAMLINHA,TAMCOLUNA);

		while((movi!='q') && (ponto<173) && !colidiu)
		{
			wrefresh(win);
			fantasmaPercegue(Mapa,pacman,&fantasma1);
			fantasmaDistancia(Mapa,movi,&fantasma2);
			fantasmaAleatorio(Mapa,movi,&fantasma3);fantasmaAleatorio(Mapa,movi,&fantasma4);
			printfantasma(&fantasma1);printfantasma(&fantasma2);printfantasma(&fantasma3);printfantasma(&fantasma4);
			colidiu=colisao(pacman,fantasma1)+colisao(pacman,fantasma2)+colisao(pacman,fantasma3)+colisao(pacman,fantasma4);
			
			movi=wgetch(win);//movimento do Pacman
			moviPac(Mapa,&pacman,movi,&ponto);
		}
		endwin();
		player.Pontos=ponto;
		inserirPlayer(v,player);
		bubbleSort(v,10);
		resultado(&ponto);
	}
	else
		if(op==2)
		{
			bubbleSort(v,10);
			imprimeRank(v);
		}
		else
			if (op==3)
				resetRank(v);
}
moveRank(v);/*atualiza o rank.txt*/
return 0;
}
