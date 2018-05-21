#Created by Eliaquim dos Santos and David Franklin
PROG = executavel
CC = g++
CPPFLAGS = -Wall -std=c++11 -pedantic -lm -I./includes
OBJS = main.o  
SRC = ./src/

$(PROG):$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(PROG) 
	mkdir build
	mv *.o ./build
	mv executavel ./bin		
main.o: 
	$(CC) $(CPPFLAGS) -c $(SRC)main.cpp
clean:
	`rm -f core ./build/*.o` 
	rmdir build