#ifndef __EXPENSE_INFO_H_
#define __EXPENSE_INFO_H_

#include "library.h"

class expense_info
{
private:
	string myDate;	// 날짜
	int mymoney;	// 금액
	string myUsing;	// 용도
	string myCategory;	// 분류
public:
	expense_info();
	expense_info(string d, int m, string u, string c);
	void ShowExpenseInfo() const;
	void expense_input();
	string getDate() const;
	int getMoney() const;
	string getUsing() const;
	string getCategory() const;
};


#endif // !__EXPENSE_INFO_H_

