#include <stdlib.h>
#include <stdio.h>
#include"mecanica.h"

int main ()
{
char **Mapa;

Mapa=criaMapa(Mapa,TAMLINHA,TAMCOLUNA);
carregaMapa(Mapa,TAMLINHA,TAMCOLUNA);
printMapa(Mapa,TAMLINHA,TAMCOLUNA);

return 0;
}
