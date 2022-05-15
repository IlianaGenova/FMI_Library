all: output

output: Main.o Library.o Author.o Book.o
	g++ -std=c++0x -Wall Main.o Library.o Author.o Book.o -o output

Main.o: Main.cpp
	g++ -c Main.cpp

Library.o: Library.cpp Library.hpp
	g++ -c Library.cpp

Author.o: Author.cpp Author.hpp
	g++ -c Author.cpp

Book.o: Book.cpp Book.hpp
	g++ -c Book.cpp

clean:
	del *.o output
