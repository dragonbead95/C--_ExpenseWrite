#include "stream.h"

stream::stream()
{
	out.open("2018��_�����_TXT����.txt", ios::app);
	in.open("2018��_�����_TXT����.txt");
}
void stream::input(expense_info exin)
{
	out << exin.getDate() << '\t' << exin.getMoney() << '\t' << exin.getUsing() << '\t' << exin.getCategory() << endl;
	//out.close();
}
void stream::print()
{
	string in_line;
	ifstream in("2018��_�����_TXT����.txt");
	string buf;
	vector<string> tokens;

	ShowHeader();	// �޴� ���� ���
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

void stream::printCategorySum()	// �з��� �ݾ� ���� ���
{
	string in_line;
	ifstream in("2018��_�����_TXT����.txt");
	string buf;
	vector<string> tokens;
	
	int category_arr[13] = { 0 };
	string category_name[] = {" ","�ĺ�","�����","��ź�","���ĺ�","�����","��Ȱ��","å","������","������","�Ƿ��","�Ƿ���","��Ÿ" };

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

void stream::printSum()	// ���� �ݾ� ���� ���
{
	string in_line;
	ifstream in("2018��_�����_TXT����.txt");
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
	cout << "�ݾ� ����: "<<'\t'<< thousand_seperator(sum)<< endl;
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