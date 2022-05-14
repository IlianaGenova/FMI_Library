all: output

output: Library.o Author.o Book.o
	g++ -std=c++0x -Wall Library.o Author.o Book.o -o output

Library.o: Library.cpp
	g++ -c Library.cpp

Author.o: Author.cpp Author.hpp
	g++ -c Author.cpp

Book.o: Book.cpp Book.hpp
	g++ -c Book.cpp

clean:
	del *.o output
