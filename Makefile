OBJS=main.o ./tree/tree.o

main:$(OBJS)
	g++ $(OBJS) -o main
	rm main.o

main.o:./tree/tree.h main.cpp
	g++ -c main.cpp

tree.o:./tree/tree.h ./tree/tree.cpp
	g++ -c ./tree./tree.cpp