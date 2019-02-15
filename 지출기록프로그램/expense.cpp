/******************************************
��¥ : 2019-02-15
�ۼ��� : ���ȯ
���� : ���� ��� ���α׷�
������Ʈ : 0.1
���ų��� : ���(expense) Ŭ���� �߰�
*******************************************/
#include "expense.h"

/*������*/
expense::expense()
{
	Date = NULL;
	money = 0;
	Using = NULL;
	category = 0;
}

/*������*/
expense::expense(String myDate, int myMoney, String myUsing, int myCategory)
	: money(myMoney),category(myCategory)
{
	Date = myDate;
	Using = myUsing;
}

/*��¥ ��ȯ*/
String expense::GetDate() const
{
	return Date;
}

/*�ݾ� ��ȯ*/
int expense::GetMoney() const
{
	return money;
}

/*�뵵 ��ȯ*/
String expense::GetUsing() const
{
	return Using;
}

/*�з� ��ȯ*/
int expense::GetCategory() const
{
	return category;
}

/*��¥ ����*/
void expense::SetDate(String myDate)
{
	Date = myDate;
}

/*�ݾ� ����*/
void expense::SetMoney(int myMoney)
{
	money = myMoney;
}

/*�뵵 ����*/
void expense::SetUsing(String myUsing)
{
	Using = myUsing;
}

/*�з� ����*/
void expense::Setcategory(int myCategory)
{
	category = myCategory;
}

/*���� ��� ���*/
void expense::ShowExpenseInfo() const
{
	cout << "��¥:" << Date
		<< " �ݾ�:" << money
		<< " �뵵:" << Using
		<< " �з�:";
	switch (category)
	{
	case FOOD:
		cout << "�ĺ�" << endl;
		break;
	case PUBLIC_TRANSFER:
		cout << "�����" << endl;
		break;
	case POSTAGE:
		cout << "��ź�" << endl;
		break;
	case SNACK:
		cout << "���ĺ�" << endl;
		break;
	case ENTERTAINMENT:
		cout << "�����" << endl;
		break;
	case LIFE:
		cout << "��Ȱ��" << endl;
		break;
	case BOOK:
		cout << "������" << endl;
		break;
	case EDUCATION:
		cout << "������" << endl;
		break;
	case STATIONARY:
		cout << "������" << endl;
		break;
	case MEDICAL:
		cout << "�Ƿ��" << endl;
		break;
	case CLOTHES:
		cout << "�Ƿ���" << endl;
		break;
	case ETC:
		cout << "��Ÿ" << endl;
		break;

	}
}