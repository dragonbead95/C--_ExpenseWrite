#ifndef __EXPENSE_INFO_H_
#define __EXPENSE_INFO_H_

#include "library.h"

class expense_info
{
private:
	string myDate;	// ��¥
	int mymoney;	// �ݾ�
	string myUsing;	// �뵵
	string myCategory;	// �з�
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

