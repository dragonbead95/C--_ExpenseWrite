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

		io->input(exin);	// �Է¹��� ������������ txt���Ͽ� �����Ѵ�.
		sort();	// ������������ �����ؼ� txt���Ͽ� �ٽ� �����Ѵ�.
	}
	catch (ExpenseException &expn)
	{
		expn.ShowExceptionReason();
	}
	
}

// ���Ḯ��Ʈ���� ��¥�� �������� �����ϴ� �����Լ�
int WhoIsPreced(LData data1, LData data2)
{
	int year1, year2;
	int month1, month2;
	int day1, day2;

	year1 = atoi(data1.getDate().substr(0, 4).c_str());
	year2 = atoi(data2.getDate().substr(0, 4).c_str());

	month1 = atoi(data1.getDate().substr(5, 2).c_str());
	month2 = atoi(data2.getDate().substr(5, 2).c_str());

	day1 = atoi(data1.getDate().substr(8, 2).c_str());
	day2 = atoi(data2.getDate().substr(8, 2).c_str());

	if (year1 == year2)
	{
		if (month1 == month2)
		{
			if (day1 == day2)
				return 0;
			else if (day1 < day2)
				return 0;
			else
				return 1;
		}
		else if (month1 < month2)
			return 0;
		else
			return 1;
	}
	else if (year1 < year2)
	{
		return 0;
	}
	else {
		return 1;
	}

}

// test.txt�� �ִ� ������������ list �ڷᱸ���� �ű�� �Լ�
void control::listInsert(List * list)
{
	string in_line;
	ifstream in("test.txt");
	string buf;
	vector<string> tokens;

	while (getline(in, in_line))
	{
		stringstream ss(in_line);
		while (ss >> buf)
		{
			tokens.push_back(buf);
		}
		expense_info exbuf(tokens[0], atoi(tokens[1].c_str()), tokens[2], atoi(tokens[3].c_str()));

		list->LInsert(exbuf);
		tokens.clear();
	}

	in.close();
}

void control::sort()
{
	List list;
	list.SetSortRule(WhoIsPreced);
	listInsert(&list);
	ofstream out2("test.txt");
	expense_info temp;

	if (list.LFirst(&temp))
	{
		out2 << temp.getDate() << '\t' << temp.getMoney() << '\t' << temp.getUsing() << '\t' << temp.getCategory() << endl;

		while (list.LNext(&temp))
		{
			out2 << temp.getDate() << '\t' << temp.getMoney() << '\t' << temp.getUsing() << '\t' << temp.getCategory() << endl;
		}
	}
	out2.close();
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
/*
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
*/
/*
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
*/
/*
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
*/
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
/*
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
*/
/*
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
*/
/*
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
*/