#include "stream.h"

stream::stream()
{
	out.open("test.txt", ios::app);
	in.open("test.txt");
}
void stream::input(expense_info exin)
{
	out << exin.getDate() << '\t' << exin.getMoney() << '\t' << exin.getUsing() << '\t' << exin.getCategory() << endl;
	//out.close();
}
void stream::print()
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

		for (int i = 0;i < (signed int)tokens.size();i++)
		{
			cout << tokens[i] << '\t';
		}

		cout << endl;
		tokens.clear();
	}

	in.close();
}

void stream::printSum()	// 지출 금액 총합 출력
{
	string in_line;
	ifstream in("test.txt");
	string buf;
	vector<string> tokens;
	int sum = 0;
	while (getline(in, in_line))
	{
		stringstream ss(in_line);
		while (ss >> buf)
		{
			tokens.push_back(buf);
		}
		sum += atoi(tokens[1].c_str());
		tokens.clear();
	}
	cout << "금액 총합 : " << sum << endl;
	in.close();
}