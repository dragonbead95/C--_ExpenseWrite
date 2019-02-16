#ifndef __ACCOUNT_EXCPETION_H_
#define __ACCOUNT_EXCPETION_H_
#include "String.h"

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

class CategoryException : public ExpenseException
{
private:
	int reqCate;	// ��û �з�
public:
	CategoryException(int myCategory);
	void ShowExceptionReason();
};

class DateException : public ExpenseException
{
private:
	String str;
public:
	DateException(String s);
	void ShowExceptionReason();
};
#endif // !__ACCOUNT_EXCPETION_H_
