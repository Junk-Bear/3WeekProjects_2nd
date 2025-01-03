#include "BookManager.h"
#include <iostream>

// 타이틀, 작가명 받아서 books에 추가
bool BookManager::addBook(string _title, string _author)
{

	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getTitle() == _title)
		{
			cout << "이미 등록된 책(작가 상관없음)" << endl;
			return false;
		}
	}

	Book newBook(_title, _author);
	books.push_back(newBook);
	return true;
}

// 순회해서 모두 보여줌(제목, 작가)
void BookManager::displayAllBooks()
{
	for (int i = 0; i < books.size(); i++)
	{
		cout << "책 제목 : " << books[i].getTitle() << ", 작가: " << books[i].getAuthor() << endl;
	}
}

// 제목으로 검색해서 있으면 있고, 책을 대여할건지 물어봄, 없으면 없다고 알림
int BookManager::findByTitle(string _title)
{
	bool isexist = false;

	cout << endl;
	cout << "-----검색 결과------" << endl;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getTitle() == _title)
		{
			isexist = true;
			cout << "등록되어 있는 책입니다." << endl;

			string input = "";
			//책을 빌릴지에 대한 여부
			while (1)
			{
				cout << endl;
				cout << "책을 빌리시겠습니까? (예 : 1, 아니오 : 2) : ";
				cin >> input;

				if (input == "1" || input == "2")
				{
					return stoi(input);
				}
				else
				{
					cout << "잘못된 제목 입력. 다시 눌러주시오" << endl;
				}
				break;
			}
		}
	}
	if (!isexist)
		cout << "등록되지 않은 책입니다." << endl;

	return 0;
}

// 작가로 검색해서 해당 작가의 모든 책을 보여주고 어떤책을 가져갈건지 물어봄, 없으면 없다 알림
string BookManager::findByAuthor(string _author)
{
	bool isexist = false;
	vector<string> authorBooks;

	cout << endl;
	cout << "-----검색 결과------" << endl;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getAuthor() == _author)
		{
			isexist = true;
			authorBooks.push_back(books[i].getTitle()); // 작가의 책들 임시저장 : 대여할 책 찾을때 books 전체 순회 안하게
			cout << "책 제목 : " << books[i].getTitle() << endl;
		}
	}

	string input = "";
	//책을 빌릴지에 대한 여부
	while (1)
	{
		cout << endl;
		cout << "어떤 책을 빌리시겠습니까? (예 : 빌릴 책을 입력, 아니오 : 000을 입력) : ";
		cin >> input;
		if (input == "000")
		{
			return "";
		}
		else
		{
			for (int i = 0; i < authorBooks.size(); i++)
			{
				if (authorBooks[i] == input)
					return input;
			}

			cout << "잘못된 버튼 입력. 다시 눌러주시오" << endl;
		}
		break;
	}

	if (!isexist)
		cout << "해당 작가의 책이 없음" << endl;

	return "";
}

bool BookManager::isHoldBook(string _title)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getTitle() == _title)
			return true;
	}

	return false;
}
