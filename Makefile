bane:bane.c
	gcc -o bane bane.c

install:bane
	install -c bane /usr/local/bin/bane

clean:bane
	rm -f bane

