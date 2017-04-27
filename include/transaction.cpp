#include <stdio.h>
#include <iostream>
#include "wrapper_book.h"
#include "wrapper_member.h"

class Transaction {
	private:
		char issue_date[12], due_date[12], return_date[12];
		int fine;
	public:
		void issue_book();
		void return_book();
		void search_book();
		void search_member();


};


void Transaction::issue_book() {


}

void Transaction::return_book() {

}

void Transaction::search_book() {

}

void Transaction :: search_member() {

}
