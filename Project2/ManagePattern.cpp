#include "ManagePattern.h"
#include <iostream>

//매니지 패턴 : 책 추가, 북매니저에 책을 등록, 버로우매니저에 책 재고량을 등록
void ManagePattern::patternAddBook(string _title, string _author)
{
	if (addBook(_title, _author))
	{ 
		initStock(_title);
	}
}

//매니지 패턴 : 책 검색 및 대여 _searchType : 1 - 책으로 검색, 2 - 작가로 검색
void ManagePattern::patternBorrow(string _word, int _searchType)
{
	int input = 0;
	string str = "";
	switch (_searchType)
	{
	case 1:
		input = findByTitle(_word);
		if (input == 1)
			borrowBook(_word);
		break;
	case 2:
		str = findByAuthor(_word);
		if (str != "")
		{
			borrowBook(str);
		}
		break;
	}
}

//매니지 패턴 : 책 반납
void ManagePattern::patternReturnBook(string _title)
{
	if (isHoldBook(_title))
		returnBook(_title);
	else
		cout << "등록되지 않은 책입니다." << endl;
}
