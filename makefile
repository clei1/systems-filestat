all: filestat.c
	gcc filestat.c
run: all
	./a.out
clean: 
	rm *.out
	rm *~
