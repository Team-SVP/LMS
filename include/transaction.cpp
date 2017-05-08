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
		int t_id=100, fine=0, b_id, m_id, days=0, h_id=0;
	public:
		void issue_book(int , int , ptime, ptime);
		void return_book(int);
		void search_book();
		void search_member();
		void list_transaction();
		void list_history();


};


void TRANSACTION::issue_book(int b_id1, int m_id1, ptime issue_date1, ptime due_date1) {
	fstream file;
	issue_date = issue_date1;
	due_date = due_date1;
	
	cout << issue_date <<"\t" << due_date << endl;
	cout << "Issue date and \t due date";	
        file.open("TRANSACTION.dat", fstream::in);
        file.seekg(-sizeof(TRANSACTION),std::ios_base::end);
        file.read((char *) this, sizeof(TRANSACTION));
        file.close();
        t_id = t_id + 1;
	b_id = b_id1;
	m_id = m_id1;
        file.open("TRANSACTION.dat",ios::out|ios::binary | ios::app);
	BOOKS bObj;
	
	
	bObj.update_avail(b_id, -1);
	
        file.write((char *) this, sizeof(TRANSACTION));
        file.close();


}

void TRANSACTION::return_book(int tr_id1) {
	fstream file, file1, file_d, file_d1;
	int flag_r = 0, fine1 = 0;
        file.open("TRANSACTION.dat", fstream::in);
        //file.seekg(-sizeof(TRANSACTION),std::ios_base::end);
        while(file.read((char *) this, sizeof(TRANSACTION))) {
		if (t_id == tr_id1){
			flag_r = 1;
			ptime current_date;
			time_facet *facet = new time_facet("%d/%b/%Y");
        		cout.imbue(locale(cout.getloc(), facet));
        		current_date  = second_clock::local_time();

			time_duration d = current_date - due_date;
			days = d.total_seconds();
			days = days/86400;
			if (days >= 1) {
				fine1 = days * 2;
			}
			return_date = current_date;
			fine = fine1;
			
		} 
		
	}
	
	
        file.close();
	if (flag_r == 0)
		cout << "Book was not issued to this member" << endl;
	else {

		BOOKS bObj;
		cout << b_id;

        	bObj.update_avail(b_id, 1);
		
		file1.open("HISTORY.dat", fstream::in);
        	file1.seekg(-sizeof(TRANSACTION),std::ios_base::end);
        	file1.read((char *) this, sizeof(TRANSACTION));
        	file1.close();
		h_id = h_id + 1;
		file1.open("HISTORY.dat",ios::out|ios::binary | ios::app);
        	file1.write((char *) this, sizeof(TRANSACTION));
        	file1.close();


			
			


        	file_d.open("TRANSACTION.dat", fstream::in);
        	file_d1.open("trtmp.dat",ios::out|ios::binary);

        	while(file_d.read((char *) this, sizeof(TRANSACTION))){
                	if (t_id != tr_id1)
                        	file_d1.write((char *) this, sizeof(TRANSACTION));
        	}
        	file_d.close();
        	file_d1.close();

        	remove("TRANSACTION.dat");
        	rename("trtmp.dat", "TRANSACTION.dat");

	}


}

void TRANSACTION::search_book() {

}

void TRANSACTION :: search_member() {

}

void TRANSACTION :: list_transaction() {
	fstream file;
        file.open("TRANSACTION.dat",ios::in|ios::binary);
        file.seekg(0,ios::beg);
        cout << "Transaction ID \t" << "Book Id\t" << "Member ID\t" << "Issue Date\t" << "Due Date\t"  << endl;
        while(file.read((char *) this, sizeof(TRANSACTION))) {
                cout << t_id << "\t\t" << b_id  << "\t\t" << m_id << "\t\t"  << issue_date << "\t\t" << due_date <<endl;
        }
        file.close();


}

void TRANSACTION :: list_history() {
        fstream file;
        file.open("HISTORY.dat",ios::in|ios::binary);
        file.seekg(0,ios::beg);
        cout << "Transaction ID \t" << "Book Id\t" << "Member ID\t" << "Issue Date\t" << "Due Date\t" << "Return Date\t" <<"Fine \t" << endl;
        while(file.read((char *) this, sizeof(TRANSACTION))) {
                cout << t_id << "\t\t" << b_id  << "\t\t" << m_id << "\t\t"  << issue_date << "\t\t" << due_date << "\t\t" << return_date << "\t\t" << fine <<endl;
        }
        file.close();


}
