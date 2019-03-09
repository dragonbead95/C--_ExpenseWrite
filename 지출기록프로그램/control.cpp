#include "control.h"
#include "AccountException.h"
#include "expense_info.h"
#include "stream.h"

control::control() : num(0)
{

}

void control::write(stream * io)
{
	expense_info exin;	// ���� ������ ����ִ� ��ü

	exin.expense_input();	// ���������� �Է¹޾� ����� ����
	

	try {
		string temp = exin.getDate().substr(5, 2);
		if (temp < "01" || temp >"12")
			throw DateException(exin.getDate());

		temp = exin.getDate().substr(8, 2);
		if (temp < "01" || temp>"31")
			throw DateException(exin.getDate());
		if (exin.getMoney() < 0)
			throw MinusException(exin.getMoney());
		if (exin.getCategory() < 1 || exin.getCategory()>12)
			throw CategoryException(exin.getCategory());

		io->input(exin);
	}
	catch (ExpenseException &expn)
	{
		expn.ShowExceptionReason();
	}
	
}

void control::ShowAllExpense(stream * io)
{
	io->print();
	io->printSum();
}

void control::ShowMoneySum(stream * io)
{
	io->printSum();
}

void control::ShowDateSearch(string year)
{
	string temp;
	int sum = 0;
	for (int i = 0;i < num;i++)
	{
		temp = arr[i]->GetDate();
		if (temp.substr(0, 4) == year)
		{
			arr[i]->ShowExpenseInfo();
			sum += arr[i]->GetMoney();
		}
	}
	cout << "�ݾ� ���� : " << sum << endl;
}

void control::ShowDateSearch(string year,string month)
{
	string temp;
	int sum = 0;
	for (int i = 0;i < num;i++)
	{
		temp = arr[i]->GetDate();
		if (temp.substr(0, 4) == year && temp.substr(5,2)==month)
		{
			arr[i]->ShowExpenseInfo();
			sum += arr[i]->GetMoney();
		}
	}
	cout << "�ݾ� ���� : " << sum << endl;
}

void control::ShowDateSearch(string year, string month, string day)
{
	string temp;
	int sum = 0;
	for (int i = 0;i < num;i++)
	{
		temp = arr[i]->GetDate();
		if (temp.substr(0, 4) == year && temp.substr(5, 2) == month && temp.substr(8,2)==day)
		{
			arr[i]->ShowExpenseInfo();
			sum += arr[i]->GetMoney();
		}
	}
	cout << "�ݾ� ���� : " << sum << endl;
}

void control::ShowMenu() const
{
	cout << "1. ������" << endl;
	cout << "2. ������ü�˻�" << endl;
	cout << "3. ����˻�" << endl;
	cout << "4. ����" << endl;
}

void control::ShowSearchMenu() const
{
	cout << "1. ��¥�� �˻�" << endl;
	cout << "2. �ݾ׺� �˻�" << endl;
	cout << "3. �з��� �˻�" << endl;
	cout << "4. �ڷΰ���" << endl;
	cout << "5. ����" << endl;
}

void control::ShowDateSearch()
{
	int number;
	string date;

	cout << "1. ������ �˻�" << endl;
	cout << "2. ���� �˻�" << endl;
	cout << "3. �Ϻ� �˻�" << endl;
	cout << "4.����" << endl;
	cin >> number;

	if (number == 1)
	{
		cout << "���Ͻô� ������ �Է����ּ���.(2019)" << endl;
		cin >> date;
		ShowDateSearch(date);
	}
	else if (number == 2)
	{
		cout << "������ ���� �Է����ּ���.(2019-02)" << endl;
		cin >> date;
		ShowDateSearch(date.substr(0, 4), date.substr(5, 2));
	}
	else if (number == 3)
	{
		cout << "������ ���� ���� �Է����ּ���(2019-02-02)" << endl;
		cin >> date;
		ShowDateSearch(date.substr(0, 4), date.substr(5, 2),date.substr(8,2));
	}
	else if (number == 4)
	{
		exit(1);
	}
	else {
		return;
	}
}

void control::ShowMoneySearch()
{
	int m;
	cout << "�˻��ϰ���� �ݾ��̻��� �Է����ּ���." << endl;
	cin >> m;

	int sum = 0;
	for (int i = 0;i < num;i++)
	{
		if (arr[i]->GetMoney() >= m)
		{
			arr[i]->ShowExpenseInfo();
			sum += arr[i]->GetMoney();
		}
	}
	cout << "�ݾ� ���� : " << sum << endl;
}

void control::ShowCategorySearch()
{
	int c,sum=0;
	cout << "�˻��ϰ� ���� �з��� �Է����ּ���." << endl;
	cout << "�з� : 1.�ĺ� 2.����� 3.��ź� 4.���ĺ� 5.����� 6.��Ȱ�� 7.������ 8.������ 9.������ 10.�Ƿ�� 11.�Ƿ��� 12.��Ÿ" << endl;
	cin >> c;
	
	for (int i = 0;i < num;i++)
	{
		if (arr[i]->GetCategory() == c)
		{
			arr[i]->ShowExpenseInfo();
			sum += arr[i]->GetMoney();
		}
	}
	cout << "�ݾ� ���� : " << sum << endl;
}