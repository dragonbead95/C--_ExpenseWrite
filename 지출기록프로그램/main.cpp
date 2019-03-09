/******************************************
날짜 : 2019-02-28
작성자 : 김용환
제목 : 지출 기록 프로그램
업데이트 : 0.4
업데이트 : 지출을 작성할때 메모장에 입력되게 만듬
2번 옵션인 지출전체검색시 메모장에서 읽어들여서
지출 데이터와 금액의 총합을 출력함
지출 작성시 날짜별로 정렬되서 입력되게 만들어야함
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
		manager.ShowMenu();
		cout << "선택 : ";
		cin >> number;

		switch (number)
		{
		case WRITE: manager.write(&io);
			break;
		case ALLSEARCH: manager.ShowAllExpense(&io);
			break;
		case SEARCH:
			manager.ShowSearchMenu();
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