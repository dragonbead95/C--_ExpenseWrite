#ifndef __CONTROL_H_
#define __CONTROL_H_

#include "expense.h"
#include "BoundCheckArray.h"

class control
{
private:
	BoundCheckArray<expense*> arr;
	int num;
public:
	control();
	void write();
	void ShowAllExpense() const;
	void ShowMenu() const;
};
#endif // !__CONTROL_H_

