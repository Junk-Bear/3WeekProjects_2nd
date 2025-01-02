#pragma once
#include<string>

using namespace std;

class Book
{
private:
	string title;
	string author;
public:
	string getTitle()
	{
		return title;
	}
	string getAuthor()
	{
		return author;
	}

	Book(string _title, string _author)
	{
		title = _title;
		author = _author;
	}
};


