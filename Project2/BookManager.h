#pragma once
#include "Book.h"
#include <vector>

class BookManager
{
private:
	vector<Book> books;

public:
	void addBook(string, string);
	void displayAllBooks();
	void SearchByTitle(string);
	void SearchByAuthor(string);
};

