ortografia.o : main.c fantasma.c mecanica.c rank.c mecanica.h fantasma.h rank.h
			gcc main.c fantasma.c mecanica.c rank.c -lncurses -g  -o pacman.o
