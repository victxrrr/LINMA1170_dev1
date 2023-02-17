CC=gcc
CFLAGS=-g3 -Wall

test_mat: matrix.c test_matrix.c
	$(CC) $(CFLAGS) -o $@ $^
	./test_mat

test_lu: matrix.c lu.c test_lu.c
	$(CC) $(CFLAGS) -o $@ $^
	./test_lu

complex: matrix.c lu.c complexity.c
	$(CC) $(CFLAGS) -o $@ $^
	./complex

clean:
	rm -f test_mat
	rm -f test_lu
	rm -f complex
	rm -f *.o