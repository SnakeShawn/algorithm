test: test.o sorting.o
	gcc -o test test.o sorting.o
test.o: test.cpp sorting.h
	gcc -c test.cpp
sorting.o: sorting.cpp sorting.h
	gcc -c sorting.cpp
clean:
	rm test test.o sorting.o
