#ifndef __CONTROL_H_
#define __CONTROL_H_

#include "library.h"
#include "stream.h"
#include "DLinkedList.h"

class control
{
private:
//	BoundCheckArray<expense*> arr;
	int num;
public:
	control();
	void write(stream * io);
	void ShowAllExpense(stream * io);
	void ShowMoneySum(stream * io);
	void ShowMenu() const;
	void ShowSearchMenu() const;
	void ShowDateSearch();
	void ShowDateSearch(string year);	// ������ �˻�
	void ShowDateSearch(string year, string month);	// ���� �˻�
	void ShowDateSearch(string year, string month, string day);	// ���� �˻�
	void ShowMoneySearch();	// �ݾ׺� �˻�
	void ShowCategorySearch();	// �з��� �˻�
	void listInsert(List * list);	//txt������ ����Ʈ�� ����
	void sort();	// ���� ���
	
};
#endif // !__CONTROL_H_

