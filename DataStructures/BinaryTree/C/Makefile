#CC : le compilateur à utiliser
CC=gcc

#CFLAGS : les options de compilation  
CFLAGS= -Wall -I include/

#lieu où se trouve les sources :
SRC=./

#les fichiers objets
OBJ=$(SRC)BinaryTree.o \
	$(SRC)Test.c

Out : $(OBJ)
	$(CC) $^ -o $@ 

$(SRC)%.o: $(SRC)%.c $(SRC)%.h
	$(CC) $(CFLAGS)  $(LDFLAGS) -c $< -o $@


clean:
	rm -rf $(SRC)*.o Out

