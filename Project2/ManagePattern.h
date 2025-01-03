#pragma once
#include "BookManager.h"
#include "BorrowManager.h"

class ManagePattern : public BookManager, public BorrowManager
{
public:
	void patternAddBook(string, string);
	void patternBorrow(string, int);
	void patternReturnBook(string);
};

