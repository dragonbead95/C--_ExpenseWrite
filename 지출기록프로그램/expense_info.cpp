
#include "expense_info.h"
#include "ExpenseCommon.h"

expense_info::expense_info()
{

}
expense_info::expense_info(string d, int m, string u, int c)
	: myDate(d), mymoney(m), myUsing(u), myCategory(c)
{

}

/*지출 기록 출력*/
void expense_info::ShowExpenseInfo() const
{
	cout << "날짜:" << myDate
		<< " 금액:" << mymoney
		<< " 용도:" << myUsing
		<< " 분류:";
	switch (myCategory)
	{
	case FOOD:
		cout << "식비" << endl;
		break;
	case PUBLIC_TRANSFER:
		cout << "교통비" << endl;
		break;
	case POSTAGE:
		cout << "통신비" << endl;
		break;
	case SNACK:
		cout << "간식비" << endl;
		break;
	case ENTERTAINMENT:
		cout << "유흥비" << endl;
		break;
	case LIFE:
		cout << "생활비" << endl;
		break;
	case BOOK:
		cout << "도서비" << endl;
		break;
	case EDUCATION:
		cout << "교육비" << endl;
		break;
	case STATIONARY:
		cout << "문구비" << endl;
		break;
	case MEDICAL:
		cout << "의료비" << endl;
		break;
	case CLOTHES:
		cout << "의류비" << endl;
		break;
	case ETC:
		cout << "기타" << endl;
		break;

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

int expense_info::getCategory() const
{
	return myCategory;
}
