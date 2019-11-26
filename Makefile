stack : ADT_Stack.c
	gcc -c ADT_Stack.c

main : main.c
	gcc -c main.c

main2 : main2.c
	gcc -c main2.c

merge1 : ADT_Stack.o main.o
	gcc -o merge1 ADT_Stack.o main.o

merge2 : ADT_Stack.o main2.o
	gcc -o merge2 ADT_Stack.o main2.o

clean : 
	rm -rf *.o merge1 merge2

