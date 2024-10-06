mygame: main.o fight.o riddle.o game.o
    gcc -o mygame main.o fight.o riddle.o game.o

main.o: main.c
    gcc -c main.c

fight.o: fight.c
    gcc -c fight.c

riddle.o: riddle.c
    gcc -c riddle.c

game.o: game.c
    gcc -c game.c
