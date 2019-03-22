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
	ifstream in("2018��_�����_TXT����.txt");
	string buf;
	vector<string> tokens;

	while (getline(in, in_line))
	{
		stringstream ss(in_line);
		while (ss >> buf)
		{
			tokens.push_back(buf);
		}
		expense_info exbuf(tokens[0], atoi(tokens[1].c_str()), tokens[2],tokens[3]);

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
	ofstream out2("2018��_�����_TXT����.txt");
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
	io->printCategorySum();
	io->printSum();
}

void control::ShowMoneySum(stream * io)
{
	io->printSum();
}

void control::ShowDateSearch(string year)
{
	List list;
	listInsert(&list);

	expense_info temp;
	string temp_date;
	int sum = 0;

	ShowHeader();	// �޴� ���� ���
	if (list.LFirst(&temp))
	{
		temp_date = temp.getDate();
		if (temp_date.substr(0, 4) == year)
		{
			temp.ShowExpenseInfo();
			sum += temp.getMoney();
		}
		
		while (list.LNext(&temp))
		{
			temp_date = temp.getDate();
			if (temp_date.substr(0, 4) == year)
			{
				temp.ShowExpenseInfo();
				sum += temp.getMoney();
			}
		}
	}

	cout << "�ݾ� ���� : " << sum << endl;
}


void control::ShowDateSearch(string year,string month)
{
	List list;
	listInsert(&list);

	expense_info temp;
	string temp_date;
	int sum = 0;

	ShowHeader();	// �޴� ���� ���
	if (list.LFirst(&temp))
	{
		temp_date = temp.getDate();
		if (temp_date.substr(0, 4) == year && temp_date.substr(5, 2) == month)
		{
			temp.ShowExpenseInfo();
			sum += temp.getMoney();
		}

		while (list.LNext(&temp))
		{
			temp_date = temp.getDate();
			if (temp_date.substr(0, 4) == year && temp_date.substr(5, 2) == month)
			{
				temp.ShowExpenseInfo();
				sum += temp.getMoney();
			}
		}
	}

	cout << "�ݾ� ���� : " << sum << endl;
}


void control::ShowDateSearch(string year, string month, string day)
{
	List list;
	listInsert(&list);

	expense_info temp;
	string temp_date;
	int sum = 0;

	ShowHeader();	// �޴� ���� ���
	if (list.LFirst(&temp))
	{
		temp_date = temp.getDate();
		if (temp_date.substr(0, 4) == year && temp_date.substr(5, 2) == month && temp_date.substr(8, 2) == day)
		{
			temp.ShowExpenseInfo();
			sum += temp.getMoney();
		}

		while (list.LNext(&temp))
		{
			temp_date = temp.getDate();
			if (temp_date.substr(0, 4) == year && temp_date.substr(5, 2) == month && temp_date.substr(8, 2) == day)
			{
				temp.ShowExpenseInfo();
				sum += temp.getMoney();
			}
		}
	}

	cout << "�ݾ� ���� : " << sum << endl;
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
	List list;
	listInsert(&list);
	expense_info temp;

	int m;
	cout << "�˻��ϰ���� �ݾ��̻��� �Է����ּ���." << endl;
	cin >> m;

	int sum = 0;

	ShowHeader();	// �޴� ���� ���
	if (list.LFirst(&temp))
	{
		if (temp.getMoney()>=m)
		{
			temp.ShowExpenseInfo();
			sum += temp.getMoney();
		}

		while (list.LNext(&temp))
		{
			if (temp.getMoney() >= m)
			{
				temp.ShowExpenseInfo();
				sum += temp.getMoney();
			}
		}
	}
	cout << "�ݾ� ���� : " << sum << endl;
}


void control::ShowCategorySearch()
{
	List list;
	expense_info temp;
	int sum=0;
	string c;

	cout << "�˻��ϰ� ���� �з��� �ѱ۷� �Է����ּ���." << endl;
	cout << "�з� : 1.�ĺ� 2.����� 3.��ź� 4.���ĺ� 5.����� 6.��Ȱ�� 7.������ 8.������ 9.������ 10.�Ƿ�� 11.�Ƿ��� 12.��Ÿ" << endl;
	cin >> c;
	
	listInsert(&list);

	ShowHeader();	// �޴� ���� ���
	if (list.LFirst(&temp))
	{
		if (temp.getCategory()==c)
		{
			temp.ShowExpenseInfo();
			sum += temp.getMoney();
		}

		while (list.LNext(&temp))
		{
			if (temp.getCategory() == c)
			{
				temp.ShowExpenseInfo();
				sum += temp.getMoney();
			}
		}
	}
	cout << "�ݾ� ���� : " << sum << endl;
}

