#pragma once
#include "Book.h"
#include <vector>

class BookManager
{
private:
	vector<Book> books;

protected: // ManagePatter Class에서 사용할 예정
	bool addBook(string, string);
	int findByTitle(string);
	string findByAuthor(string);
	bool isHoldBook(string);

public:
	void displayAllBooks(); 
};

