
#include "expense_info.h"

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
