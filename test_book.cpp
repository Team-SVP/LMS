#include "books.h"
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

