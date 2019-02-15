#ifndef __EXPENSE_H_
#define __EXPENSE_H_

#include <iostream>
#include <string>
#include "String.h"
#include "ExpenseCommon.h"

using std::cout;
using std::endl;
using std::cin;

class expense
{
private:
	String Date;	// ��¥
	int money;		// �ݾ�
	String Using;	// �뵵
	int category;	// �з�
public:
	expense();
	expense(String myDate, int myMoney, String myUsing, int myCategory);
	String GetDate() const;
	int GetMoney() const;
	String GetUsing() const;
	int GetCategory() const;
	void SetDate(String myDate);
	void SetMoney(int myMoney);
	void SetUsing(String myUsing);
	void Setcategory(int myCategory);
	void ShowExpenseInfo() const;
};

#endif // !__EXPENSE_H_

