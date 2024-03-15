CXX = g++
CXXFlAGS = -g

run : main
	./main.out

main : clean Media.o main.o
	$(CXX) $(CXXFlAGS) Media.o main.o -o main.out

main.o :
	$(CXX) $(CXXFlAGS) -c main.cpp
Media.o:
	$(CXX) $(CXXFlAGS) -c Media.cpp

clean :
	rm -f *.o *.out
