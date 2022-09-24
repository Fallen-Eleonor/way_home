all: way_home

way_home:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -o way_home src/*.c

clean:
	rm -f $(name)

uninstall:
	rm -f $(name)

reinstall:
	make uninstall
	make