/******************************************
��¥ : 2019-02-16
�ۼ��� : ���ȯ
���� : ���� ��� ���α׷�
������Ʈ : 0.2
������Ʈ : ��¥,�ݾ�,�з��� ���� ����ó�� �Ϸ�
*******************************************/
#include "control.h"
#include "ExpenseCommon.h"

int main(void)
{
	control manager;
	int number;
	while (1)
	{
		manager.ShowMenu();
		cout << "���� : ";
		cin >> number;

		switch (number)
		{
		case WRITE: manager.write();
			break;
		case ALLSEARCH: manager.ShowAllExpense();
			break;
		case SEARCH:
			manager.ShowSearchMenu();
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