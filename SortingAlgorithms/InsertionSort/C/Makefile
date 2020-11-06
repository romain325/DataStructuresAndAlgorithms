CC=gcc

CFLAGS= -Wall -g -I include/

SRC=./

OBJ=$(SRC)InsertionSort.o

Out : $(OBJ)
	$(CC) $^ -o $@

$(SRC)%.o: $(SRC)%.c $(SRC)%.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(SRC)*.o Out
	clear
