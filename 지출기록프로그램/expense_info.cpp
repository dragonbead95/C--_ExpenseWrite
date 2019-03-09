
#include "expense_info.h"

void expense_info::expense_input()
{
	cout << "[날짜(2019-02-15), 금액, 용도, 분류]를 입력해주세요" << endl;
	cout << "분류 : 1.식비 2.교통비 3.통신비 4.간식비 5.유흥비 6.생활비 7.도서비 8.교육비 9.문구비 10.의료비 11.의류비 12.기타" << endl;

	cin >> myDate >> mymoney >> myUsing >> myCategory;
}
string expense_info::getDate() const
{
	return myDate;
}

int expense_info::getMoney() const
{
	return mymoney;
}

string expense_info::getUsing() const
{
	return myUsing;
}

int expense_info::getCategory() const
{
	return myCategory;
}
