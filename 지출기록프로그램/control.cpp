#include "control.h"
#include "AccountException.h"


control::control() : num(0)
{

}

void control::write()
{
	string myDate;	// ��¥
	int mymoney;	// �ݾ�
	string myUsing;	// �뵵
	int myCategory;	// �з�

	cout << "[��¥(2019-02-15), �ݾ�, �뵵, �з�]�� �Է����ּ���" << endl;
	cout << "�з� : 1.�ĺ� 2.����� 3.��ź� 4.���ĺ� 5.����� 6.��Ȱ�� 7.������ 8.������ 9.������ 10.�Ƿ�� 11.�Ƿ��� 12.��Ÿ"<< endl;

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
	cout << "1. ������" << endl;
	cout << "2. ������ü�˻�" << endl;
	cout << "3. ����" << endl;
}