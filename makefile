prog:maintest.o  animation.o scrolling.o collision.o
	gcc maintest.o animation.o scrolling.o collision.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
maintest.o:maintest.c
	gcc -c maintest.c -g
animation.o:animation.c
	gcc -c animation.c -g
scrolling.o:scrolling.c
	gcc -c scrolling.c -g
collision.o:collision.c
	gcc -c collision.c -g
	


clean:
	rm *.o prog
