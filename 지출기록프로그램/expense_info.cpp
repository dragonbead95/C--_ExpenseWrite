
#include "expense_info.h"
#include "ExpenseCommon.h"

expense_info::expense_info()
{

}
expense_info::expense_info(string d, int m, string u, string c)
	: myDate(d), mymoney(m), myUsing(u), myCategory(c)
{

}

/*지출 기록 출력*/
void expense_info::ShowExpenseInfo() const
{
	string category_name[] = { " ","식비","교통비","통신비","간식비","유흥비","생활비","책","교육비","문구비","의료비","의류비","기타" };

	
	cout << myDate << '\t' << mymoney << '\t' << myUsing << '\t';

	for (int i = 1;i < 13;i++)
	{
		if (myCategory == category_name[i])
			cout << category_name[i]<< endl;
	}
}

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

string expense_info::getCategory() const
{
	return myCategory;
}
