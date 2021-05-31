CC = g++ --std=c++11
INC = rsdl.cpp -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: output.out 

output.out: main.o map.o game.o mario.o clay.o pipe.o question.o enemies.o
	${CC} main.o game.o map.o mario.o clay.o pipe.o question.o enemies.o ${INC} -o output.out

main.o: main.cpp map.o game.o
	${CC} -c main.cpp

game.o: game.h game.cpp
	${CC} -c game.cpp

map.o: map.h map.cpp
	${CC} -c map.cpp

mario.o: mario.cpp mario.h
	${CC} -c mario.cpp

clay.o: clay.cpp clay.h
	${CC} -c clay.cpp 

pipe.o: pipe.cpp pipe.h
	${CC} -c pipe.cpp

question.o: question.cpp question.h
	${CC} -c question.cpp

enemies.o: enemies.cpp enemies.h
	${CC} -c enemies.cpp

clean:
	rm *.o
	rm output.out
