/******************************************
��¥ : 2019-03-22
�ۼ��� : ���ȯ
���� : ���� ��� ���α׷�
������Ʈ : 1
������Ʈ : 
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
		cout << "���� : ";
		cin >> number;

		switch (number)
		{
		case WRITE: manager.write(&io);
			break;
		case ALLSEARCH: manager.ShowAllExpense(&io);
			break;
		case SEARCH:
			ShowSearchMenu();
			cout << "���� : ";
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