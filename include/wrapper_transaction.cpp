#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include "transaction.h"
#include "books.h"
#include "member.h"
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::posix_time;
	

int wrapper_issue_book(TRANSACTION obj_tr, BOOKS obj_b, MEMBERS obj_mem) {
	int b_id1, m_id1;	
        ptime issue_date, due_date;
	time_facet *facet = new time_facet("%d/%b/%Y");
        cout.imbue(locale(cout.getloc(), facet));
        issue_date  = second_clock::local_time();

	obj_b.list();
	cout << "Enter Book Id: ";
	cin >> b_id1;
	
	obj_mem.list_members();
	cout << "Enter Member Id: ";
	cin >> m_id1;

	due_date = issue_date + boost::gregorian::days(10);

	obj_tr.issue_book(b_id1, m_id1, issue_date, due_date);

	return 0;
}

void wrapper_return_book() {

}

void wrapper_search_book() {

}

void wrapper_search_member() {

}

