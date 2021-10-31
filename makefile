SOURCE_CPP = src/BoggleBoard.cpp

all:
	mkdir -p bin/
	g++-11 --std=c++20 -o bin/main src/main.cpp ${SOURCE_CPP}

make run: all
	./bin/main

clean:
	rm -rvf bin/