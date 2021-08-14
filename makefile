all:compile executable execute

compile:
	g++ -I./include -c ./src/Dugum.cpp -o ./lib/dugum.o
	g++ -I./include -c ./src/Test.cpp -o ./lib/test.o
	g++ -I./include -c ./src/DoublyLinkedList.cpp -o ./lib/list.o
	
executable:
	g++      ./lib/dugum.o  ./lib/list.o  ./lib/test.o -o ./bin/test.exe
execute:
	./bin/test
