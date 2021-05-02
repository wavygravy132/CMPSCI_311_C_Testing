%.o:%.c
	gcc -c $^

all: test-thread test

test-thread: test-thread.o
	gcc -o test-thread test-thread.o -lpthread
test: test.o
	gcc -o test test.o

clean:
	$(RM) test 