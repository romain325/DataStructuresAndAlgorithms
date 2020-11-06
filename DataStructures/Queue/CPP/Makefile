CC=g++

CFLAGS= -Wall -g -I include/

SRC=./

OBJ=$(SRC)Queue.o \
	$(SRC)test.o

Out : $(OBJ)
	$(CC) $^ -o $@

$(SRC)%.o: $(SRC)%.c $(SRC)%.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(SRC)*.o Out
	clear
