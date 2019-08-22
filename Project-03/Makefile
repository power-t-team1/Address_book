SRC:= $(wildcard *.c)
OBJ:= $(patsubst %.c, %.o, $(SRC))

book.exe: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.o *.exe

run:
	make && ./book.exe

