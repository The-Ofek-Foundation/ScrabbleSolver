SOURCE_CPP = src/BoggleBoard.cpp

all:
	mkdir -p bin/
	g++-11 --std=c++17 -o bin/main src/main.cpp ${SOURCE_CPP} -O3 -Wall -Werror

make run: all
	cd bin/ && ./main

clean:
	rm -rvf bin/