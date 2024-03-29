CXX = g++
CXXFlAGS = -g 

run : main
	./main.out

main : clean Job.o Player.o main.o
	$(CXX) $(CXXFlAGS) Character.o Player.o Job.o main.o -o main.out

main.o :
	$(CXX) $(CXXFlAGS) -c main.cpp -I./header

Player.o : Character.o
	$(CXX) $(CXXFlAGS) -c Player.cpp -I./header 

Character.o:
	$(CXX) $(CXXFlAGS) -c Character.cpp -I./header 

Job.o:
	$(CXX) $(CXXFlAGS) -c Job.cpp -I./header

clean :
	rm -f *.o *.out
