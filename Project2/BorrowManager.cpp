#include "BorrowManager.h"
#include <iostream>
#define DEFAULT_BOOK_STOCK 3

//들여온 책의 재고량을 DEFAULT_BOOK_STOCK으로 맞춤
void BorrowManager::initStock(string _title)
{
	stock.insert(make_pair(_title, DEFAULT_BOOK_STOCK));
	cout << "등록완료" << endl;
}

//재고량이 있으면 책을 빌림, 없으면 대여할 재고량이 없다고 알림
//책이 있는지 확인해야함 - BookManager findByTitle이나 findByAuthor로 확인(메인에서)
void BorrowManager::borrowBook(string _title)
{
	if (stock[_title] != 0)
	{
		stock[_title]--;
		cout << "책:" << _title << "를(을) 빌렸습니다, 남은 재고량 : " << stock[_title] << endl;
	}
	else
	{
		cout << "책이 모두 대여된 상태입니다." << endl;
	}
}

//책을 반납하여 재고량 추가
//책이 있던 책인지 확인해야함 - BookManager isHoldBook을 통해 알아보기(메인에서)
void BorrowManager::returnBook(string _title)
{
	if (stock[_title] < 3)
	{
		stock[_title]++;
		cout << "책:" << _title << "이(가) 반납되었습니다, 남은 재고량 : " << stock[_title] << endl;
	}
	else
		cout << "재고량이 꽉참 : 어디서 줏어온 책인가?" << endl;
}

//현재 모든 책과 그 재고 사항을 보여줌
void BorrowManager::displayStock()
{
	for (map<string, int>::iterator it = stock.begin(); it != stock.end(); it++)
	{
		cout << "책 제목 : " << it->first << ", 현재 재고량 : " << it->second << endl;
	}
}

