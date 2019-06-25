run: Main.o Matriz.o 
	g++ Main.o Matriz.o -o run
Main.o: Main.cpp Matriz.h 
	g++ -c Main.cpp
Matriz.o: Matriz.h Matriz.cpp
	g++ -c Matriz.cpp
