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
	int reqDep;	// 기록 금액
public:
	MinusException(int money);
	void ShowExceptionReason();
};
/*
class CategoryException : public ExpenseException
{
private:
	string reqCate;	// 요청 분류
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
