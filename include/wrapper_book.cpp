#include "books.h"
#include<stdio.h>
#include<iostream>
using namespace std;

void wrapper_add_book(BOOKS bObj) {
	int total_copies, b_price, copies_avail;
	char b_name[100], b_author[100], b_pub[100];
	
	cout << "Enter Details for Adding Book";
	cout << "Enter Book Name: \n";
	cin >> b_name;
	cout << "Enter Author Name: \n";
	cin >> b_author;
	cout << "Enter Publication: \n";
	cin >> b_pub;
	cout << "Enter Total No of Copies: \n";
	cin >> total_copies;
	cout << "Book Price: \n";
	cin >> b_price;
	cout << "Available Copies: \n";
	cin >> copies_avail;
	
	bObj.add_book( b_name, b_author, b_pub, total_copies, b_price, copies_avail);
}

void wrapper_delete_book(BOOKS bObj) {
	int b_id;
	bObj.list();
	cout << "Enter Book Id";
	cin >> b_id;
	bObj.delete_book(b_id);
}

void wrapper_update_book(BOOKS bObj) {
	int b_id, total_copies, b_price, copies_avail;
	
	bObj.list();
	cout << "Enter Details to update book";
	cout << "Enter Book Id for update";
        cin >> b_id;

	cout << "Enter Total No of Copies: \n";
        cin >> total_copies;
        cout << "Book Price: \n";
        cin >> b_price;
        cout << "Available Copies: \n";
        cin >> copies_avail;


}

void wrapper_book_name(BOOKS bObj) {
	int b_id;
	char b_name[100], b_author[100], b_pub[100];
	
	
	bObj.list();
        cout << "Enter Details for updating Book name";
	cout << "Enter Book Id for update";
	cin >> b_id;
        cout << "Enter Book Name: \n";
        cin >> b_name;
        cout << "Enter Author Name: \n";
        cin >> b_author;
        cout << "Enter Publication: \n";
        cin >> b_pub;
        cout << "Enter Total No of Copies: \n";

}


void wrapper_list_book(BOOKS bObj) {
	bObj.list();

}


/*
int main() {

        BOOKS bookObj;
	wrapper_add_book(bookObj);

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
	
        //bookObj.list();
        return 0;
}
*/
