calc: calculator.o eval.o stack.o token.o
	gcc -o calc calculator.o eval.o stack.o token.o -lm
calculator.o: calculator.c eval.h
	gcc -c calculator.c
eval.o: eval.c token.h stack.h eval.h 
	gcc -c eval.c
stack.o: stack.c stack.h	
	gcc -c stack.c
token.o: token.c token.h
	gcc -c token.c
clean:
	rm -rf *.o calc
