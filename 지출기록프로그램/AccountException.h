#ifndef __ACCOUNT_EXCPETION_H_
#define __ACCOUNT_EXCPETION_H_

#include "library.h"

class ExpenseException
{
public:
	virtual void ShowExceptionReason() = 0;
};

class MinusException : public ExpenseException
{
private:
	int reqDep;	// ��� �ݾ�
public:
	MinusException(int money);
	void ShowExceptionReason();
};
/*
class CategoryException : public ExpenseException
{
private:
	string reqCate;	// ��û �з�
public:
	CategoryException(string myCategory);
	void ShowExceptionReason();
};
*/
class DateException : public ExpenseException
{
private:
	string str;
public:
	DateException(string s);
	void ShowExceptionReason();
};
#endif // !__ACCOUNT_EXCPETION_H_
