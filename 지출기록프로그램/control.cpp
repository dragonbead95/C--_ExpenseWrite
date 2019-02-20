#include "control.h"
#include "AccountException.h"


control::control() : num(0)
{

}

void control::write()
{
	string myDate;	// 날짜
	int mymoney;	// 금액
	string myUsing;	// 용도
	int myCategory;	// 분류

	cout << "[날짜(2019-02-15), 금액, 용도, 분류]를 입력해주세요" << endl;
	cout << "분류 : 1.식비 2.교통비 3.통신비 4.간식비 5.유흥비 6.생활비 7.도서비 8.교육비 9.문구비 10.의료비 11.의류비 12.기타"<< endl;

	cin >> myDate >> mymoney >> myUsing >> myCategory;

	try {
		string temp = myDate.substr(5, 2);
		if (temp < "01" || temp >"12")
			throw DateException(myDate);

		temp = myDate.substr(8, 2);
		if (temp < "01" || temp>"31")
			throw DateException(myDate);
		if (mymoney < 0)
			throw MinusException(mymoney);
		if (myCategory < 1 || myCategory>12)
			throw CategoryException(myCategory);

		arr[num++] = new expense(myDate, mymoney, myUsing, myCategory);
	}
	catch (ExpenseException &expn)
	{
		expn.ShowExceptionReason();
	}
	
	
}

void control::ShowAllExpense() const
{
	for (int i = 0;i < num;i++)
	{
		arr[i]->ShowExpenseInfo();
	}
}

void control::ShowMenu() const
{
	cout << "1. 지출기록" << endl;
	cout << "2. 지출전체검색" << endl;
	cout << "3. 종료" << endl;
}