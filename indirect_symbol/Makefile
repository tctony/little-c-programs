pwd:=$(shell echo `pwd`)

all: main.c indirect_symbol.c foo
	gcc -L$(pwd) -Wl,-rpath $(pwd) -Wall -Werror main.c indirect_symbol.c -lfoo

foo: foo.o
	gcc -shared -o libfoo.so foo.o

foo.o: foo.c
	gcc -c -Wall -Werror -fpic foo.c

clean:
	rm -rf a.out libfoo.so foo.o
