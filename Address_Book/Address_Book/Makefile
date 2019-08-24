SRC:= $(wildcard *.c)
OBJ:= $(patsubst %.c, %.o, $(SRC))

Address_book: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.o 

run:
	make && ./Address_book
