# run with the following command: make uno
uno: game_state.o colors.h card.o main.o
	g++ main.o card.o game_state.o -o uno -std=c++11

game_state.o: game_state.cpp  colors.h
	g++ -c game_state.cpp -std=c++11
	
card.o: card.cpp colors.h
	g++ -c card.cpp -std=c++11

main.o: main.cpp colors.h
	g++ -c main.cpp -std=c++11

clean: 
	rm *.o uno