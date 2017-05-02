CC=g++
 # Hey!, I am comment number 2. I want to say that CFLAGS will be the
 #  # options I'll pass to the compiler.
CFLAGS=-c -Wall

all: clean shared lms

#lms: member.o books.o test_member.o 
#	$(CC) bin/member.o ./bin/books.o ./bin/test_member.o -o ./bin/hello
	
#member.o: ./include/member.cpp
#	$(CC) -I./include $(CFLAGS) ./include/member.cpp -o ./bin/member.o
	
#books.o: ./include/books.cpp
#	$(CC) -I./include $(CFLAGS) ./include/books.cpp -o ./bin/books.o

#test_member.o: test_member.cpp
#	$(CC) -I./include $(CFLAGS) test_member.cpp -o ./bin/test_member.o

shared : ./include/books.cpp ./include/member.cpp ./include/transaction.cpp
	g++ -shared -fPIC -I./include ./include/books.cpp ./include/member.cpp ./include/transaction.cpp -o ./lib/liblms.so

lms: ./include/wrapper_member.cpp mgt.cpp ./include/wrapper_book.cpp ./include/wrapper_transaction.cpp
	g++ -I./include -L./lib -llms mgt.cpp ./include/wrapper_member.cpp ./include/wrapper_book.cpp ./include/wrapper_transaction.cpp -o ./bin/lms

clean:
	rm -rf ./bin/lms ./lib/liblms.so
