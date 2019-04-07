prog:maintest.o  jeux.o
	gcc maintest.o jeux.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
maintest.o:maintest.c
	gcc -c maintest.c -g
jeux.o:jeux.c
	gcc -c jeux.c -g

	


clean:
	rm *.o prog
