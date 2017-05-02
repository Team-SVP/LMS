#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include "books.h"
#include "member.h"
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

using namespace std;

class TRANSACTION {
	private:
		ptime issue_date, due_date, return_date;
		int t_id=100, fine, b_id, m_id;
	public:
		void issue_book(int , int , ptime, ptime);
		void return_book();
		void search_book();
		void search_member();


};


void TRANSACTION::issue_book(int b_id1, int m_id1, ptime issue_date1, ptime due_date1) {
	fstream file;
	issue_date = issue_date1;
	due_date = due_date1;
	
        file.open("TRANSACTION.dat", fstream::in);
        file.seekg(-sizeof(TRANSACTION),std::ios_base::end);
        file.read((char *) this, sizeof(TRANSACTION));
        file.close();
        t_id = t_id + 1;
	b_id = b_id1;
	m_id = m_id1;
        file.open("TRANSACTION.dat",ios::out|ios::binary | ios::app);
	BOOKS bObj;
	
	
	bObj.update_avail(b_id);
	
        file.write((char *) this, sizeof(TRANSACTION));
        file.close();


}

void TRANSACTION::return_book() {

}

void TRANSACTION::search_book() {

}

void TRANSACTION :: search_member() {

}

