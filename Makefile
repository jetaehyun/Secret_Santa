all:
	gcc -o santa src/main.c

clean:
	rm -f santa main.o
