/******************************************
날짜 : 2019-02-15
작성자 : 김용환
제목 : 지출 기록 프로그램
업데이트 : 0.1
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
		cout << "선택 : ";
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