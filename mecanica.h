#ifndef  MECANICA_H
#define  MECANICA_H

#define TAMLINHA 20
#define TAMCOLUNA 20

WINDOW * win;


typedef struct objeto
{
	int px;
	int py;
}objeto;

int iniciancurses();
char** criaMapa(char **mapa,int linha,int coluna);
int printMapa(char **mapa,int linha,int coluna);
int carregaMapa(char **mapa,int linha,int coluna);
int moviPac(char **mapa,objeto *pacman,char movi,int *ponto);
int resultado(int *ponto);
void opcoes ();


#endif  /*FILE_H*/
