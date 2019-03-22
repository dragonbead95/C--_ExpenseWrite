
#include "expense_info.h"
#include "ExpenseCommon.h"

expense_info::expense_info()
{

}
expense_info::expense_info(string d, int m, string u, string c)
	: myDate(d), mymoney(m), myUsing(u), myCategory(c)
{

}

/*���� ��� ���*/
void expense_info::ShowExpenseInfo() const
{
	string category_name[] = { " ","�ĺ�","�����","��ź�","���ĺ�","�����","��Ȱ��","å","������","������","�Ƿ��","�Ƿ���","��Ÿ" };

	
	cout << myDate << '\t' << mymoney << '\t' << myUsing << '\t';

	for (int i = 1;i < 13;i++)
	{
		if (myCategory == category_name[i])
			cout << category_name[i]<< endl;
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

string expense_info::getCategory() const
{
	return myCategory;
}
