#include <iostream>
#include "BookManager.h"


int main()
{
	BookManager bm;
	bm.addBook("할렐루야", "우랄라");

	bm.displayAllBooks();

	bm.SearchByAuthor("울랄라");
	bm.SearchByAuthor("우랄라");

	return 0;
}