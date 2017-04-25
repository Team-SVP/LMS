CC=g++
 # Hey!, I am comment number 2. I want to say that CFLAGS will be the
 #  # options I'll pass to the compiler.
CFLAGS=-c -Wall

all: hello

hello: member.o books.o test_member.o 
	$(CC) bin/member.o ./bin/books.o ./bin/test_member.o -o ./bin/hello
	
member.o: ./include/member.cpp
	$(CC) -I./include $(CFLAGS) ./include/member.cpp -o ./bin/member.o
	
books.o: ./include/books.cpp
	$(CC) -I./include $(CFLAGS) ./include/books.cpp -o ./bin/books.o

test_member.o: test_member.cpp
	$(CC) -I./include $(CFLAGS) test_member.cpp -o ./bin/test_member.o

lms.o: wrapper_member.cpp mgt.cpp
	g++ -I./include -L/root/projects/LMS/lib -lmember mgt.cpp wrapper_member.cpp 

clean:
	rm *.o hello
