#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "books.h"
using namespace std;

int main() {

	/*

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
        bookObj.list(); */
	int choice;
	cout << "1: Add Member \n";
	cout << "2: Update Member \n";
	cout << "3: Delete Member \n";
	cout << "4: Display Member \n";
	
	cout << "5: Add Book\n";
	cout << "6: Update Book\n";
	cout << "7: Update Book Name\n";
	cout << "8: Delete Book\n";
	cout << "9: Display Book\n";
	cout << "10: Issue Book\n";
	cout << "11: Return Book\n";
	cout << "12: Search Book\n";
	cout << "13: Search Member\n";
	cout << "14: Exit\n";
	
	cout << "Enter Your Choice : ";
	cin >> choice; 
	
	switch(choice) {
		case 1:
			cout << "Your in switch 1";
			break;
		case 2: cout << "Your in switch 2";
			break;

		case 14:
			exit(0);
		default:
			cout << "in default case";
	
	}	

        return 0;
}


	
