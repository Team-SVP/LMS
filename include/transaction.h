#ifndef __TRANSACTION_H
#define  __TRANSACTION_H

#include <stdio.h>
#include <iostream>
#include "wrapper_book.h"
#include "wrapper_member.h"

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

#endif
