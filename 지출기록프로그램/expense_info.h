#ifndef __EXPENSE_INFO_H_
#define __EXPENSE_INFO_H_

#include "library.h"

class expense_info
{
private:
	string myDate;	// ��¥
	int mymoney;	// �ݾ�
	string myUsing;	// �뵵
	int myCategory;	// �з�
public:
	void expense_input();
	string getDate() const;
	int getMoney() const;

	string getUsing() const;
	int getCategory() const;
};


#endif // !__EXPENSE_INFO_H_

