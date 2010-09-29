

default:build

build: lib
	g++ main.cpp static.a -o GO5 -g

lib:
	g++ -c board.cpp captureother.cpp functorlist.cpp ko.cpp  putstone.cpp stone.cpp verifyboard.cpp action.cpp lowlevelboard.cpp history.cpp -g
	ar rcs static.a *.o
clean:
	rm -f *.o *~ *.a