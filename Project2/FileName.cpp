#include <iostream>
#include "ManagePattern.h"

int main()
{
	ManagePattern bookSystem;
	bookSystem.patternAddBook("신간1호", "장씨");
	bookSystem.patternAddBook("신간2호", "장씨");
	bookSystem.patternAddBook("신간3호", "장씨");
	bookSystem.patternAddBook("할렐루야", "김씨");
	bookSystem.patternAddBook("울랄라", "김씨");

	string inputKey = "";
	cout << "책방에 오신걸 환영합니다." << endl;
	while (1)
	{
		cout << endl;
		cout << "다음을 입력하여 주세요 : 책(또는 작가)을 검색하고 빌린다(1), 책을 반납한다(2), 책방의 모든 책과 재고를 본다(3), 동일한 책 3권을 추가한다(4), 나간다(0)" << endl;
		cin >> inputKey;

		string inputSearchType = "";
		string str1 = "";
		string str2 = "";

		if (inputKey == "1") // 검색 후 대여 여부
		{
			while (1)
			{
				cout << endl;
				cout << "책검색 : 1, 작가검색 : 2 를 눌러주세요 (벗어나기 : 0) : ";
				cin >> inputSearchType;

				if (inputSearchType == "1" || inputSearchType == "2" || inputSearchType == "0")
				{
					if (inputSearchType == "0")
						break;
					else
					{
						cout << "검색 단어 입력 (일치해야함) : ";
						cin >> str1;
						bookSystem.patternBorrow(str1, stoi(inputSearchType));
					}
				}
				else
				{
					cout << "잘못된 버튼 입력. 다시 눌러주시오" << endl;
				}
			}
		}
		else if (inputKey == "2") // 책 반납
		{
			cout << endl;
			cout << "반납할 책 제목을 입력하세요 :";
			cin >> str1;

			bookSystem.patternReturnBook(str1);
		}
		else if (inputKey == "3") // 모든 책과 그 재고를 보기
		{
			bookSystem.displayStock();
		}
		else if (inputKey == "4") // 책 추가
		{
			cout << endl;
			cout << "책 제목과 작가를 입력해 주세요" << endl;
			cout << "책 제목 : ";
			cin >> str1;
			cout << "작가 : ";
			cin >> str2;

			bookSystem.patternAddBook(str1, str2);
		}
		else if (inputKey == "0") // 끝
		{
			return 0;
		}
		else // 잘못된 입력 다시 선택하게 하기
		{
			cout << "잘못된 버튼 입력. 다시 눌러주시오" << endl;
		}
	}
}