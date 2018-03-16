OBJS=main.o ./tree/tree.o

main:$(OBJS)
	g++ -g $(OBJS) -o main
	rm $(OBJS)

main.o:./tree/tree.h main.cpp
	g++ -g -c main.cpp

tree.o:./tree/tree.h ./tree/tree.cpp
	g++ -g -c ./tree./tree.cpp