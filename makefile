build:
	g++ main.cc -o prime-test.exe
build-debug:
	g++ -g main.cc -o prime-test.exe
clean:
	rm -f prime-test.exe
test:
	./prime-test
debug:
	gdb ./prime-test