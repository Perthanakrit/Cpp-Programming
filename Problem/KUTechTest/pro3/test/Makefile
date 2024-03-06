SHELL := bash
CXX = g++
CXXFlAGS = -g

run : main
	./main.out

main : clean Node.o main.o
	$(CXX) $(CXXFlAGS) Node.o main.o -o main.out

main.o :
	$(CXX) $(CXXFlAGS) -c main.cpp
Node.o:
	$(CXX) $(CXXFlAGS) -c Node.cpp

clean :
	rm -f *.o *.out
