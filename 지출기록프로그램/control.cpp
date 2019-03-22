#include "control.h"
#include "AccountException.h"
#include "expense_info.h"
#include "stream.h"

control::control() : num(0)
{

}

void control::write(stream * io)
{
	expense_info exin;	// 지출 정보가 들어있는 객체

	exin.expense_input();	// 지출정보를 입력받아 멤버에 저장
	

	try {
		string temp = exin.getDate().substr(5, 2);
		if (temp < "01" || temp >"12")
			throw DateException(exin.getDate());

		temp = exin.getDate().substr(8, 2);
		if (temp < "01" || temp>"31")
			throw DateException(exin.getDate());
		if (exin.getMoney() < 0)
			throw MinusException(exin.getMoney());

		io->input(exin);	// 입력받은 지출정보들을 txt파일에 저장한다.
		sort();	// 지출정보들을 정렬해서 txt파일에 다시 저장한다.
	}
	catch (ExpenseException &expn)
	{
		expn.ShowExceptionReason();
	}
	
}

// 연결리스트에서 날짜를 기준으로 정렬하는 기준함수
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

// test.txt에 있는 지출정보들을 list 자료구조로 옮기는 함수
void control::listInsert(List * list)
{
	string in_line;
	ifstream in("2018년_가계부_TXT버전.txt");
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
	ofstream out2("2018년_가계부_TXT버전.txt");
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

	ShowHeader();	// 메뉴 제목 출력
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

	cout << "금액 총합 : " << sum << endl;
}


void control::ShowDateSearch(string year,string month)
{
	List list;
	listInsert(&list);

	expense_info temp;
	string temp_date;
	int sum = 0;

	ShowHeader();	// 메뉴 제목 출력
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

	cout << "금액 총합 : " << sum << endl;
}


void control::ShowDateSearch(string year, string month, string day)
{
	List list;
	listInsert(&list);

	expense_info temp;
	string temp_date;
	int sum = 0;

	ShowHeader();	// 메뉴 제목 출력
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

	cout << "금액 총합 : " << sum << endl;
}


void control::ShowDateSearch()
{
	int number;
	string date;

	cout << "1. 연도별 검색" << endl;
	cout << "2. 월별 검색" << endl;
	cout << "3. 일별 검색" << endl;
	cout << "4.종료" << endl;
	cin >> number;

	if (number == 1)
	{
		cout << "원하시는 연도를 입력해주세요.(2019)" << endl;
		cin >> date;
		ShowDateSearch(date);
	}
	else if (number == 2)
	{
		cout << "연도와 월을 입력해주세요.(2019-02)" << endl;
		cin >> date;
		ShowDateSearch(date.substr(0, 4), date.substr(5, 2));
	}
	else if (number == 3)
	{
		cout << "연도와 월과 일을 입력해주세요(2019-02-02)" << endl;
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
	cout << "검색하고싶은 금액이상을 입력해주세요." << endl;
	cin >> m;

	int sum = 0;

	ShowHeader();	// 메뉴 제목 출력
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
	cout << "금액 총합 : " << sum << endl;
}


void control::ShowCategorySearch()
{
	List list;
	expense_info temp;
	int sum=0;
	string c;

	cout << "검색하고 싶은 분류를 한글로 입력해주세요." << endl;
	cout << "분류 : 1.식비 2.교통비 3.통신비 4.간식비 5.유흥비 6.생활비 7.도서비 8.교육비 9.문구비 10.의료비 11.의류비 12.기타" << endl;
	cin >> c;
	
	listInsert(&list);

	ShowHeader();	// 메뉴 제목 출력
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
	cout << "금액 총합 : " << sum << endl;
}

