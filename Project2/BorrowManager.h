#pragma once
#include<map>
#include<string>
#include "Book.h"

using namespace std;

class BorrowManager
{
private: 
	map<string, int> stock;

protected: // ManagePatter Class에서 사용할 예정
	void initStock(string);
	void borrowBook(string);
	void returnBook(string);
	
public:
	void displayStock();
};

