#include "stream.h"

stream::stream()
{
	out.open("2018년_가계부_TXT버전.txt", ios::app);
	in.open("2018년_가계부_TXT버전.txt");
}
void stream::input(expense_info exin)
{
	out << exin.getDate() << '\t' << exin.getMoney() << '\t' << exin.getUsing() << '\t' << exin.getCategory() << endl;
	//out.close();
}
void stream::print()
{
	string in_line;
	ifstream in("2018년_가계부_TXT버전.txt");
	string buf;
	vector<string> tokens;

	ShowHeader();	// 메뉴 제목 출력
	while (getline(in, in_line))
	{
		stringstream ss(in_line);
		while (ss >> buf)
		{
			tokens.push_back(buf);
		}
		
		for (int i = 0;i < (signed int)tokens.size();i++)
		{
			if (i == 1)
			{
				cout << thousand_seperator(atoi(tokens[i].c_str())) << '\t';
			}
			else {
				cout << tokens[i] << '\t';
			}
		}

		cout << endl;
		tokens.clear();
	}

	in.close();
}

void stream::printCategorySum()	// 분류별 금액 총합 출력
{
	string in_line;
	ifstream in("2018년_가계부_TXT버전.txt");
	string buf;
	vector<string> tokens;
	
	int category_arr[13] = { 0 };
	string category_name[] = {" ","식비","교통비","통신비","간식비","유흥비","생활비","책","교육비","문구비","의료비","의류비","기타" };

	while (getline(in, in_line))
	{
		stringstream ss(in_line);
		while (ss >> buf)
		{
			tokens.push_back(buf);
		}

		for (int i = 1;i < 13;i++)
		{
			if (tokens[3] == category_name[i])
			{
				category_arr[i] += atoi(tokens[1].c_str());
			}
		}
		tokens.clear();
	}

	for (int i = 1;i < 13;i++)
	{
		cout << category_name[i] <<'\t'<<" : " <<'\t'<< thousand_seperator(category_arr[i]) << endl;
	}
	in.close();
}

void stream::printSum()	// 지출 금액 총합 출력
{
	string in_line;
	ifstream in("2018년_가계부_TXT버전.txt");
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
	cout << "금액 총합: "<<'\t'<< thousand_seperator(sum)<< endl;
	in.close();
}

string stream::thousand_seperator(int uValue)
{
	string strValueTS;

	int j, i = 0, k = 0;
	int temp = uValue;
	int p = 1;

	while (temp > 0) //counting number of digits
	{
		temp /= 10;
		p *= 10;
		i++;
	}
	j = i % 3;
	p /= 10;
	while (i > 0)//display integer number with 1000 seperator
	{
		strValueTS += char((uValue / p) + '0');
		uValue %= p;
		p /= 10;
		i--;
		k++;
		j--;
		if ((k % 3 == 0 && i > 0) || (j == 0 && i > 2))
		{
			strValueTS += ",";
			k = 0;
		}
	}
	return strValueTS;

}