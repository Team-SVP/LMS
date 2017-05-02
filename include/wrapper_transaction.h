#ifndef __WRAPPER_TRANSACTION_H
#define  __WRAPPER_TRANSACTION_H

#include "transaction.h"
#include "books.h"
#include "member.h"
int wrapper_issue_book(TRANSACTION, BOOKS, MEMBERS);
void wrapper_return_book();
void wrapper_search_book();
void wrapper_search_member();

#endif
