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
		int book_code = 0, copies, avail, flag = 1;
		float price;
		char  book_name[100], author_name[100], publication[100];
	
	protected:
		
		//void add_book(int, string, string, string, int, float, int);
		//void delete_book(void);
		//void update_book(int, int, int);
		//void update_book(int, char[], char[], char[]);
		
	public:
		
		void delete_book(void);
		void update_book(void);
		void update_book_name(void);
		void add_book(char[], char[], char[], int, float, int);
		void list();
		

};


void BOOKS::add_book( char *book_name1, char *author_name1, char *publication1, int copies1, float price1, int avail1)
{
	fstream file;
	/*
	ofstream outfile;
   outfile.open("afile.dat");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 

   // write inputted data into the file.
      outfile << "data" << endl;
   //
	*/
	//file.open("BOOK.txt", std::fstream::in | std::fstream::out | std::fstream::app | ios::binary);
	
	file.open("BOOK.dat", fstream::in);
	//if (file.fail())
	//file.read((char *) this, sizeof(BOOKS));
	//if (book_code == -1)
	//	book_code = 0;
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
	
	book_code = book_code;
	copies = copies;
	file.write((char *) this, sizeof(BOOKS));
	file.close();	

}

void BOOKS:: delete_book(void)
{
	int b_id;
        fstream file, file1;

        file.open("BOOK.dat", fstream::in);
        file1.open("tmp.dat",ios::out|ios::binary);
	cout << "Enter ID of Book to be Deleted : ";
	cin >> b_id;

        while(file.read((char *) this, sizeof(BOOKS))){
		if (book_code == b_id)
			flag = 0;
		else  
		{
        		file1.write((char *) this, sizeof(BOOKS));
			flag = 1;
		}
	}
        file.close();
        file1.close();

	if (flag != 0)
		cout << " ****** Record Not Found ******\n";
	remove("BOOK.dat");
	rename("tmp.dat", "BOOK.dat");

}

void BOOKS:: update_book(void)
{
        int b_id, avail1, copies1;
        fstream file, file1;

        file.open("BOOK.dat", fstream::in);
        file1.open("tmp.dat",ios::out|ios::binary);
        		
	cout << "Enter ID of Book to be Updated : ";
        cin >> b_id;

        while(file.read((char *) this, sizeof(BOOKS))){
                if (book_code == b_id)
		{
                        flag = 0;
       			cout << "Enter available books count : ";
        		cin >> avail1;
        		cout << "Enter no of copies : ";
        		cin >> copies1;

			copies = copies1;
			avail = avail1;
                        file1.write((char *) this, sizeof(BOOKS));
		}
                else
                {
                        file1.write((char *) this, sizeof(BOOKS));
                        flag = 1;
                }
        }
        file.close();
        file1.close();

        if (flag != 0)
                cout << " ****** Record Not Found ******\n";
        remove("BOOK.dat");
        rename("tmp.dat", "BOOK.dat");

}

void BOOKS:: update_book_name(void)
{
        int b_id;
	char b_name[32], a_name[32], pub[32];
        fstream file, file1;

        file.open("BOOK.dat", fstream::in);
        file1.open("tmp.dat",ios::out|ios::binary);
	
	cout << "Enter ID of Book to be Updated : ";
       	cin >> b_id;

        while(file.read((char *) this, sizeof(BOOKS))){
                if (book_code == b_id)
                {
                        flag = 0;
        		cout << "Enter name of the book : ";
        		cin >> b_name;
        		cout << "Enter name of the author : ";
        		cin >> a_name;
        		cout << "Enter name of the publication : ";
        		cin >> pub;
                        
			strcpy(book_name, b_name);
                        strcpy(author_name, a_name);
                        strcpy(publication, pub);
                        file1.write((char *) this, sizeof(BOOKS));
                }
                else
                {
                        file1.write((char *) this, sizeof(BOOKS));
                        flag = 1;
                }
        }
        file.close();
        file1.close();

        if (flag != 0)
                cout << " ****** Record Not Found ******\n";
        remove("BOOK.dat");
        rename("tmp.dat", "BOOK.dat");

}


void BOOKS:: list() {
	fstream file;
        file.open("BOOK.dat",ios::in|ios::binary);
        file.seekg(0,ios::beg);
	cout << "Book ID \t" << "Book Name\t" << "Author Name\t" << "Publication\t" << "Price\t" << "Total Copies\t" << "Available Copies" << endl;
        while(file.read((char *) this, sizeof(BOOKS))) {
		cout << book_code << "\t\t" << book_name  << "\t\t" << author_name << "\t\t"  << publication << "\t\t" << price << "\t\t" << copies << "\t\t" << avail  <<endl;
	}
        file.close();
	

}

int main() {

	BOOKS bookObj;

	bookObj.add_book( "Unix", "Steve", "PBS", 10, 100.24, 10);
	bookObj.add_book( "Unix", "Steve", "PBS", 10, 100.24, 10);
	bookObj.add_book( "Unix", "Steve", "PBS", 10, 100.24, 10);
	bookObj.list();
	//bookObj.delete_book();
	//bookObj.update_book();
	bookObj.update_book_name();
	bookObj.list();

	bookObj.add_book( "Unix", "Steve", "PBS", 10, 100.24, 10);
	bookObj.list();
	return 0;
}



