bane:src/bane.c
	gcc -o build/bane src/bane.c

install:build/bane
	install -c build/bane /usr/local/bin/bane

clean:build/bane
	rm -f build/bane
