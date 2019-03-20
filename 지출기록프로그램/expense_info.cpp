
#include "expense_info.h"
#include "ExpenseCommon.h"

expense_info::expense_info()
{

}
expense_info::expense_info(string d, int m, string u, int c)
	: myDate(d), mymoney(m), myUsing(u), myCategory(c)
{

}

/*���� ��� ���*/
void expense_info::ShowExpenseInfo() const
{
	cout << "��¥:" << myDate
		<< " �ݾ�:" << mymoney
		<< " �뵵:" << myUsing
		<< " �з�:";
	switch (myCategory)
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

void expense_info::expense_input()
{
	cout << "[��¥(2019-02-15), �ݾ�, �뵵, �з�]�� �Է����ּ���" << endl;
	cout << "�з� : 1.�ĺ� 2.����� 3.��ź� 4.���ĺ� 5.����� 6.��Ȱ�� 7.������ 8.������ 9.������ 10.�Ƿ�� 11.�Ƿ��� 12.��Ÿ" << endl;

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
