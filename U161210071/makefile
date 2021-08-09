all: compile run

compile: AVLTree test
	g++ ./lib/AVLTree.o ./lib/test.o -o ./bin/test

AVLTree:
	g++ -I "./include" -c ./src/AVLTree.cpp -o ./lib/AVLTree.o

test:
	g++ -I "./include" -c ./src/test.cpp -o ./lib/test.o

clean:
	rm -rf edit ./lib/AVLTree.o ./lib/test.o ./bin/test

run:
	./bin/test
