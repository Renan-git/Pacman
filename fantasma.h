#ifndef  FANTASMA_H
#define  FANTASMA_H

int iniciaCordenadas (objeto *pacman,objeto *fantasma1,objeto *fantasma2,objeto *fantasma3,objeto *fantasma4);
int printfantasma(objeto *fant);
int fantasmaPercegue(char **mapa,objeto pacman,objeto *fant);
int fantasmaDistancia(char **mapa,char movi,objeto *fant);
int fantasmaAleatorio(char **mapa,char movi,objeto *fant);
int colisao (objeto pacman,objeto fantasma);


#endif  /*FILE_H*/
