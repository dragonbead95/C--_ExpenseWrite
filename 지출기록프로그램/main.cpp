/******************************************
��¥ : 2019-02-15
�ۼ��� : ���ȯ
���� : ���� ��� ���α׷�
������Ʈ : 0.1
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
		case EXIT: exit(1);
		default:
			continue;
		}
	}
}