.DEFAULT_GOAL = jogo

jogador.o: jogador.cpp jogador.h
	g++ jogador.cpp -c
jogo.o: jogo.cpp jogo.h
	g++ jogo.cpp -c

jogo: main.cpp jogador.o jogo.o
	g++ main.cpp jogador.o jogo.o -o jogo

clear:
	rm *.o
	rm jogo
