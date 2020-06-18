prog:main.o  vie.o
	gcc main.o  vie.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g

 
vie.o:vie.c 
	gcc -c vie.c -lSDL -lSDL_image -g 
