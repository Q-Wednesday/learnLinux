hello: hello.o
	g++ hello.o -o hello
hello.o: hello.s
	g++ -c hello.s -o hello.o
hello.s: 
	g++ -S hello.cpp -o hello.s
clean:
	rm hello.o hello.s hello
	