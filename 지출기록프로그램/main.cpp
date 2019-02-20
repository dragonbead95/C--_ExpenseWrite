/******************************************
날짜 : 2019-02-16
작성자 : 김용환
제목 : 지출 기록 프로그램
업데이트 : 0.2
업데이트 : 날짜,금액,분류에 대한 예외처리 완료
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