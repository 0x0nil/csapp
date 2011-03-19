# makefile

object=p foo3 foo4 foo4 p2

all: $(object)

p: main.o swap.o
	$(CC) -o p main.o swap.o

p2:main2.o libvector.a
	$(CC) -static -o p2 main2.o ./libvector.a

libvector.a:addvec.o multvec.o
	ar rcs libvector.a addvec.o multvec.o

foo1:foo1.o bar1.o
	$(CC) -o foo1 foo1.o bar1.o
foo2:foo2.o bar2.o
	$(CC) -o foo2 foo2.o bar2.o
foo3:foo3.o bar3.o
	$(CC) -o foo3 foo3.o bar3.o
foo4:foo4.o bar4.o
	$(CC) -o foo4 foo4.o bar4.o
foo5:foo5.o bar5.o
	$(CC) -o foo5 foo5.o bar5.o

clean:
	rm -rf *.o *.a
	rm -rf $(object)
