compile: dev_rand.c test.txt
	chmod 777 test.txt
	gcc dev_rand.c

run:
	./a.out

clean:
	-rm -rf *.o a.out
