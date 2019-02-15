/******************************************
날짜 : 2019-02-15
작성자 : 김용환
제목 : 지출 기록 프로그램
업데이트 : 0.1
갱신내용 : 비용(expense) 클래스 추가
*******************************************/
#include "expense.h"

/*생성자*/
expense::expense()
{
	Date = NULL;
	money = 0;
	Using = NULL;
	category = 0;
}

/*생성자*/
expense::expense(String myDate, int myMoney, String myUsing, int myCategory)
	: money(myMoney),category(myCategory)
{
	Date = myDate;
	Using = myUsing;
}

/*날짜 반환*/
String expense::GetDate() const
{
	return Date;
}

/*금액 반환*/
int expense::GetMoney() const
{
	return money;
}

/*용도 반환*/
String expense::GetUsing() const
{
	return Using;
}

/*분류 반환*/
int expense::GetCategory() const
{
	return category;
}

/*날짜 설정*/
void expense::SetDate(String myDate)
{
	Date = myDate;
}

/*금액 설정*/
void expense::SetMoney(int myMoney)
{
	money = myMoney;
}

/*용도 설정*/
void expense::SetUsing(String myUsing)
{
	Using = myUsing;
}

/*분류 설정*/
void expense::Setcategory(int myCategory)
{
	category = myCategory;
}

/*지출 기록 출력*/
void expense::ShowExpenseInfo() const
{
	cout << "날짜:" << Date
		<< " 금액:" << money
		<< " 용도:" << Using
		<< " 분류:";
	switch (category)
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