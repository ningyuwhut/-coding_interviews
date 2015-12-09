assignment_operator_main : assignment_operator_main.o assignment_operator.o
	g++  -o assignment_operator_main assignment_operator_main.o assignment_operator.o
assignment_operator_main.o : assignment_operator_main.cpp assignment_operator.h
	g++   -c assignment_operator_main.cpp
assignment_operator.o : assignment_operator.cpp assignment_operator.h
	g++   -c assignment_operator.cpp
clean:
	rm assignment_operator_main.o assignment_operator.o 
