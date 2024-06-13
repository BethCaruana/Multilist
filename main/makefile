all:		Node.o main.o
		g++ -g Node.o main.o -o all

Node.o:		Node.h
		g++ -c -g Node.cpp

main.o:		main.cpp Node.h
		g++ -c -g main.cpp

clean:
	rm *.o
	rm all

run: all
	./all

debug: all
	gdb all

valgrind: all
	valgrind --leak-check=full ./all
