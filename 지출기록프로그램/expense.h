#ifndef __EXPENSE_H_
#define __EXPENSE_H_

#include "library.h"
#include "ExpenseCommon.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;

class expense
{
private:
	string Date;	// 날짜
	int money;		// 금액
	string Using;	// 용도
	int category;	// 분류
public:
	expense();
	expense(string myDate, int myMoney, string myUsing, int myCategory);
	string GetDate() const;
	int GetMoney() const;
	string GetUsing() const;
	int GetCategory() const;
	void SetDate(string myDate);
	void SetMoney(int myMoney);
	void SetUsing(string myUsing);
	void Setcategory(int myCategory);
	void ShowExpenseInfo() const;

};

#endif // !__EXPENSE_H_

