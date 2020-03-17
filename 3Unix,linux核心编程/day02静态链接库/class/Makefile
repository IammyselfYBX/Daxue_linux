#静态链接库
all:main.bin
	@echo "-----------------------"
	@echo "succeed!"

main.bin:libtest.a
	gcc day02.c -ltest -L ./ -o $@

libtest.a:day02.o
	$(AR) -r libtest.a day02.o

day02.o:day02.c
	gcc -c day02.c

AR:day02.o
	$(AR) -r libtest.a day02.o

clean:
	$(RM) *.o *.a main.bin