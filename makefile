CC=gcc
OBJECTS_MAIN_TRIE=main.o trie.o
FLAGS= -Wall -g

all: frequency 	
frequency: $(OBJECTS_MAIN_TRIE) 
	$(CC) $(FLAGS) -o  frequency $(OBJECTS_MAIN_TRIE) 	
trie.o: trie.c trie.h 
	$(CC) $(FLAGS) -fPIC -c trie.c
main.o: main.c trie.h   
	$(CC) $(FLAGS) -fPIC -c main.c 


.PHONY: clean all

clean:
	rm -f *.o  *.out frequency