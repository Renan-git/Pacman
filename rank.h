#ifndef  RANK_H
#define  RANK_H

typedef struct jogador
{
	char Nome[50];
	int Pontos;
}jogador;

int leNome(jogador *player);
int recebeRank(jogador v[]);
int imprimeRank(jogador v[]);
void bubbleSort(jogador *v, int n);
void swap(int *a, int *b);
int inserirPlayer(jogador v[],jogador player);
void swapstring(char *a,char *b);
int resetRank (jogador v[]);
int moveRank(jogador v[]);


#endif  /*FILE_H*/
