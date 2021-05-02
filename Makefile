test: test.o
	gcc -o test test.o

%.o:%.c:
	gcc -c $^

clean:
	$(RM) test 