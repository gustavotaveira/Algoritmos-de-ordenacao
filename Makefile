OBJS = principal.o algoritmos.o utils.o

app : $(OBJS)
	gcc -o programa $(OBJS)

principal.o : principal.c utils.h algoritmos.h
	gcc -c -o principal.o principal.c
algoritmos.o : algoritmos.c algoritmos.h
	gcc -c -o algoritmos.o algoritmos.c
utils.o : utils.c utils.h
	gcc -c -o utils.o utils.c
.PHONY : clean
clean :
	-rm $(OBJS) programa
