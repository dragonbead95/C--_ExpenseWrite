#ifndef __CONTROL_H_
#define __CONTROL_H_

#include "expense.h"
#include "BoundCheckArray.h"
#include <fstream>
#include <vector>
#include <sstream>
using std::ofstream;
using std::ifstream;
using std::vector;
using std::stringstream;
using std::ios;
class control
{
private:
	BoundCheckArray<expense*> arr;
	int num;
public:
	control();
	void write();
	void ShowAllExpense();
	void ShowMenu() const;
	void ShowSearchMenu() const;
	void ShowDateSearch();
	void ShowDateSearch(string year);	// ������ �˻�
	void ShowDateSearch(string year, string month);	// ���� �˻�
	void ShowDateSearch(string year, string month, string day);	// ���� �˻�
	void ShowMoneySearch();	// �ݾ׺� �˻�
	void ShowCategorySearch();	// �з��� �˻�
	void ShowMoneySum();
	void sort();
};
#endif // !__CONTROL_H_

