all: 
	clear
	gcc   ./Include/funcao.h   	 ./ArquivosC/funcao.c	 	  main.c	    -o	   exec
	./exec

clean:
	rm -rf *.o ./exec
	clear