SHELL := bash
CXX = g++
CXXFlAGS = -g

run : main
	./main.out

main : clean Book.o main.o
	$(CXX) $(CXXFlAGS) Book.o main.o -o main.out

main.o :
	$(CXX) $(CXXFlAGS) -c main.cpp
Book.o:
	$(CXX) $(CXXFlAGS) -c Book.cpp

clean :
	rm -f *.o *.out
