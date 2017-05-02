#include<stdio.h>
#include<fstream>
#include<iostream>
#include<string>
#include<ctype.h>
#include<cstring>
#include<stdlib.h>
using namespace std;

// Book module for LMS system. Which will store all books record.

class BOOKS
{
	private:
		int book_code = 0, copies, avail;
		float price;
		char  book_name[100], author_name[100], publication[100];
	
	protected:
		
		
	public:
		
		void delete_book(int);
		void update_book(int, int, int);
		void update_book_name(int , char *, char *, char *);
		void add_book(char *, char *, char *, int, float, int);
		void list();
		int update_avail(int);
		

};


void BOOKS::add_book( char *book_name1, char *author_name1, char *publication1, int copies1, float price1, int avail1)
{
	fstream file;
	
	file.open("BOOK.dat", fstream::in);
	file.seekg(-sizeof(BOOKS),std::ios_base::end);
	file.read((char *) this, sizeof(BOOKS));
	file.close();
	book_code = book_code + 1;
	strcpy(book_name, book_name1);
	strcpy(author_name, author_name1);
	strcpy(publication, publication1);
	copies = copies1;
	price = price1;
	avail = avail1;
	file.open("BOOK.dat",ios::out|ios::binary | ios::app);
	
	file.write((char *) this, sizeof(BOOKS));
	file.close();	

}

void BOOKS:: delete_book(int b_id)
{
	int flag_d = 0;
        fstream file, file1;

        file.open("BOOK.dat", fstream::in);
        file1.open("tmp.dat",ios::out|ios::binary);

        while(file.read((char *) this, sizeof(BOOKS))){
		if (book_code == b_id)
			flag_d = 1;
		else  
		{
        		file1.write((char *) this, sizeof(BOOKS));
		}
	}
        file.close();
        file1.close();

	if (flag_d == 0)
		cout << " ****** Record Not Found ******\n";
	else
		flag_d = 0;
	remove("BOOK.dat");
	rename("tmp.dat", "BOOK.dat");

}


int BOOKS:: update_avail(int b_id)
{
        int flag_u1 = 0;
        fstream file, file1;

        file.open("BOOK.dat", fstream::in);
        file1.open("tmp.dat",ios::out|ios::binary);


        while(file.read((char *) this, sizeof(BOOKS))){
                if (book_code == b_id)
                {
                        flag_u1 = 1;
			if (avail != 0) 
                        	avail = avail - 1;
			else{
				remove("tmp.data");
				return -1;
			}
                        file1.write((char *) this, sizeof(BOOKS));
                }
                else
                {
                        file1.write((char *) this, sizeof(BOOKS));
                }
        }
        file.close();
        file1.close();

        if (flag_u1 == 0)
                cout << " ****** Record Not Found ******\n";
        else
                flag_u1 = 0;

        remove("BOOK.dat");
        rename("tmp.dat", "BOOK.dat");
	return 0;

}


void BOOKS:: update_book(int b_id, int avail1, int copies1)
{
        int flag_u1 = 0;
        fstream file, file1;

        file.open("BOOK.dat", fstream::in);
        file1.open("tmp.dat",ios::out|ios::binary);
        		

        while(file.read((char *) this, sizeof(BOOKS))){
                if (book_code == b_id)
		{
                        flag_u1 = 1;

			copies = copies1;
			avail = avail1;
                        file1.write((char *) this, sizeof(BOOKS));
		}
                else
                {
                        file1.write((char *) this, sizeof(BOOKS));
                }
        }
        file.close();
        file1.close();

	if (flag_u1 == 0)
		cout << " ****** Record Not Found ******\n";
	else
		flag_u1 = 0;
        
	remove("BOOK.dat");
        rename("tmp.dat", "BOOK.dat");

}

void BOOKS:: update_book_name(int b_id, char *b_name, char *a_name, char *pub)
{
        int flag_u2 =0;
        fstream file, file1;

        file.open("BOOK.dat", fstream::in);
        file1.open("tmp.dat",ios::out|ios::binary);
	

        while(file.read((char *) this, sizeof(BOOKS))){
                if (book_code == b_id)
                {
                        flag_u2 = 1;
			strcpy(book_name, b_name);
                        strcpy(author_name, a_name);
                        strcpy(publication, pub);
                        file1.write((char *) this, sizeof(BOOKS));
                }
                else
                {
                        file1.write((char *) this, sizeof(BOOKS));
                }
        }
        file.close();
        file1.close();

        if (flag_u2 == 0)
                cout << " ****** Record Not Found ******\n";
	else
		flag_u2 = 0;
        remove("BOOK.dat");
        rename("tmp.dat", "BOOK.dat");

}


void BOOKS:: list() {

	/* Show the book details*/

	fstream file;
        file.open("BOOK.dat",ios::in|ios::binary);
        file.seekg(0,ios::beg);
	cout << "Book ID \t" << "Book Name\t" << "Author Name\t" << "Publication\t" << "Price\t" << "Total Copies\t" << "Available Copies" << endl;
        while(file.read((char *) this, sizeof(BOOKS))) {
		cout << book_code << "\t\t" << book_name  << "\t\t" << author_name << "\t\t"  << publication << "\t\t" << price << "\t\t" << copies << "\t\t" << avail  <<endl;
	}
        file.close();
	

}

/*
int main() {

	BOOKS bookObj;

	bookObj.add_book( "Unix", "Steve", "PBS", 10, 100.24, 10);
	bookObj.add_book( "Unix", "Steve", "PBS", 10, 100.24, 10);
	bookObj.add_book( "Unix", "Steve", "PBS", 10, 100.24, 10);
	bookObj.list();
	bookObj.delete_book(2);
	bookObj.list();
	bookObj.update_book(3, 20, 5);
	bookObj.list();
	bookObj.update_book_name(1, "Win", "John", "VPS");
	bookObj.list();

	bookObj.add_book( "Unix", "Steve", "PBS", 10, 100.24, 10);
	bookObj.list();
	return 0;
}


*/
