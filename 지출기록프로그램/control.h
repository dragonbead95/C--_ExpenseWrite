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
	void ShowDateSearch(string year);	// 연도별 검색
	void ShowDateSearch(string year, string month);	// 월별 검색
	void ShowDateSearch(string year, string month, string day);	// 월별 검색
	void ShowMoneySearch();	// 금액별 검색
	void ShowCategorySearch();	// 분류별 검색
	void listInsert(List * list);	//txt파일을 리스트에 삽입
	void sort();	// 정렬 기능
	
};
#endif // !__CONTROL_H_

