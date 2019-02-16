#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;

class String
{
private:
	int len;
	char * str;
public:
	String();
	String(const char * s);	// 생성자
	String(const String& s);	// 복사 생성자
	~String();	// 소멸자
	String& operator=(const String& s);	// 대입 연산자
	String operator+(const String& s);	// +연산자의 오버로딩
	String& operator+=(const String& s);	// +=연산자의 오버로딩
	bool operator==(const String& s);	// ==연산자의 오버로딩
	friend ostream& operator<<(ostream& os, const String& s);	//<<연산자
	friend istream& operator>>(istream& is, String& s);	//>> 연산자
	bool isDate() const; // 날짜검사
};

#endif
