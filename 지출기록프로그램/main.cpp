/******************************************
날짜 : 2019-03-22
작성자 : 김용환
제목 : 지출 기록 프로그램
업데이트 : 1
업데이트 : 
*******************************************/
#include "control.h"
#include "ExpenseCommon.h"
#include "stream.h"

int main(void)
{
	control manager;
	stream io;
	int number;
	
	while (1)
	{
		ShowMenu();
		cout << "선택 : ";
		cin >> number;

		switch (number)
		{
		case WRITE: manager.write(&io);
			break;
		case ALLSEARCH: manager.ShowAllExpense(&io);
			break;
		case SEARCH:
			ShowSearchMenu();
			cout << "선택 : ";
			cin >> number;
			switch (number)
			{
			case search::DATE_SEARCH:
				manager.ShowDateSearch();
				break;
			case search::MONEY_SEARCH:
				manager.ShowMoneySearch();
				break;
			case search::CATEGORY_SEARCH:
				manager.ShowCategorySearch();
				break;
			case search::BACK:
				break;
			case search::SEARCH_EXIT:
				exit(1);
			}
			break;
		case EXIT: exit(1);
		default:
			continue;
		}
	}
}