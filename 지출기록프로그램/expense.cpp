#include "expense.h"

/*������*/
expense::expense()
{
	Date = "";
	money = 0;
	Using = "";
	category = 0;
}

/*������*/
expense::expense(string myDate, int myMoney, string myUsing, int myCategory)
	: money(myMoney),category(myCategory)
{
	Date = myDate;
	Using = myUsing;
}

/*��¥ ��ȯ*/
string expense::GetDate() const
{
	return Date;
}

/*�ݾ� ��ȯ*/
int expense::GetMoney() const
{
	return money;
}

/*�뵵 ��ȯ*/
string expense::GetUsing() const
{
	return Using;
}

/*�з� ��ȯ*/
int expense::GetCategory() const
{
	return category;
}

/*��¥ ����*/
void expense::SetDate(string myDate)
{
	Date = myDate;
}

/*�ݾ� ����*/
void expense::SetMoney(int myMoney)
{
	money = myMoney;
}

/*�뵵 ����*/
void expense::SetUsing(string myUsing)
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