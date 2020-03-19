all: main.bin
	@echo "---------------------------"
	@echo "succeed"

main.bin:day03.c libtest.so 
	gcc day03.c -I./ -ltest -L./ -o $@

libtest.so:day03.o
	gcc -shared day03.o -o libtest.so

day03.o:day03.c
	gcc -c day03.c -fpic -o day03.o

clean:
	$(RM) main.bin *.o *.so
