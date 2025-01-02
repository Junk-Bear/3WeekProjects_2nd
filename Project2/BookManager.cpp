#include "BookManager.h"
#include <iostream>

void BookManager::addBook(string _title, string _author)
{
	Book newBook(_title, _author);
	books.push_back(newBook);
}

void BookManager::displayAllBooks()
{
	for (int i = 0; i < books.size(); i++)
	{
		cout << "책 제목 : " << books[i].getTitle() << ", 작가: " << books[i].getAuthor() << endl;
	}
}

void BookManager::SearchByTitle(string _title)
{
	bool isexist = false;

	cout << "-----검색 결과------" << endl;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getTitle() == _title)
		{
			isexist = true;
			cout << "책이 존재함" << endl;
			break;
		}
	}
	if (!isexist)
		cout << "해당 책이 없음" << endl;
}

void BookManager::SearchByAuthor(string _author)
{
	bool isexist = false;

	cout << "-----검색 결과------" << endl;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getAuthor() == _author)
		{
			isexist = true;
			cout << "책 제목 : " << books[i].getTitle() << endl;
		}
	}
	if (!isexist)
		cout << "해당 작가의 책이 없음" << endl;
}
