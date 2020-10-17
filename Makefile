TARGET:TestApp
TestApp:main.o libds.a
	gcc ./bin/main.o -o ./bin/TestApp -L . ./bin/libds.a -lm
main.o:main.c
	gcc -c main.c -o ./bin/main.o
libds.a:libds.o
	ar rs ./bin/libds.a ./bin/libds.o
libds.o:./lib/array.c
	gcc -c ./lib/array.c -o ./bin/libds.o
clean:
	rm ./bin/libds.o
	rm ./bin/main.o
	rm ./bin/TestApp
