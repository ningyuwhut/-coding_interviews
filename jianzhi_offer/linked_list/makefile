main: main.o linked_list.o
	g++ -o main -g main.o linked_list.o
main.o: main.cpp linked_list.h
	g++ -c main.cpp 
linked_list.o : linked_list.cpp linked_list.h
	g++ -c linked_list.cpp

