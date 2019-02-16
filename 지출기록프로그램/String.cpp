#include "String.h"


String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char * s)
{
	len = strlen(s) + 1;
	str = new char[len];	// 동적할당
	strcpy_s(str, len, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len];	// 동적할당
	strcpy_s(str, len, s.str);
}

String::~String()
{
	if (str != NULL)
	{
		delete[]str;
	}

}

String& String::operator=(const String& s)
{
	if (str != NULL)
	{
		delete[]str;
	}
	len = s.len;
	str = new char[len];
	strcpy_s(str, len, s.str);
	return *this;
}

String& String::operator+=(const String& s)
{
	len += (s.len - 1);
	char * tempstr = new char[len];
	strcpy_s(tempstr, len, str);
	strcat_s(tempstr, len, s.str);

	if (str != NULL)
	{
		delete[]str;
	}
	str = tempstr;
	return *this;
}

bool String::operator==(const String& s)
{

	if (strcmp(str, s.str) == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

String String::operator+(const String& s)
{
	int templen = len + s.len - 1;
	char * tempstr = new char[templen];	// len과 s.len에서 +1 +1로 인해서 -1을 안해주면 1칸 더 많아진다.
	strcpy_s(tempstr, templen, s.str);
	strcat_s(tempstr, templen, s.str);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

bool String::isDate() const
{
	int len = strlen(str);
	if (len != 10)
	{
		cout << str << "은(는) 정확한 규격이 아닙니다." << endl;
		return false;
	}

	for (int k = 0;k <len;k++)
	{
		if (k == 4 || k == 7)
		{
			if ((str[k] == '-') == false)
				return false;
		}
		else {
			if ((str[k] >= '0' && str[k] <= '9') == false)
				return false;
		}
	}
	/*str중에 1월부터 12월까지만 제한을 두어야 하는데 일단 조각조각 검사되서
	숫자는 맞지만 13이나 14같이 월을 넘어간 숫자도 참으로 문제는되는 상황
	고치기 위해서는 월과 일을 따로 검사해야 되는 상황, 좀더 보완해야 함!!
	String 사용자 정의에 substr을 만들어야함
	*/

	return true;
}