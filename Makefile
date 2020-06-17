prog:main.o enigma.o
	gcc main.o enigma.o -o prog -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL -ldl -lm -g
main.o:main.c
	gcc -c main.c -g
enigma.o:enigma.c
	gcc -c enigma.c -g
